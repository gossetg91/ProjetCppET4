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
	std::string color; //string code to change color

public:
    Team(std::string teamName , bool iAi , int initialMoney , bool isRight, std::string Ncolor): money(initialMoney), isAi(iAi), right(isRight), name(teamName), color(Ncolor)
    {};
    
    bool isRight() const; //balkany

    int getMoney();
    bool getIsAi();

	void setAi() { isAi = true; }
	
	bool operator==(const Team t) const;

    void spend(int);

    const std::string& getName() const;
	void setName(std::string c);
	void setColor(std::string c);
	std::string getColor() { return color; }

	std::string toDat() const;

    ~Team(){};
};