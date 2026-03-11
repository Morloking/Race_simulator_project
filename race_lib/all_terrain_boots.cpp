#include "all_terrain_boots.h"

namespace race_simulator {

    AllTerrainBoots::AllTerrainBoots() : GroundTransport("Ботинки-вездеходы", 6.0) {}

    double AllTerrainBoots::calcDurationOfRest(double distance) {
        double allTime = distance / getSpeed();
        int count = static_cast<int>((allTime - 1e-9) / 60);
        if (count == 0) return 0.0;
        else if (count == 1) return 10.0;
        else return 10.0 + (count - 1) * 5.0;
    }

}