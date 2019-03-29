cmake_minimum_required(VERSION 3.13)
project(HW3)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW3 main.cpp BuildAirplane.cpp Airplane.cpp Ship.cpp ShipFactory.cpp Train.cpp TrainFactory.cpp AirplaneFactory.cpp BuildTrain.cpp BuildShip.cpp)