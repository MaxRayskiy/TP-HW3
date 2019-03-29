#include "ShipFactory.h"
#include "Unit.h"
#include "Ship.h"

Unit *ShipFactory::CreateUnit(int type, int number) {
    Unit *new_unit = new Ship(type, number);
    return new_unit;
}

