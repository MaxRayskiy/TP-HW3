#if defined HOME
#include "game.h"
#endif
#include "Units/Airplane.cpp"
#include "Units/Ship.cpp"
#include "Units/Train.cpp"
#include "Factories/AirplaneFactory.cpp"
#include "Factories/ShipFactory.cpp"
#include "Factories/TrainFactory.cpp"
#include "Builders/BuildAirplane.cpp"
#include "Builders/BuildShip.cpp"
#include "Builders/BuildTrain.cpp"

#if not defined HOME
int main() {}
#endif