#ifndef FUELTANK_H
#define FUELTANK_H

class FuelTank {
private:
    double capacity; // Maximum fuel (kg)
    double remainingFuel; // Remaining fuel (kg)
    bool isEmpty; // True if out of fuel

public:
    FuelTank(double cap);
    bool hasFuel(); // Checks if there is fuel remaining
    void burnFuel(double amount); // Reduces fuel from the fuel tank
};

#endif