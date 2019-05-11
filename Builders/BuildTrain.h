#pragma once

#include "Builder.h"

class BuildTrain: public Builder {
public:
    void SetCrew(Unit *train, int crew) override;
    void SetLoad(Unit *train, int first_class, int second_class, int third_class) override;
    int SetFuel(Unit *train, int fuel) override;
    int SetPayload(Unit *train, int cargo) override;
    void Upgrade(Unit *train, int upgrade_class) override;
};