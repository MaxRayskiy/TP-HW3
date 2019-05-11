#include "BuildShip.h"
#include <algorithm>

void BuildShip::SetCrew(Unit *ship, int crew) {
    std::vector<int> ship_state = ship->GetInfo();
    if (ship_state[0] < 50) {
        return;
    }
}

void BuildShip::SetLoad(Unit *ship, int first_class, int second_class, int third_class) {
    std::vector<int> ship_state = ship->GetInfo();
    switch (ship_state[0]) {
        case 101: {  // cargo
            first_class = 0;
            second_class = 0;
            third_class = 0;
            break;
        }
        case 102: { // in 3 class config
            first_class = std::min(first_class, 10);
            second_class = std::min(second_class, 20);
            third_class = std::min(third_class, 270);
            break;
        }
        case 103: { // in 2 class config
            first_class = 0;
            second_class = std::min(second_class, 15);
            third_class = std::min(third_class, 300);
            break;
        }
        case 104: { // in 1 class config
            first_class = 0;
            second_class = 0;
            third_class = std::min(third_class, 340);
            break;
        }
    }
    ship->Load(first_class, second_class, third_class);
}

int BuildShip::SetFuel(Unit *ship, int fuel) {
    std::vector<int> ship_state = ship->GetInfo();
    int current_fuel = ship_state[13];
    int max_fuel_level  = ship_state[12];
    if (fuel <= max_fuel_level) {
        ship->Refuel(fuel);
        return (fuel - current_fuel);
    } else {
        return -1;
    }
}

int BuildShip::SetPayload(Unit *ship, int cargo) {
    std::vector<int> ship_state = ship->GetInfo();
    if (cargo <= ship_state[15]) {
        ship->Payload(cargo);
        return cargo;
    } else {
        ship->Payload(ship_state[15]);
        return ship_state[15];
    }
}

void BuildShip::Upgrade(Unit *ship, int upgrade_class) {
    std::vector<int> ship_state = ship->GetInfo();
    //
}

