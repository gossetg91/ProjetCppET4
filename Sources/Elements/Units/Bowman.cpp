#include"Bowman.h"
#include<algorithm>
#include <iostream>

std::vector<std::string> Bowman::displayElement()
{
     std::vector<std::string> builded;

    builded.push_back(" " + displayLifeBar() + " ");
    builded.push_back("      /\\          ");
    builded.push_back("     /__\\_{)      ");
    builded.push_back("    |--<<)__\\     ");
    builded.push_back("     \\  /  (      ");
    builded.push_back("      \\/ __)      ");
    builded.push_back("         \\ |__    ");
    builded.push_back("          ~    ~  ");

    if(!relatedTeam->isRight())
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
			std::replace(builded[i].begin(), builded[i].end(), 'a', ')');
        
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

	for (std::string &s : builded) {
		s = c + s + r;  //rajoute les couleurs
	}

    return builded;
}

void Bowman::action1()
{
	attack();
	if (isHasAttacked()) std::cout << "Bowman en case " << getPtile()->getPosition() << " a attaque" << std::endl;
}

void Bowman::action2()
{
	if (!isHasMoved() && checkMove()) {
		move();
		std::cout << "Bowman s'est deplace en case " << getPtile()->getPosition() << std::endl;
	}
}

void Bowman::action3()
{

}

int Bowman::getUnitPrice()
{
    return 12;
}

void Bowman::attack() {

	int value = 0;

	Tile* t = checkAttack();
	if (t == nullptr) return;

	if (t->getElement() != nullptr) value = t->getElement()->getUnitPrice();


	if (t->attackInside(getAttack())) { //si l'ennemi meurt
		relatedTeam->giveMoney(value / 2);
	}

	setHasAttacked();
}