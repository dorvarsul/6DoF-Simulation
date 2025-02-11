#include "FuelTank.h"

// Constructor
FuelTank::FuelTank(double capacity) : capacity(capacity), remainingFuel(capacity), isEmpty(false) {}

bool FuelTank::hasFuel() { return remainingFuel > 0; }

void FuelTank::burnFuel(double amount) {
    remainingFuel = (amount <= remainingFuel)? remainingFuel - amount:0;
} 