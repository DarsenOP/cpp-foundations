//
// Created by DarsenOP on 2/3/25.
//

#include "Person.h"
#include "Player.h"

#include <iostream>

Player::Player()
{
    std::cout << "Player Constructor" << std::endl;
}

Player::Player(std::string_view first_name_param, std::string_view last_name_param, std::string_view game_param)
    : Person(first_name_param, last_name_param), m_Game(game_param)
{
    std::cout << "Player Constructor" << std::endl;
}


Player::~Player()
{
    std::cout << "Player Destructor" << std::endl;
}

Player::Player(const Player &other)
    : Person(other), m_Game(other.m_Game)
{
    std::cout << "Player Copy Constructor" << std::endl;
}
