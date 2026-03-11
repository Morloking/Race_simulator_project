#include "fly_carpet.h"

namespace race_simulator {

    FlyCarpet::FlyCarpet() : AirTransport("Ковёр-самолёт", 10.0) {}

    double FlyCarpet::calcCoef(double distance) {
        if (distance >= 10000) return 0.05;
        else if (distance >= 5000 && distance < 10000) return 0.1;
        else if (distance >= 1000 && distance < 5000) return 0.03;
        else return 0.0;
    }

}