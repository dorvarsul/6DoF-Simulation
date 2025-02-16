#include "missile.h"

Missile::Missile(MissileInput parameters)
: position(parameters.getPosition()),
velocity(Eigen::Vector3d::Zero()),
acceleration(Eigen::Vector3d::Zero()),
angularVelocity(Eigen::Vector3d::Zero()),
orientation(parameters.getOrientation()),
mass(parameters.getMass() + parameters.getFuelCapacity()),
engine(parameters.getThrust(), parameters.getBurnTime(), parameters.getSpecificImpulse()),
fuelTank(parameters.getFuelCapacity()) {}

void Missile::launch() {
    engine.ignite();
    std::cout << "Missile launched!" << std::endl;
    std::cout << "X:" << position.x() << " Y:" << position.y() << " Z:" << position.z() << std::endl;
}

void Missile::update(double dt) {
    if(engine.isEngineRunning()) {
        engine.update(dt, orientation, &fuelTank);
        
        if(fuelTank.hasFuel()) {
            mass -= engine.computeFuelConsumption(dt);
        }

        Eigen::Vector3d weight(0,0, -mass * G_FORCE);
        acceleration = (engine.getThrustVector() + weight) / mass;

        velocity += acceleration * dt;
        position += velocity * dt;

        if (angularVelocity.norm() > 1e-6) {
            Eigen::Quaterniond deltaRotation(
                Eigen::AngleAxisd(angularVelocity.norm() * dt, angularVelocity.normalized())
            );
            orientation *= deltaRotation;   
            orientation.normalize();
        }
    }
    std::cout << "X:" << position.x() << " Y:" << position.y() << " Z:" << position.z() << std::endl;
}

double Missile::getZ() { return position.z(); }