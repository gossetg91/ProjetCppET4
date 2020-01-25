#include "Catapult.h"
#include <algorithm>
#include <math.h>
#include <iostream>

std::vector<std::string> Catapult::displayElement()
{
     std::vector<std::string> builded;

    if(getLife() >= 10)
        builded.push_back(displayLifeBar()); 
    else
        builded.push_back(" " + displayLifeBar()); 
        
    builded.push_back("   /\\\\            ");
    builded.push_back("  /  \\\\           ");
    builded.push_back(" |    \\\\          ");
    builded.push_back(" |     \\\\         ");
    builded.push_back(" |      \\\\        ");
    builded.push_back(" |   ||-------|   ");
    builded.push_back(" U   /\\  \\==\\  \\  ");
    builded.push_back("    / -\\--\\==\\--\\ ");
    builded.push_back("   /    \\        \\");

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

	for (std::string &s : builded) {
		s = c + s + r;  //rajoute les couleurs
	}

    return builded;
}

void Catapult::action1()
{
	attack();
	if (isHasAttacked()) std::cout << "Catapulte en case " << getPtile()->getPosition() << " a attaque" << std::endl;
}

void Catapult::action2()
{

}

void Catapult::action3()
{
	if (!isHasAttacked() && !isHasMoved()) if (checkMove()) {
		move();
		std::cout << "Catapulte s'est deplacee en case " << getPtile()->getPosition() << std::endl;
	}
}

int Catapult::getUnitPrice()
{
    return 22;
}

void Catapult::attack() {

	int value = 0;

	Tile* t = checkAttack();
	if (t == nullptr) return;

	int distance = abs(getPtile()->getPosition() - t->getPosition());

	if (t->getElement() != nullptr) {
		value = t->getElement()->getUnitPrice();
	}

	if (t->attackInside(getAttack())) {
		relatedTeam->giveMoney(value/2);
	}

	


	//a ce stade, on a deja attaque une case forcement (pas besoin de return pour laisser hasAttacked a false)

	if (distance == 4) { //on attaque aussi t-1 (t=4)
	
		if (getRelatedTeam().isRight()) {

			if (t->getNext() == nullptr) {
				setHasAttacked();
				return; 
			}
			value = t->getNext()->getElement()->getUnitPrice();

			if (t->getNext()->attackInside(getAttack())) { //on attaque la case d'après
				relatedTeam->giveMoney(value / 2);
			}
		}
		else {
			if (t->getPrec() == nullptr) {
				setHasAttacked();
				return;
			}
			value = t->getPrec()->getElement()->getUnitPrice();

			if (t->getPrec()->attackInside(getAttack())) { //on attaque la case d'avant
				relatedTeam->giveMoney(value / 2);
			}
		}
	}

	else { //on attaque aussi t+1

		if (getRelatedTeam().isRight()) {

			if (t->getPrec() == nullptr) {
				setHasAttacked();
				return;
			}
			value = t->getPrec()->getElement()->getUnitPrice();

			if (t->getPrec()->attackInside(getAttack())) { //on attaque la case d'avant
				relatedTeam->giveMoney(value / 2);
			}
		}
		else {
			if (t->getNext() == nullptr) {
				setHasAttacked();
				return;
			}
			value = t->getNext()->getElement()->getUnitPrice();
			
			if (t->getNext()->attackInside(getAttack())) {//on attaque la case d'après
				relatedTeam->giveMoney(value / 2);
			}
		}

	}


	setHasAttacked();
}