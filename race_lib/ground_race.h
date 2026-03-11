#pragma once
#include "race.h"
#include "export.h"

namespace race_simulator {

    class GroundRace : public Race
    {
    public:
        RACE_API explicit GroundRace(double distance);
    };

}