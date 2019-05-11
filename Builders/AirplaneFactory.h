#pragma once

#include "../Units/Unit.h"
#include "../Factories/AbstractFactory.h"

class AirplaneFactory: public AbstractFactory {
public:
    Unit* CreateUnit(int type, int number) override;//одинаковые типы для самолётов и кораблей,
    ~AirplaneFactory() = default;
};
