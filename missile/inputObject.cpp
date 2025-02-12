#include "inputObject.h"

Input::Input(
    Eigen::Vector3d position,
    double angleXZ,
    double angleXY,
    double mass,
    double thrust,
    double burnTime,
    double specificImpulse,
    double fuelCapacity
) : position(position), angleXZ(angleXZ), angleXY(angleXY), mass(mass), thrust(thrust), burnTime(burnTime),
specificImpulse(specificImpulse), fuelCapacity(fuelCapacity) {}

Eigen::Vector3d Input::getPosition() { return position; }

Eigen::Quaterniond Input::getOrientation() {
    double theta = DEG2RAD(angleXZ);
    double phi = DEG2RAD(angleXY);

    Eigen::Vector3d direction(
        std::cos(theta) * std::cos(phi),
        std::sin(theta),
        std::sin(phi) * std::cos(phi)
        );

    Eigen::Vector3d reference(1,0,0);

    return Eigen::Quaterniond::FromTwoVectors(reference, direction);
}

double Input::getMass() { return mass; }
double Input::getThrust() { return thrust; }
double Input::getBurnTime() { return burnTime; }
double Input::getSpecificImpulse() { return specificImpulse; }
double Input::getFuelCapacity() { return fuelCapacity; }
