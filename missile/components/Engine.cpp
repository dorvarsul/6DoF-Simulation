#include "Engine.h"
#include <iostream>

Engine::Engine(
    double thrust,
    double burnTime,
    double specificImpulse
) : thrust(thrust), burnTime(burnTime), specificImpulse(specificImpulse), thrustVector(Eigen::Vector3d::Zero()), isRunning(false) {}

void Engine::ignite() {
    if (burnTime > 0) {
        isRunning = true;
        std::cout << "Engine ignited!" << std::endl;
    } else {
        std::cout << "No burn time left, Engine cannot ignite!" << std::endl;
    }
}

void Engine::shutdown() {
    isRunning = false;
    thrustVector = Eigen::Vector3d::Zero();
    std::cout << "Engine shutdown!" << std::endl;
}

void Engine::update(double dt, const Eigen::Quaterniond& missileOrientation, FuelTank* fuelTank) {
    if (!isRunning) {
        thrustVector = Eigen::Vector3d::Zero();
        return;
    }

    if (burnTime > 0 && fuelTank->hasFuel()) {
        burnTime -= dt;

        double fuelConsumed = computeFuelConsumption(dt);
        fuelTank->burnFuel(fuelConsumed);

        // Compute thrust direction in world space
        Eigen::Vector3d localThrust(0, 0, -thrust); // Local negative Z-axis
        thrustVector = missileOrientation * localThrust; // Rotate thrust into world space
    } else{
        shutdown();
    }
}

Eigen::Vector3d Engine::getThrustVector() { return thrustVector; }

double Engine::computeFuelConsumption(double dt) {
    return (thrust / (specificImpulse * G_FORCE)) * dt;
}

bool Engine::isEngineRunning() {
    return isRunning;
}