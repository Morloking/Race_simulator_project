#pragma once
#include "ground_transport.h"
#include "export.h"

namespace race_simulator {

    class AllTerrainBoots : public GroundTransport
    {
    public:
        RACE_API AllTerrainBoots();
        RACE_API double calcDurationOfRest(double distance) override;
    };

}