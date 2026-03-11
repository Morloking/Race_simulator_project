#include <cstdlib>
#include <limits>

#include <iostream>
#include <memory>
#include <string>

#include "export.h"
#include "enums.h"
#include "air_race.h"
#include "all_terrain_boots.h"
#include "broom.h"
#include "camel.h"
#include "centaur.h"
#include "eagle.h"
#include "fast_camel.h"
#include "fly_carpet.h"
#include "ground_race.h"
#include "mixed_race.h"

using std::cin;
using std::cout;

using race_simulator::Transport;
using race_simulator::AllTerrainBoots;
using race_simulator::Broom;
using race_simulator::Camel;
using race_simulator::Centaur;
using race_simulator::Eagle;
using race_simulator::EndRaceAction;
using race_simulator::FastCamel;
using race_simulator::FlyCarpet;
using race_simulator::Race;
using race_simulator::AirRace;
using race_simulator::GroundRace;
using race_simulator::MixedRace;
using race_simulator::PostRegistrationAction;
using race_simulator::RacePhase;
using race_simulator::RaceType;
using race_simulator::TypeReg;

void checkInputAndClear(double& input, double basicValue) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        input = basicValue;
    }
}
void checkInputAndClear(int& input, int basicValue) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        input = basicValue;
    }
}

void warnIfNotMinPlayers() {
    int input;
    do {
        cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства\n"
            << "1. Зарегистрировать транспорт\n"
            << "Выберите действие: ";
        cin >> input;
        checkInputAndClear(input, 0);
    } while (input != 1);
    std::system("cls");
}

std::string raceTypeToString(RaceType type) {
    switch (type) {
    case RaceType::GROUND: return "Гонка для наземного транспорта";
    case RaceType::AIR:    return "Гонка для воздушного транспорта";
    case RaceType::MIXED:  return "Гонка для наземного и воздушного транспорта";
    default:               return "";
    }
}

