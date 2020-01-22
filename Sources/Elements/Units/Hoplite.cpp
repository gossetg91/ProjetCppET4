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
}

void Hoplite::action2()
{
	if (!isHasMoved() && checkMove()) move();
}

void Hoplite::action3()
{
	if (!isHasAttacked() || isSuper)
    {
		attack();
    };
}

int Hoplite::getUnitPrice()
{
    return 10;
}

void Hoplite::attack() {

	bool isHoplite = false;

	Tile* t = checkAttack();
	if (t == nullptr) return;

	std::cout << t->getElement()->isHoplite() << std::endl;
	if (t->getElement()->isHoplite()) isHoplite = true;

	if (t->attackInside(getAttack()) && isHoplite) {

		setSuper();  //on a tué l'hoplite
	}

	setHasAttacked();
}