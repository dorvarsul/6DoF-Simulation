#ifndef MISSILE_INPUT_H
#define MISSILE_INPUT_H

#include <eigen3/Eigen/Dense>
#include <cmath>

#define DEG2RAD(deg) ((deg) * M_PI / 180.0)

class MissileInput {
private:
    Eigen::Vector3d position;
    double angleXZ;
    double angleXY;
    double mass;
    double thrust;
    double burnTime;
    double specificImpulse;
    double fuelCapacity;

public:
    MissileInput(
        Eigen::Vector3d pos,
        double angleXZ,
        double angleXY,
        double mass,
        double thrust,
        double burnTime,
        double specificImpulse,
        double fuelCapacity
    );

    // Getters
    Eigen::Vector3d getPosition();
    Eigen::Quaterniond getOrientation();
    double getMass();
    double getThrust();
    double getBurnTime();
    double getSpecificImpulse();
    double getFuelCapacity();
};

#endif