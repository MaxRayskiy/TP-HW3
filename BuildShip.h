#pragma once

#include "Builder.h"

class BuildShip: public Builder {
public:
    void SetCrew(Unit *ship, int crew) override;
    void SetLoad(Unit *ship, int first_class, int second_class, int third_class) override;
    int SetFuel(Unit *ship, int fuel) override;
    int SetPayload(Unit *ship, int cargo) override;
    void Upgrade(Unit *ship, int upgrade_class) override;
};