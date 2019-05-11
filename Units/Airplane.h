#pragma once

#include "Unit.h"

#include <vector>

class Airplane: public Unit {
private:
    int type, number;
    int location, state;
    int crew, payload, seat_limit, first_class, second_class, third_class, speed, fuel_capacity, fuel_level, range, max_payload;

public:
    Airplane(int r_type,int r_number);
    std::vector<int> GetInfo() override;
    void Move(int destination) override;
    void Refuel(int fuel) override;
    void Repair(int hp) override;
    void Load(int pax1, int pax2, int pax3) override;
    void Payload(int weight) override;
    void Upgrade(int parameter, int state) override;

    ~Airplane() = default;
};