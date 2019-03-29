#include "BuildAirplane.h"
#include <algorithm>

void BuildAirplane::SetCrew(Unit *airplane, int crew) {
    std::vector<int> airplane_state = airplane->GetInfo();
    if (airplane_state[0] < 50) {
        return;
    }
}

void BuildAirplane::SetLoad(Unit *airplane, int first_class, int second_class, int third_class) {
    std::vector<int> airplane_state = airplane->GetInfo();
    switch (airplane_state[0]) {
        case 1: {  // cargo
            first_class = 0;
            second_class = 0;
            third_class = 0;
            break;
        }
        case 2: { // in 3 class config
            first_class = std::min(first_class, 10);
            second_class = std::min(second_class, 20);
            third_class = std::min(third_class, 270);
            break;
        }
        case 3: { // in 2 class config
            first_class = 0;
            second_class = std::min(second_class, 15);
            third_class = std::min(third_class, 300);
            break;
        }
        case 4: { // in 1 class config
            first_class = 0;
            second_class = 0;
            third_class = std::min(third_class, 340);
            break;
        }
    }
    airplane->Load(first_class, second_class, third_class);
}

int BuildAirplane::SetFuel(Unit *airplane, int fuel) {
    std::vector<int> airplane_state = airplane->GetInfo();
    int current_fuel = airplane_state[13];
    int max_fuel_level  =airplane_state[12];
    if (fuel <= max_fuel_level) {
        airplane->Refuel(fuel);
        return (fuel - current_fuel);
    } else {
        return -1;
    }
}

int BuildAirplane::SetPayload(Unit *airplane, int cargo) {
    std::vector<int> airplane_state = airplane->GetInfo();
    if (cargo <= airplane_state[15]) {
        airplane->Payload(cargo);
        return cargo;
    } else {
        airplane->Payload(airplane_state[15]);
        return airplane_state[15];
    }
}

void BuildAirplane::Upgrade(Unit *airplane, int upgrade_class) {
    //
}

