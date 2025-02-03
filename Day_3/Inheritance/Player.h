//
// Created by DarsenOP on 2/3/25.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Person.h"

class Player : private Person {
    // This has access to all members of Player, but not Person's private members
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    // We can also inherit Base class constructor with
    // using Person::Person;
public:
    // using Person::m_First_name;

    Player();
    Player(std::string_view first_name_param, std::string_view last_name_param, std::string_view game_param);
    ~Player();

    Player(const Player& other);
public:
    std::string m_Game{"None"};
};



#endif //PLAYER_H
