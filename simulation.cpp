#include "simulation.h"

void Simulation::runSimulation(double duration, double timeStep) {
    int x,y,z;
    int velX, velY, velZ;
    double mass, fuel, thrust;

    std::cout << "Welcome to the debug screen of the simulation!" << std::endl;
    std::cout << "Enter initial pos (x y z):" << std::endl;
    std::cin >> x >> y >> z;

    std::cout << "Enter initial velocity (x y z):" << std::endl;
    std::cin >> velX >> velY >> velZ;

    std::cout << "Enter mass (kg):" << std::endl;
    std::cin >> mass;

    std::cout << "Enter fuel (kg):" << std::endl;
    std::cin >> fuel;

    std::cout << "Enter thrust (N):" << std::endl;
    std::cin >> thrust;

    // Initialize vectors
    Eigen::Vector3d initialPos(x,y,z);
    Eigen::Vector3d initialVel(velX, velY, velZ);

    // Initialize object
    Missile missile(initialPos, initialVel, mass, fuel, thrust);



    double elapsedTime = 0.0;

    std::ofstream file("trajectory.csv");
    file << "x,y,z" << std::endl;

    std::cout << "Position: " << missile.getX() << "," << missile.getY() << "," << missile.getZ() << std::endl;
    while (elapsedTime < duration && missile.inAir()) {
        missile.update(timeStep);
        file << missile.getX() << "," << missile.getY() << "," << missile.getZ() << std::endl;
        elapsedTime += timeStep;
    }

    file.close();
}

int main() {
    Simulation::runSimulation(50, 0.05);
    return 0;
}