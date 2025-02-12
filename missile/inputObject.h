#ifndef INPUT_H
#define INPUT_H

#include <eigen3/Eigen/Dense>
#include <cmath>

#define DEG2RAD(deg) ((deg) * M_PI / 180.0)

class Input {
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
    Input(
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