#pragma once

#include "Unit.h"
#include "Abstractfactory.h"

class AirplaneFactory: public AbstractFactory {
public:
    Unit* CreateUnit(int type, int number) override;//одинаковые типы для самолётов и кораблей,
    ~AirplaneFactory() = default;
};
