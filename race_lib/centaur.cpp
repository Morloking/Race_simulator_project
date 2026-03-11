#include "centaur.h"

namespace race_simulator {

    Centaur::Centaur() : GroundTransport("Кентавр", 15.0) {}

    double Centaur::calcDurationOfRest(double distance) {
        double allTime = distance / getSpeed();
        int count = static_cast<int>((allTime - 1e-9) / 8);
        if (count == 0) return 0.0;
        else return count * 2.0;
    }

}