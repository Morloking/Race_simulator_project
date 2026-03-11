#pragma once
#include "air_transport.h"
#include "export.h"

namespace race_simulator {

    class FlyCarpet : public AirTransport
    {
    public:
        RACE_API FlyCarpet();
        RACE_API double calcCoef(double distance) override;
    };

}