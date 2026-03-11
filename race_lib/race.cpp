#include "race.h"

namespace race_simulator {

    Race::Race(int type, double dist) {
        setTypeRace(type);
        setDistance(dist);
        clearData();
    }

    void Race::clearData() {
        listTransports.clear();
    }

    bool Race::canStart() const {
        if (listTransports.size() >= 2) { return true; }
        else return false;
    }

    std::multimap<double, std::string> Race::calcAllTime() const {
        std::multimap <double, std::string> results{};
        for (int i = 0; i < listTransports.size(); ++i) {
            double time = listTransports[i]->calcTime(distance);
            std::string name = listTransports[i]->getName();
            results.insert({ time,name });
        }
        return results;
    }

    TypeReg Race::addPlayer(Transport* currTran) {
        for (int i = 0; i < listTransports.size(); ++i) {
            if (listTransports[i]->getName() == currTran->getName()) {
                return TypeReg::ALREADY_ADDED;
            }
        }
        if (typeRace == 3 || typeRace == currTran->getTypeTr()) {
            listTransports.push_back(currTran); return TypeReg::AFTER_ADDED;
        }
        else return TypeReg::INCONGRUITY_TYPE;
    }

    const std::vector<Transport*>& Race::getListPlayers() const { return listTransports; }

    int Race::getTypeRace() const { return typeRace; }

    void Race::setDistance(double distance) { this->distance = distance; }

    void Race::setTypeRace(int typeRace) { this->typeRace = typeRace; }

    Race::~Race() {}

}