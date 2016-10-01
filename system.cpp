#include <system.h>
#include <iostream>
#include <Integrators/integrator.h>
#include <Potentials/potential.h>
#include <InitialConditions/initialcondition.h>
#include <particle.h>

using std::cout;
using std::endl;



void System::computeForces() {
    resetAllForces();
    m_potential->resetPotentialEnergy();

    for (int i=0; i<m_numberOfParticles; i++) {
        for (int j=i+1; j<m_numberOfParticles; j++) {
            m_potential->computeForces(m_particles.at(i), m_particles.at(j));
        }
    }
}

void System::resetAllForces() {
    for (int i=0; i<m_numberOfParticles; i++) {
        m_particles.at(i)->resetForces();
    }
}

void System::setPotential(Potential* potential) {
    m_potential = potential;
}

void System::setIntegrator(Integrator* integrator) {
    m_integrator = integrator;
}

void System::setInitialCondition(InitialCondition* initialCondition) {
    m_initialCondition = initialCondition;
    m_initialCondition->setupParticles();
    m_particles = m_initialCondition->getParticles();
    m_numberOfParticles = m_particles.size();
}

void System::setDt(double dt) {
    m_integrator->setDt(dt);
}

void System::integrate(int numberOfSteps) {
    m_integrateSteps = numberOfSteps;
    printIntegrateInfo(0);
    for (int i=1; i<numberOfSteps+1; i++) {
        m_integrator->integrateOneStep(m_particles);
        printIntegrateInfo(i);
        writePositionsToFile();
    }
}

void System::addParticle(Particle* p) {
    m_particles.push_back(p);
    m_numberOfParticles += 1;
}

double System::computeKineticEnergy() {
    m_kineticEnergy = 0;
    for (int i=0; i<m_numberOfParticles; i++) {
        double velocitySquared = m_particles.at(i)->velocitySquared();
        double mass = m_particles.at(i)->getMass();
        m_kineticEnergy += 0.5*mass*velocitySquared;
    }
    return m_kineticEnergy;
}

void System::printIntegrateInfo(int stepNumber) {
    if (stepNumber==0) {
        cout                                << endl
             << " STARTING INTEGRATION "    << endl
             << "-------------------------" << endl
             << "  o Number of steps:     " << m_integrateSteps << endl
             << "  o Time step, dt:       " << m_integrator->getDt() << endl
             << "  o Initial condition:   " << m_initialCondition->getName() << endl
             << "  o Number of particles: " << m_particles.size() << endl
             << "  o Potential in use:    " << m_potential->getName() << endl
             << "  o Integrator in use:   " << m_integrator->getName() << endl
             << endl;
    } else if (stepNumber % 1000 == 0) {
        m_kineticEnergy     = computeKineticEnergy();
        m_potentialEnergy   = m_potential->getPotentialEnergy();
        m_totalEnergy       = m_kineticEnergy + m_potentialEnergy;
        printf("Step: %5d    E =%10.5f   Ek =%10.5f    Ep =%10.5f\n",
               stepNumber, m_totalEnergy, m_kineticEnergy, m_potentialEnergy);
        fflush(stdout);
    }
}

void System::removeLinearMomentum() {
    vec3 totalMomentum = vec3(0,0,0);
    for (int i=0; i<m_numberOfParticles; i++) {
        Particle* p = m_particles.at(i);
        totalMomentum += p->getVelocity() * p->getMass();
    }
    vec3 momentumToBeRemovedFromEachParticle = vec3(totalMomentum[0],
                                                    totalMomentum[1],
                                                    totalMomentum[2]);
    momentumToBeRemovedFromEachParticle /= m_numberOfParticles;
    for (int i=0; i<m_numberOfParticles; i++) {
        Particle* p = m_particles.at(i);
        p->getVelocity() -= momentumToBeRemovedFromEachParticle /
                            p->getMass();
    }
}

void System::setFileWriting(bool writeToFile) {
    m_writeToFile = writeToFile;
}

void System::writePositionsToFile() {
    if (m_outFileOpen == false) {
        m_outFile.open("positions.dat", std::ios::out);
        m_outFileOpen = true;
    }
    for (int i=0; i<m_numberOfParticles; i++) {
        Particle* p = m_particles.at(i);
        m_outFile << p->getPosition()[0] << " "
                  << p->getPosition()[1] << " "
                  << p->getPosition()[2] << " ";
    }
    m_outFile << endl;
}






