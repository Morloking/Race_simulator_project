#pragma once
#include "air_transport.h"
#include "export.h"

namespace race_simulator {

    class Eagle : public AirTransport
    {
    public:
        RACE_API Eagle();
        RACE_API double calcCoef(double distance) override;
    };

}