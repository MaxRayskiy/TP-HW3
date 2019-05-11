#pragma once

#include "Unit.h"
#include <vector>

class Train: public Unit{
protected:
    int type, number;
    int location, state;
    int crew, payload, seat_limit, first_class, second_class, third_class, speed, fuel_capacity, fuel_level, range, max_payload;

public:
    Train(int type,int number);
    std::vector<int> GetInfo();
    void Move(int destination);
    void Refuel(int fuel);
    void Repair(int hp);
    void Load(int pax1, int pax2, int pax3);
    void Payload(int weight);
    void Upgrade(int parameter, int state);

    ~Train() = default;
};