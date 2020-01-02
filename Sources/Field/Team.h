#pragma once

#include<string>
#include<vector>

class Team
{
private:
    int money;
    bool isAi;

    //boolean to know if display of members must be inverted
    bool right;
    std::string name;

public:
    Team(std::string teamName , bool iAi , int initialMoney , bool isRight): money(initialMoney), isAi(iAi), right(isRight), name(teamName)
    {};
    
    bool isRight();

    int getMoney();
    bool getIsAi();

    void spend(int);

    const std::string& getName() const;

    ~Team(){};
};