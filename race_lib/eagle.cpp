#include "eagle.h"

namespace race_simulator {

	Eagle::Eagle() : AirTransport("Орёл", 8.0) {}

	double Eagle::calcCoef(double distance) { return 0.06; }

}