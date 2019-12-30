#pragma once

#include<string>
#include<vector>

#include"Base.h"
#include"GameElement.h"

class Team
{
private:
    int money;
    bool isAi;

    //boolean to know if display of members must be inverted
    bool isRight;

    std::string name;

    std::vector<GameElement> teamListing;

public:
    Team(std::string teamName , bool iAi , int initialMoney , bool right): money(initialMoney), isAi(iAi), isRight(right), name(teamName), teamListing(std::vector<GameElement>())
    {
        teamListing.push_back(Base());
    };

    Base* getBaseRef();

    ~Team(){};
};