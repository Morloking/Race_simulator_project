#pragma once
#include "ground_transport.h"
#include "export.h"

namespace race_simulator {

    class FastCamel : public GroundTransport
    {
    public:
        RACE_API FastCamel();
        RACE_API double calcDurationOfRest(double distance) override;
    };

}