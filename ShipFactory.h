#pragma once

#include "Unit.h"
#include "Abstractfactory.h"

class ShipFactory: public AbstractFactory {
public:
    Unit* CreateUnit(int type, int number) override;
    ~ShipFactory() = default;
};
