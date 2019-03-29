#pragma once

#include <vector>

class Unit {
public:
    virtual std::vector<int> GetInfo() = 0;
    virtual void Move(int destination) = 0;
    virtual void Refuel(int fuel) = 0;
    virtual void Repair(int hp) = 0;
    virtual void Load(int pax1, int pax2, int pax3) = 0;
    virtual void Payload(int weight) = 0;
    virtual void Upgrade(int parameter, int state) = 0;

    ~Unit() = default;
};