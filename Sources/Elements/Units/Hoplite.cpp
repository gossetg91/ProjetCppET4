#include "Hoplite.h"
#include<algorithm>
#include <iostream>

std::vector<std::string> Hoplite::displayElement()
{
     std::vector<std::string> builded;

    if(getLife() >= 10)
        builded.push_back(displayLifeBar()); 
    else
        builded.push_back(" " + displayLifeBar()); 

    if(!isSuper)
    {
        builded.push_back("  _   _+       |  ");
        builded.push_back("  _`-'_|  \\+/  |  ");
        builded.push_back("  _`C'_| _<=>_ |  ");
        builded.push_back("  _`-' 0/ \\ / o=o ");
        builded.push_back("       \\/\\ ^ /`0  ");
        builded.push_back("       | /_^_\\    ");
        builded.push_back("       | || ||    ");
        builded.push_back("     __|_d|_|b__  ");
    }
    else
    {
        builded.push_back("     |            ");
        builded.push_back("     |            ");
        builded.push_back("     + \\          ");
        builded.push_back("     \\\\.G_.*=.    ");
        builded.push_back("      `(#'/.\\|    ");
        builded.push_back("       .>' (_--.  ");
        builded.push_back("    _=/d   ,^\\    ");
        builded.push_back("   ~~ \\)-'   '    ");
        builded.push_back("      / |         ");
        builded.push_back("     '  '         ");
    }
    
    if(relatedTeam->isRight())
    {
        for(size_t i = 1 ; i < builded.size() ; i++)
        {
            std::reverse(builded[i].begin(),builded[i].end());

            //shifting assymetrical characters
            std::replace( builded[i].begin(), builded[i].end(), '/', 'a');
            std::replace( builded[i].begin(), builded[i].end(), '\\', '/');
            std::replace( builded[i].begin(), builded[i].end(), 'a', '\\');
        
            std::replace( builded[i].begin(), builded[i].end(), '(', 'a');
            std::replace( builded[i].begin(), builded[i].end(), ')', '(');
            std::replace( builded[i].begin(), builded[i].end(), 'a', ')');
        
            std::replace( builded[i].begin(), builded[i].end(), '{', 'a');
            std::replace( builded[i].begin(), builded[i].end(), '}', '{');
            std::replace( builded[i].begin(), builded[i].end(), 'a', '}');


            std::replace( builded[i].begin(), builded[i].end(), '[', 'a');
            std::replace( builded[i].begin(), builded[i].end(), ']', '[');
            std::replace( builded[i].begin(), builded[i].end(), 'a', ']');

            std::replace( builded[i].begin(), builded[i].end(), '<', 'a');
            std::replace( builded[i].begin(), builded[i].end(), '>', '<');
            std::replace( builded[i].begin(), builded[i].end(), 'a', '>');
        }
    }

	std::string c = relatedTeam->getColor();
	std::string r = "\e[0m";

	for (std::string & s : builded) {
		s = c + s + r;  //rajoute les couleurs
	}

    return builded;
}

void Hoplite::action1()
{
	attack();
	if (isHasAttacked()) std::cout << (isSuper ? "Super " : "") << "Hoplite en case " << getPtile()->getPosition() << " a attaque" << std::endl;
}

void Hoplite::action2()
{
	if (!isHasMoved() && checkMove()) {
		move();
		std::cout << (isSuper ? "Super " : "") << "Hoplite en case s'est deplace en case " << getPtile()->getPosition() << std::endl;
	}
}

void Hoplite::action3()
{
	if (!isHasAttacked() || isSuper)
    {
		attack();
		if (isHasAttacked()) std::cout << (isSuper ? "Super " : "") << "Hoplite en case " << getPtile()->getPosition() << " a attaque" << std::endl;
    };
}

int Hoplite::getUnitPrice()
{
    return 10;
}

void Hoplite::attack() {

	bool isHoplite = false;
	int value = 0;

	Tile* t = checkAttack();
	if (t == nullptr) return;

	if (t->getElement() != nullptr) {
		if (t->getElement()->isHoplite()) isHoplite = true;

		 value = t->getElement()->getUnitPrice();
	}

	if (t->attackInside(getAttack())) {
		if (isHoplite) setSuper();  //on a tue l'hoplite

		relatedTeam->giveMoney(value/2);
	}

	setHasAttacked();
}