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
    
    bool isRight() const; //balkany

    int getMoney();
    bool getIsAi();

	void setAi() { isAi = true; }
	
	bool operator==(const Team t) const;

    void spend(int);

    const std::string& getName() const;
	void setName(std::string c);

	std::string toDat() const;

    ~Team(){};
};