#pragma once
#include "transport.h"
#include "export.h"

namespace race_simulator {

    class AirTransport : public Transport
    {
    public:
        RACE_API AirTransport(std::string nameTr, double speedTr);
        RACE_API double calcTime(double distance) override;
        RACE_API virtual double calcCoef(double distance) = 0;
        RACE_API virtual ~AirTransport() {}
    private:
        double coefficient{ 0.0 };
    };

}