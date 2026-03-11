#pragma once
#include "transport.h"
#include "export.h"

namespace race_simulator {

    class GroundTransport : public Transport
    {
    public:
        RACE_API GroundTransport(std::string nameTr, double speedTr);
        RACE_API double calcTime(double distance) override {
            return distance / getSpeed() + calcDurationOfRest(distance);
        }
        RACE_API virtual double calcDurationOfRest(double distance) = 0;
        RACE_API virtual ~GroundTransport() {}
    };

}