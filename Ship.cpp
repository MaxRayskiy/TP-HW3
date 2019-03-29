#include "Ship.h"

Ship::Ship(int r_type, int r_number)
        : type(r_type)
        , number(r_number)
        , location(0)
        , state(100)
        , crew(0)
        , payload(0)
        , seat_limit(0)
        , first_class(0)  // 8
        , second_class(0)
        , third_class(0)
        , speed(0)
        , fuel_capacity(0)  // 12
        , fuel_level(0)  // 13
        , range(0)
        , max_payload(0)  // 15
{}

std::vector<int> Ship::GetInfo() {
    std::vector<int> info = {type, number, location, state, crew, payload, seat_limit, first_class, second_class,
                             third_class, speed, fuel_capacity, fuel_level, range, max_payload};
    return info;
}

void Ship::Move(int destination) {
    location = destination;
}

void Ship::Refuel(int fuel) {
    fuel_level = fuel;
}

void Ship::Repair(int hp) {
    state = hp;
}

void Ship::Load(int pax1, int pax2, int pax3) {
    first_class = pax1;
    second_class = pax2;
    third_class = pax3;
}

void Ship::Payload(int weight) {
    payload = weight;
}

void Ship::Upgrade(int parameter, int state) {
    if (parameter == 14)
        range = state;
}

