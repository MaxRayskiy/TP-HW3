#include "Airplane.h"

Airplane::Airplane(int r_type, int r_number)
    : type(r_type)
    , number(r_number)
    , location(0)
    , state(100)
    , crew(2)
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
{
    switch (type) {
        case 1: {  // cargo
            seat_limit = 0;
            speed = 860;
            fuel_capacity = 181120;
            range = 10190;
            max_payload = 103700
            break;
        }
        case 2: { // in 3 class config
            seat_limit = 400;
            speed = 860;
            fuel_capacity = 145810;
            range = 10190;
            max_payload = 103700
            break;
        }
        case 3: { // in 2 class config
            seat_limit = 420;
            speed = 860;
            fuel_capacity = 171160;
            range = 10190;
            max_payload = 101200;
            break;
        }
        case 4: { // in 1 class config
            seat_limit = 480;
            speed = 860;
            fuel_capacity = 171160;
            range = 10190;
            max_payload = 101200;
            break;
        }
    }

}

std::vector<int> Airplane::GetInfo() {
    std::vector<int> info = {type, number, location, state, crew, payload, seat_limit, first_class, second_class,
                        third_class, speed, fuel_capacity, fuel_level, range, max_payload};
    return info;
}

void Airplane::Move(int destination) {
    location = destination;
}

void Airplane::Refuel(int fuel) {
    fuel_level = fuel;
}

void Airplane::Repair(int hp) {
    state = hp;
}

void Airplane::Load(int pax1, int pax2, int pax3) {
    first_class = pax1;
    second_class = pax2;
    third_class = pax3;
}

void Airplane::Payload(int weight) {
    payload = weight;
}

void Airplane::Upgrade(int parameter, int state) {
    if (parameter == 14)
        range = state;
}

