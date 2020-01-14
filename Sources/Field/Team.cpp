#include "Team.h"
#include <iostream>   

bool Team::isRight() const
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
	//ins�rez les v�rification de censure
	if (c.find("G@M3R") != std::string::npos) {
		std::cout << "Projet voltaire sauvage intervient !" << std::endl;
		name = "gaimeur";
	}
	else {
		if (c.length() > 42) c = c.substr(0, 39) + "..."; //troncature
		name = c;
	}
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

bool Team::operator==(const Team t) const{
	//laissé pour vérification mais normalement inutile (si l'appel a réussi this ne peut pas être nul a ce moment la)
    //if (this == nullptr) return false;
	if (right != t.right) return false;
	if (money != t.money) return false;
	if (isAi != t.isAi) return false;
	if (name != t.name) return false;
	return true;
}

std::string Team::toDat() const {
	return name + ',' + std::to_string(money) + ',' + (isAi ? '1' : '0');
}