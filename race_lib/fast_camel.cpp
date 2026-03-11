#include "fast_camel.h"

namespace race_simulator {

    FastCamel::FastCamel() : GroundTransport("Верблюд-быстроход", 40.0) {}

    double FastCamel::calcDurationOfRest(double distance) {
        double allTime = distance / getSpeed();
        int count = static_cast<int>((allTime - 1e-9) / 10);
        if (count == 0) return 0.0;
        else if (count == 1) return 5.0;
        else if (count == 2) return 5.0 + 6.5;
        else return 5.0 + 6.5 + (count - 2) * 8.0;
    }

}