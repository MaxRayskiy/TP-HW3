#include "BuildTrain.h"
#include <algorithm>

void BuildTrain::SetCrew(Unit *train, int crew) {
    std::vector<int> train_state = train->GetInfo();
    if (train_state[0] < 50) {
        return;
    }
}

void BuildTrain::SetLoad(Unit *train, int first_class, int second_class, int third_class) {
    std::vector<int> train_state = train->GetInfo();
    switch (train_state[0]) {
        case 201: {  // cargo
            first_class = 0;
            second_class = 0;
            third_class = 0;
            break;
        }
        case 202: { // in 3 class config
            first_class = std::min(first_class, 10);
            second_class = std::min(second_class, 20);
            third_class = std::min(third_class, 270);
            break;
        }
        case 203: { // in 2 class config
            first_class = 0;
            second_class = std::min(second_class, 15);
            third_class = std::min(third_class, 300);
            break;
        }
        case 204: { // in 1 class config
            first_class = 0;
            second_class = 0;
            third_class = std::min(third_class, 340);
            break;
        }
    }
    train->Load(first_class, second_class, third_class);
}

int BuildTrain::SetFuel(Unit *train, int fuel) {
    std::vector<int> train_state = train->GetInfo();
    int current_fuel = train_state[13];
    int max_fuel_level  = train_state[12];
    if (fuel <= max_fuel_level) {
        train->Refuel(fuel);
        return (fuel - current_fuel);
    } else {
        return -1;
    }
}

int BuildTrain::SetPayload(Unit *train, int cargo) {
    std::vector<int> train_state = train->GetInfo();
    if (cargo <= train_state[15]) {
        train->Payload(cargo);
        return cargo;
    } else {
        train->Payload(train_state[15]);
        return train_state[15];
    }
}

void BuildTrain::Upgrade(Unit *airplane, int upgrade_class) {
    //
}

