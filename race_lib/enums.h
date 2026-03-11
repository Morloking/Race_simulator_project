#pragma once

namespace race_simulator {

    enum class TypeReg : int {
        FIRST,
        AFTER_ADDED,
        ALREADY_ADDED,
        INCONGRUITY_TYPE
    };

    enum class PostRegistrationAction : int {
        RESET_POST_REG_ACTION = -1,
        CONTINUE_REGISTRATION = 1,
        START_RACE = 2
    };

    enum class EndRaceAction : int {
        RESET_END_ACTION = -1,
        START_NEW_RACE = 1,
        EXIT_ACTION = 2
    };

    enum class RaceType : int {
        EMPTY_TYPE,
        GROUND,
        AIR,
        MIXED
    };

    enum class RacePhase {
        RACE_TYPE_SELECTION,
        DISTANCE_SELECTION,
        REGISTRATION,
        POST_REGISTRATION_MENU,
        RACE_RESULTS,
        EXIT
    };

}