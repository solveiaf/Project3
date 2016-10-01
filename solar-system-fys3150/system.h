#pragma once
#include <vector>
#include <particle.h>

class System {
private:
    bool                        m_writeToFile       = false;
    bool                        m_outFileOpen       = false;
    int                         m_integrateSteps    = 0;
    int                         m_numberOfParticles = 0;
    double                      m_kineticEnergy     = 0;
    double                      m_totalEnergy       = 0;
    double                      m_potentialEnergy   = 0;
    std::vector<Particle*>      m_particles;
    class Integrator*           m_integrator = nullptr;
    class Potential*            m_potential  = nullptr;

public:
    System();
    void computeForces          ();
    void resetAllForces         ();
    void setPotential           (class Potential* potential);
    void setIntegrator          (class Integrator* integrator);
    void integrate              (int numberOfSteps);
    void addParticle            (Particle* p);
    void printIntegrateInfo     (int stepNumber);
    void setFileWriting         (bool writeToFile);
    double computeKineticEnergy ();
};

