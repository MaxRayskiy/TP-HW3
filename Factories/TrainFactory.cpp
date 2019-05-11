#include "TrainFactory.h"
#include "../Units/Unit.h"
#include "../Units/Train.h"

Unit *TrainFactory::CreateUnit(int type, int number) {
    Unit *new_unit = new Train(type, number);
    return new_unit;
}

