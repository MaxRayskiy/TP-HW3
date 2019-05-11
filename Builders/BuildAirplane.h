#pragma once

#include "Builder.h"

class BuildAirplane: public Builder {
public:
    void SetCrew(Unit* airplane, int crew) override;
    void SetLoad(Unit *airplane, int first_class, int second_class, int third_class) override;
    int SetFuel(Unit *airplane, int fuel) override;
    int SetPayload(Unit *airplane, int cargo) override;
    void Upgrade(Unit *airplane, int upgrade_class) override;
};