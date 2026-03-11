#pragma once
#include "race.h"
#include "export.h"

namespace race_simulator {

    class AirRace : public Race
    {
    public:
        RACE_API explicit AirRace(double distance);
    };

}