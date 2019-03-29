#include "AirplaneFactory.h"
#include "Unit.h"
#include "Airplane.h"

Unit *AirplaneFactory::CreateUnit(int type, int number) {
    Unit *new_unit = new Airplane(type, number);
    return new_unit;
}

