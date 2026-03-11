#pragma once
#include "race.h"
#include "export.h"

namespace race_simulator {

    class MixedRace : public Race
    {
    public:
        RACE_API explicit MixedRace(double distance);
    };

}