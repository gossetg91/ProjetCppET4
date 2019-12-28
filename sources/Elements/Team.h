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
    std::string name;

    std::vector<GameElement> teamListing;

public:
    Team(std::string teamName , bool iAi , int initialMoney): money(initialMoney), isAi(iAi), name(teamName), teamListing(std::vector<GameElement>())
    {
        teamListing.push_back(Base())
    };
    Base* getBaseRef();
    ~Team();
};