bool run() {
    RaceType raceType = RaceType::EMPTY_TYPE;
    double distance = 0.0;
    int action = -1;
    PostRegistrationAction postRegAction = PostRegistrationAction::RESET_POST_REG_ACTION;

    const std::string players[7]{
        "Ботинки-вездеходы", "Метла", "Верблюд", "Кентавр",
        "Орёл", "Верблюд-быстроход", "Ковёр-самолёт"
    };

    const std::string menuRaceTypes[3]{
        "Гонка для наземного транспорта",
        "Гонка для воздушного транспорта",
        "Гонка для наземного и воздушного транспорта"
    };

    std::vector<std::unique_ptr<Transport>> allTransportsPr;
    TypeReg typeR = TypeReg::FIRST;
    std::unique_ptr<Transport> transportPr = nullptr;
    std::unique_ptr<Race> racePr = nullptr;
    std::string tempName;
    bool hasMinPlayers = false;

    RacePhase phase = RacePhase::RACE_TYPE_SELECTION;

    while (phase != RacePhase::EXIT) {
        switch (phase) {
        case RacePhase::RACE_TYPE_SELECTION: {
            int raceTypeInt = 0;
            while (raceTypeInt < 1 || raceTypeInt > 3) {
                for (int i = 0; i < 3; ++i)
                    cout << i + 1 << ". " << menuRaceTypes[i] << "\n";
                cout << "Выберите тип гонки: ";
                cin >> raceTypeInt;
                checkInputAndClear(raceTypeInt, 0);
                std::system("cls");
            }
            raceType = static_cast<RaceType>(raceTypeInt);
            phase = RacePhase::DISTANCE_SELECTION;
            break;
        }

        case RacePhase::DISTANCE_SELECTION: {
            while (distance <= 0.0) {
                cout << "Укажите длину дистанции (должна быть положительна): ";
                cin >> distance;
                checkInputAndClear(distance, 0.0);
                std::system("cls");
            }
            phase = RacePhase::REGISTRATION;
            break;
        }

        case RacePhase::REGISTRATION: {
            if (!racePr) {
                if (raceType == RaceType::GROUND) racePr = std::make_unique<GroundRace>(distance);
                else if (raceType == RaceType::AIR) racePr = std::make_unique<AirRace>(distance);
                else if (raceType == RaceType::MIXED) racePr = std::make_unique<MixedRace>(distance);
            }

            do {
                if (postRegAction == PostRegistrationAction::CONTINUE_REGISTRATION) {
                    typeR = TypeReg::FIRST;
                    postRegAction = PostRegistrationAction::RESET_POST_REG_ACTION;
                }

                if (typeR == TypeReg::AFTER_ADDED) cout << tempName << " успешно зарегистрирован!\n";
                else if (typeR == TypeReg::ALREADY_ADDED) cout << tempName << " уже зарегистрирован!\n";
                else if (typeR == TypeReg::INCONGRUITY_TYPE) cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n";

                cout << raceTypeToString(raceType) << ". Расстояние: " << distance << "\n";

                const auto& lPlayers = racePr->getListPlayers();
                if (!lPlayers.empty()) {
                    cout << "Зарегистрированные транспортные средства: ";
                    for (size_t i = 0; i < lPlayers.size(); ++i) {
                        cout << lPlayers[i]->getName();
                        if (i != lPlayers.size() - 1) cout << ", ";
                    }
                    cout << "\n";
                }

                for (int i = 0; i < 7; ++i) cout << i + 1 << ". " << players[i] << "\n";
                cout << "0. Закончить регистрацию\n"
                    << "Выберите транспорт или 0 для окончания процесса регистрации: ";

                auto processAction = [&](int act) {
                    switch (act) {
                    case 1: transportPr = std::make_unique<AllTerrainBoots>(); break;
                    case 2: transportPr = std::make_unique<Broom>(); break;
                    case 3: transportPr = std::make_unique<Camel>(); break;
                    case 4: transportPr = std::make_unique<Centaur>(); break;
                    case 5: transportPr = std::make_unique<Eagle>(); break;
                    case 6: transportPr = std::make_unique<FastCamel>(); break;
                    case 7: transportPr = std::make_unique<FlyCarpet>(); break;
                    default: return;
                    }
                    typeR = racePr->addPlayer(transportPr.get());
                    tempName = transportPr->getName();
                    if (typeR == TypeReg::AFTER_ADDED) allTransportsPr.push_back(std::move(transportPr));
                    };

                cin >> action;
                if (action >= 1 && action <= 7) processAction(action);
                checkInputAndClear(action, -1);
                std::system("cls");

                if (allTransportsPr.size() >= 2) hasMinPlayers = true;

                if (!hasMinPlayers && action == 0) {
                    action = -1;
                    postRegAction = PostRegistrationAction::CONTINUE_REGISTRATION;
                    warnIfNotMinPlayers();
                }
            } while (action != 0);

            phase = RacePhase::POST_REGISTRATION_MENU;
            break;
        }

        case RacePhase::POST_REGISTRATION_MENU: {
            cout << "1. Зарегистрировать транспорт\n"
                << "2. Начать гонку\n"
                << "Выберите действие: ";
            int tempChoice;
            cin >> tempChoice;
            checkInputAndClear(tempChoice, -1);
            if (tempChoice == 1) phase = RacePhase::REGISTRATION;
            else if (tempChoice == 2) phase = RacePhase::RACE_RESULTS;
            else {}
            std::system("cls");
            break;
        }

        case RacePhase::RACE_RESULTS: {
            cout << "Результаты гонки:\n";
            int indexResult = 1;
            for (const auto& pair : racePr->calcAllTime()) {
                cout << indexResult << ". " << pair.second << ". Время: " << pair.first << "\n";
                ++indexResult;
            }
            cout << "\n\n";

            EndRaceAction endAction = EndRaceAction::RESET_END_ACTION;
            do {
                cout << "1. Провести ещё одну гонку\n"
                    << "2. Выйти\n"
                    << "Выберите действие: ";
                int temp;
                cin >> temp;
                checkInputAndClear(temp, -1);
                if (temp == 1) endAction = EndRaceAction::START_NEW_RACE;
                else if (temp == 2) endAction = EndRaceAction::EXIT_ACTION;
                else endAction = EndRaceAction::RESET_END_ACTION;
            } while (endAction != EndRaceAction::START_NEW_RACE && endAction != EndRaceAction::EXIT_ACTION);

            std::system("cls");

            if (endAction == EndRaceAction::START_NEW_RACE) {
                raceType = RaceType::EMPTY_TYPE;
                distance = 0.0;
                action = -1;
                postRegAction = PostRegistrationAction::RESET_POST_REG_ACTION;
                racePr.reset();
                allTransportsPr.clear();
                typeR = TypeReg::FIRST;
                transportPr.reset();
                tempName.clear();
                hasMinPlayers = false;
                phase = RacePhase::RACE_TYPE_SELECTION;
            }
            else phase = RacePhase::EXIT;
            break;
        }

        default:
            phase = RacePhase::EXIT;
            break;
        }
    }

    return (phase == RacePhase::EXIT ? false : true);
}

int main() {
    setlocale(LC_ALL, "Russian");
    bool needContinue = true;
    cout << "Добро пожаловать в гоночный симулятор!\n";
    while (needContinue) {
        needContinue = run();
    }
}