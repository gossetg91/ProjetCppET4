#pragma once

#include<string>
#include<vector>

#include"../Elements/Base.h"
#include"../Elements/GameElement.h"  

class Team
{
private:
    int money;
    bool isAi;

    //boolean to know if display of members must be inverted
    bool right;

    std::string name;

    std::vector<GameElement> teamListing;

public:
    Team(std::string teamName , bool iAi , int initialMoney , bool isRight): money(initialMoney), isAi(iAi), right(isRight), name(teamName), teamListing(std::vector<GameElement>())
    {
        teamListing.push_back(Base(this));
    };

    Base* getBaseRef();

    bool isRight();

    ~Team(){};
};