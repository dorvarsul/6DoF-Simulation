#include "missile.h"

Missile::Missile(Input parameters)
: position(parameters.getPosition()),
velocity(Eigen::Vector3d::Zero()),
acceleration(Eigen::Vector3d::Zero()),
angularVelocity(Eigen::Vector3d::Zero()),
orientation(parameters.getOrientation()),
mass(parameters.getMass()),
engine(parameters.getThrust(), parameters.getBurnTime(), parameters.getSpecificImpulse()),
fuelTank(parameters.getFuelCapacity()) {}

