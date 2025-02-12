#include "inputObject.h"

// Constructor
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

// Convert XY and XZ angles to quaternion
Eigen::Quaterniond Input::getOrientation() {
    double theta = DEG2RAD(angleXZ);
    double phi = DEG2RAD(angleXY);

    // Convert XY and XZ angles to a direction vector
    Eigen::Vector3d direction(
        std::cos(theta) * std::cos(phi),
        std::sin(theta),
        std::sin(phi) * std::cos(phi)
        );

    Eigen::Vector3d reference(1,0,0); // Reference axis is X since the degrees are in the XY & XZ planes

    // Create quaternion from 2 vectors.
    return Eigen::Quaterniond::FromTwoVectors(reference, direction);
}

Eigen::Vector3d Input::getPosition() { return position; } // Return position
double Input::getMass() { return mass; } // Returns mass
double Input::getThrust() { return thrust; } // Returns thrust
double Input::getBurnTime() { return burnTime; } // Returns burn time
double Input::getSpecificImpulse() { return specificImpulse; } // Returns specific impulse
double Input::getFuelCapacity() { return fuelCapacity; } // Returns fuel capacity
