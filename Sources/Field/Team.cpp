#include "Team.h"
#include <iostream> 

bool Team::isRight()
{
    return right;
}

int Team::getMoney()
{
    return money;
}

bool Team::getIsAi() 
{
    return isAi;
}

const std::string& Team::getName() const
{
    return name;
}

void Team::setName(std::string c) {
	if (c == "") {
		if (isRight()) name = "Droite";
		else name = "Gauche";
	}
	//insérez les vérification de censure
	if (c.find("G@M3R") != std::string::npos) {
		std::cout << "Projet voltaire sauvage intervient !" << std::endl;
		name = "gaimeur";
	}
	else name = c;
}

void Team::spend(int ammount)
{
    if(ammount > money)
    {
        money = 0;
    }
    else
    {
        money -= ammount;
    }
    
}