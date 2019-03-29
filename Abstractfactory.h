#pragma once

#include "Unit.h"

class AbstractFactory{
        public:
        virtual Unit* CreateUnit(int type, int number) = 0;
        virtual ~AbstractFactory() = default;
};
