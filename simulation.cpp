#include "simulation.h"
#include <iostream>

double Simulation::toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

Eigen::Quaterniond Simulation::getOrientation(double pitchDeg, double yawDeg) {
    double pitch = toRadians(pitchDeg);
    double yaw = toRadians(yawDeg);

    Eigen::Quaterniond qYaw(Eigen::AngleAxisd(yaw, Eigen::Vector3d(0, 0, 1))); // Yaw around Z
    Eigen::Quaterniond qPitch(Eigen::AngleAxisd(pitch, Eigen::Vector3d(0, 1, 0))); // Pitch around Y

    return qYaw * qPitch;  // Apply yaw first, then pitch
}

void Simulation::runSimulation() {
    int x, y, z;
    int pitch, yaw;
    double mass, fuel, burnRate, thrust;
    double timeStep, duration;

    std::cout << "Welcome to the debug screen of the simulation!" << std::endl;

    std::cout << "Choose time step of simulation:";
    std::cin >> timeStep;

    std::cout << "Choose duration of simulation(no of steps):";
    std::cin >> duration;

    std::cout << "Enter initial position (x y z): ";
    std::cin >> x >> y >> z;

    std::cout << "Enter pitch angle (degrees): ";
    std::cin >> pitch;

    std::cout << "Enter yaw angle (degrees): ";
    std::cin >> yaw;

    std::cout << "Enter mass (kg): ";
    std::cin >> mass;

    std::cout << "Enter fuel (kg): ";
    std::cin >> fuel;

    std::cout << "Enter burn rate (kg/s):";
    std::cin >> burnRate;

    std::cout << "Enter thrust (N): ";
    std::cin >> thrust;


    Eigen::Vector3d initialPos(x, y, z);
    Eigen::Quaterniond launchDirection = getOrientation(pitch, yaw);

    // Initialize the correct missile type
    Missile* missile = nullptr;

    missile = new UnguidedMissile(initialPos, launchDirection, mass, fuel, burnRate, thrust);

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
    Simulation::runSimulation();
    return 0;
}
