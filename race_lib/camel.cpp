#include "camel.h"

namespace race_simulator {

    Camel::Camel() : GroundTransport("Верблюд", 10.0) {}

    double Camel::calcDurationOfRest(double distance) {
        double allTime = distance / getSpeed();
        int count = static_cast<int>((allTime - 1e-9) / 30);
        if (count == 0) return 0.0;
        else if (count == 1) return 5.0;
        else return 5.0 + (count - 1) * 8.0;
    }

}