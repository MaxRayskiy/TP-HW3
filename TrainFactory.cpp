#include "TrainFactory.h"
#include "Unit.h"
#include "Train.h"

Unit *TrainFactory::CreateUnit(int type, int number) {
    Unit *new_unit = new Train(type, number);
    return new_unit;
}

