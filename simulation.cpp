#include "simulation.h"
#include <iostream>

void Simulation::runSimulation(double duration, double timeStep) {
    int x, y, z;
    int velocityMagnitude, pitch, yaw;
    double mass, fuel, thrust;
    int missileType;

    std::cout << "Welcome to the debug screen of the simulation!" << std::endl;
    std::cout << "Enter initial position (x y z): ";
    std::cin >> x >> y >> z;

    std::cout << "Enter initial velocity magnitude (m/s): ";
    std::cin >> velocityMagnitude;

    std::cout << "Enter pitch angle (degrees): ";
    std::cin >> pitch;

    std::cout << "Enter yaw angle (degrees): ";
    std::cin >> yaw;

    std::cout << "Enter mass (kg): ";
    std::cin >> mass;

    std::cout << "Enter fuel (kg): ";
    std::cin >> fuel;

    std::cout << "Enter thrust (N): ";
    std::cin >> thrust;

    std::cout << "Select missile type (1 = Ballistic, 2 = Guided): ";
    std::cin >> missileType;

    // Convert angles from degrees to radians
    double pitchRad = pitch * M_PI / 180.0;
    double yawRad = yaw * M_PI / 180.0;

    // Calculate velocity components
    double velX = velocityMagnitude * cos(pitchRad) * cos(yawRad);
    double velY = velocityMagnitude * cos(pitchRad) * sin(yawRad);
    double velZ = velocityMagnitude * sin(pitchRad);

    Eigen::Vector3d initialPos(x, y, z);
    Eigen::Vector3d initialVel(velX, velY, velZ);

    // Initialize the correct missile type
    Missile* missile = nullptr;

    if (missileType == 1) {
        missile = new BallisticMissile(initialPos, initialVel, mass, fuel, thrust);
    } else if (missileType == 2) {
        double targetX, targetY, targetZ;
        std::cout << "Enter target position (x y z): ";
        std::cin >> targetX >> targetY >> targetZ;
        Eigen::Vector3d targetPos(targetX, targetY, targetZ);

        missile = new GuidedMissile(initialPos, initialVel, mass, fuel, thrust, targetPos);
    } else {
        std::cerr << "Invalid missile type selected! Exiting..." << std::endl;
        return;
    }

    double elapsedTime = 0.0;
    std::ofstream file("trajectory.csv");
    file << "x,y,z" << std::endl;

    // Run simulation
    while (elapsedTime < duration && missile->inAir()) {
        missile->update(timeStep);
        file << missile->getX() << "," << missile->getY() << "," << missile->getZ() << std::endl;
        elapsedTime += timeStep;
    }

    std::cout << "Simulation finished successfully!" << std::endl;
    file.close();

    // Cleanup
    delete missile;
}

int main() {
    Simulation::runSimulation(50, 0.05);
    return 0;
}
