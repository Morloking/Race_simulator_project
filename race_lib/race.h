#pragma once
#include <vector>
#include <string>
#include <map>

#include "export.h"
#include "enums.h"
#include "transport.h"

namespace race_simulator {

    enum class TypeReg;

    class Race
    {
    public:
        RACE_API Race(int type, double dist);
        RACE_API void clearData();
        RACE_API bool canStart() const;
        RACE_API std::multimap<double, std::string> calcAllTime() const;
        RACE_API TypeReg addPlayer(Transport* currTran);
        RACE_API const std::vector<Transport*>& getListPlayers() const;
        RACE_API int getTypeRace() const;
        RACE_API void setDistance(double distance);
        RACE_API void setTypeRace(int typeRace);
        RACE_API virtual ~Race();
    private:
        int typeRace{ 0 };
        double distance{ 0.0 };
        std::vector<Transport*> listTransports{};
    };

}