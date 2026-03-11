#pragma once

#include <string>
#include "export.h"

namespace race_simulator {

    class Transport
    {
    public:
        RACE_API Transport(int typeTr, std::string nameTr, double speedTr);
        RACE_API virtual double calcTime(double distance) = 0;
        RACE_API int getTypeTr() const;
        RACE_API std::string getName() const;
        RACE_API double getSpeed() const;
        RACE_API virtual ~Transport();
    private:
        int typeTransport{ 0 };
        std::string name{ "" };
        double speed{ 0 };
    };

}