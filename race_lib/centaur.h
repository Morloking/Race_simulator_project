#pragma once
#include "ground_transport.h"
#include "export.h"

namespace race_simulator {

    class Centaur : public GroundTransport
    {
    public:
        RACE_API Centaur();
        RACE_API double calcDurationOfRest(double distance) override;
    };

}