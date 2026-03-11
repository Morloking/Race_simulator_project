#include "transport.h"

namespace race_simulator {

	Transport::Transport(int typeTr, std::string nameTr, double speedTr) : typeTransport(typeTr), name(nameTr), speed(speedTr) {}

	int Transport::getTypeTr() const { return typeTransport; }

	std::string Transport::getName() const { return name; }

	double Transport::getSpeed() const { return speed; }

	Transport::~Transport() {}

}