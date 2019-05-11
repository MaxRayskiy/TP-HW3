#if defined HOME
#include "game.h"
#endif
#include "Units/Airplane.cpp"
#include "Units/Ship.cpp"
#include "Units/Train.cpp"
#include "Builders/AirplaneFactory.cpp"
#include "Builders/ShipFactory.cpp"
#include "Builders/TrainFactory.cpp"
#include "Builders/BuildAirplane.cpp"
#include "Builders/BuildShip.cpp"
#include "Builders/BuildTrain.cpp"

#if not defined HOME
int main() {}
#endif