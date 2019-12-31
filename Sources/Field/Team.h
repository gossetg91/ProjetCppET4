#pragma once

#include<string>
#include<vector>

#include"../Elements/GameElement.h"

class GameElement;

class Team
{
private:
    int money;
    bool isAi;

    //boolean to know if display of members must be inverted
    bool right;
    std::string name;

    //vector containing pointers on GameElements related to team.
    std::vector<GameElement*> TeamElements;

public:
    Team(std::string teamName , bool iAi , int initialMoney , bool isRight): money(initialMoney), isAi(iAi), right(isRight), name(teamName)
    {};

    void addTeamElement(GameElement* newElement);

    bool isRight();

    ~Team(){};
};