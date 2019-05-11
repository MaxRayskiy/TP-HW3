#pragma once

#include "../Units/Unit.h"
#include "AbstractFactory.h"

class ShipFactory: public AbstractFactory {
public:
    Unit* CreateUnit(int type, int number) override;
    ~ShipFactory() = default;
};
