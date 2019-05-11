#pragma once

#include "../Units/Unit.h"
#include "AbstractFactory.h"

class TrainFactory: public AbstractFactory {
public:
    Unit* CreateUnit(int type, int number) override;
    ~TrainFactory() = default;
};
