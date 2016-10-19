#ifndef SYSTEM_H
#define SYSTEM_H


class System
{
private:
    int n_particles;
public:
    System();
    void readFile();
    double calculateAcceleration();
};

#endif // SYSTEM_H
