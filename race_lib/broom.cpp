#include "broom.h"

namespace race_simulator {

    Broom::Broom() : AirTransport("Метла", 20.0) {}

    double Broom::calcCoef(double distance) {
        double coef{ 0.0 };
        while (distance >= 1000) {
            distance -= 1000;
            coef += 0.01;
        }
        return coef;
    }

}