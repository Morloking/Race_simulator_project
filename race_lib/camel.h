#pragma once
#include "ground_transport.h"
#include "export.h"

namespace race_simulator {

    class Camel : public GroundTransport
    {
    public:
        RACE_API Camel();
        RACE_API double calcDurationOfRest(double distance) override;
    };

}