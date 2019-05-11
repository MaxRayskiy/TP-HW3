#include "AirplaneFactory.h"
#include "../Units/Unit.h"
#include "../Units/Airplane.h"

Unit *AirplaneFactory::CreateUnit(int type, int number) {
    Unit *new_unit = new Airplane(type, number);
    return new_unit;
}

