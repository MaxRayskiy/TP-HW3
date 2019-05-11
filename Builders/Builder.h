#pragma once

#include "../Units/Unit.h"
class Builder {
public:
    virtual void SetCrew(Unit *vechicle, int crew) = 0;
    virtual void SetLoad(Unit *vechicle, int first_class, int second_class, int third_class) = 0;
    virtual int SetFuel(Unit *vechicle, int fuel) = 0;
    virtual int SetPayload(Unit *vechicle, int cargo) = 0;
    virtual void Upgrade(Unit *vechicle, int upgrade_class) = 0;
};