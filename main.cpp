#include "missile/missile.h"
#include <iostream>

int main() {
    double x,y,z;
    double angleXZ, angleXY;
    double mass, thrust, burnTime, specificImpulse, fuelCapacity;
    std::cout << "Welcome to the test simulation!" << std::endl;
    std::cout << "Insert initial pos (x y z):";
    std::cin >> x >> y >> z;

    std::cout << "Insert AngleXZ (degrees):";
    std::cin >> angleXZ;

    std::cout << "Insert AngleXY (degrees):";
    std::cin >> angleXY;

    std::cout << "Insert mass (kg):";
    std::cin >> mass;

    std::cout << "Insert thrust (N):";
    std::cin >> thrust;

    std::cout << "Insert burn time (sec):";
    std::cin >> burnTime;

    std::cout << "Insert specific impulse:";
    std::cin >> specificImpulse;

    std::cout << "Insert Fuel capacity (kg):";
    std::cin >> fuelCapacity;

    Eigen::Vector3d initialPos(x,y,z);
    MissileInput input(initialPos, angleXZ, angleXY, mass, thrust, burnTime, specificImpulse, fuelCapacity);
    Missile missile(input);

    std::cout << "Sucessfully created a missile!" << std::endl;

    missile.launch();
    while (missile.getZ() >= 0) {
        missile.update(0.01);
    }
    return 0;
}