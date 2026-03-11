#pragma once
#include "air_transport.h"
#include "export.h"

namespace race_simulator {

    class Broom : public AirTransport
    {
    public:
        RACE_API Broom();
        RACE_API double calcCoef(double distance) override;
    };

}