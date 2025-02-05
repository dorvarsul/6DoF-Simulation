#include "simulation.h"

void Simulation::runSimulation(double duration, double timeStep) {
    int x,y,z;
    int velocityMagnitude, pitch, yaw;
    double mass, fuel, thrust;

    std::cout << "Welcome to the debug screen of the simulation!" << std::endl;
    std::cout << "Enter initial pos (x y z):" << std::endl;
    std::cin >> x >> y >> z;

    std::cout << "Enter initial velocity magnitude (m/s):" << std::endl;
    std::cin >> velocityMagnitude;

    std::cout << "Enter pitch angle (degrees):" << std::endl;
    std::cin >> pitch;

    std::cout << "Enter yaw angle (degrees):" << std::endl;
    std::cin >> yaw;

    std::cout << "Enter mass (kg):" << std::endl;
    std::cin >> mass;

    std::cout << "Enter fuel (kg):" << std::endl;
    std::cin >> fuel;

    std::cout << "Enter thrust (N):" << std::endl;
    std::cin >> thrust;

    // Initialize vectors
    Eigen::Vector3d initialPos(x,y,z);

    // Convert angles from degrees to radians
    pitch*= M_PI/180.0;
    yaw *= M_PI/180.0;

    // Calculate velocity components
    double velX = velocityMagnitude * cos(pitch) * cos(yaw);
    double velY = velocityMagnitude * cos(pitch) * sin(yaw);
    double velZ = velocityMagnitude * sin(pitch);

    Eigen::Vector3d initialVel(velX, velY, velZ);

    // Initialize object
    Missile missile(initialPos, initialVel, mass, fuel, thrust);



    double elapsedTime = 0.0;

    std::ofstream file("trajectory.csv");
    file << "x,y,z" << std::endl;

    while (elapsedTime < duration && missile.inAir()) {
        missile.update(timeStep);
        file << missile.getX() << "," << missile.getY() << "," << missile.getZ() << std::endl;
        elapsedTime += timeStep;
    }

    std::cout << "Finished successfully!" << std::endl;
    file.close();
}

int main() {
    Simulation::runSimulation(50, 0.05);
    return 0;
}