#include <iostream>
#include "missile.h"
#include <vector>

int main() {
    std::cout << "Creating new missile class" << std::endl;
    Eigen::Vector3d pos = Eigen::Vector3d(0,0,0);
    Eigen::Vector3d vel = Eigen::Vector3d(0,4,5);

    Missile m1 = Missile(pos, vel, 50.0, 50.0, 2500.0);

    std::cout << "Created new missile successfully!" << std::endl;

    while (m1.fuelRemaining > 0) {
        m1.update(0.01);
    }
}