#include "air_transport.h"

namespace race_simulator {

    AirTransport::AirTransport(std::string nameTr, double speedTr) : Transport(2, nameTr, speedTr) {}

    double AirTransport::calcTime(double distance) {
        coefficient = calcCoef(distance);
        return (distance * (1 - coefficient)) / getSpeed();
    }

}