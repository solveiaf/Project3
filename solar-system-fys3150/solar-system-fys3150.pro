TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vec3.cpp \
    system.cpp \
    particle.cpp \
    Integrators/integrator.cpp \
    Integrators/eulercromer.cpp \
    Potentials/potential.cpp \
    Potentials/newtoniangravity.cpp \
    examples.cpp

HEADERS += \
    vec3.h \
    system.h \
    particle.h \
    Integrators/integrator.h \
    Integrators/eulercromer.h \
    Potentials/potential.h \
    Potentials/newtoniangravity.h \
    examples.h
