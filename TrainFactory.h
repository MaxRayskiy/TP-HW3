#pragma once

#include "Unit.h"
#include "Abstractfactory.h"

class TrainFactory: public AbstractFactory {
public:
    Unit* CreateUnit(int type, int number) override;
    ~TrainFactory() = default;
};
