#include <iostream>
#include "Abstractfactory.h"
#include "AirplaneFactory.h"
#include "TrainFactory.h"
#include "ShipFactory.h"
#include "Airplane.h"
#include "Train.h"
#include "Ship.h"
#include "Unit.h"
#include "Builder.h"

#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    std::cout << "Select your company transport: planes(1), ships(2) or trains(3)" << std::endl;
    int des = 0;
    std::cin >> des;
    AbstractFactory *factory;
    string type_name;
    switch(des) {
        case 1: {
            factory = new AirplaneFactory;
            type_name = "airplane";
            break;
        }
        case 2: {
            factory = new ShipFactory;
            type_name = "ship";
            break;
        }
        case 3: {
            factory = new TrainFactory;
            type_name = "train";
            break;
        }
    }
    vector<Unit*> vechicles;


    std::cout << "Now you have only one vechile. Create your big company!" << std::endl;

    Unit *new_v = factory->CreateUnit(1, 0);
    vechicles.push_back(new_v);
    vector<int> info = new_v->GetInfo();
    for (const auto item: info) {
        cout << item << " ";
    }
    cout << endl;
    while (des) {
        cin >> des;
        if (des == 0)
            break;
    }
    for (const auto item: vechicles) {
        delete item;
    }
    delete factory;
    return 0;
}