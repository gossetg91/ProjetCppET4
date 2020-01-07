#include "Catapult.h"
#include <algorithm>
#include <math.h>

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

    return builded;
}

void Catapult::action1()
{
	attack();
}

void Catapult::action2()
{

}

void Catapult::action3()
{
	if (!isHasAttacked() && !isHasMoved()) if (checkMove()) move();
}

int Catapult::getUnitPrice()
{
    return 22;
}

void Catapult::attack() {

	Tile* t = checkAttack();
	if (t == nullptr) return;

	int distance = abs(getPtile()->getPosition() - t->getPosition());


	t->attackInside(getAttack());


	//a ce stade, on a deja attaque forcement (pas besoin de return pour laisser hasAttacked a false)

	if (distance == 4) { //on attaque aussi 4-1 (t=4)
	
		if (getRelatedTeam().isRight()) {
			t->getNext()->attackInside(getAttack()); //on attaque la case d'après
		}
		else {
			t->getPrec()->attackInside(getAttack()); //on attaque la case d'avant
		}
	}

	else { //on attaque aussi t+1

		if (getRelatedTeam().isRight()) {
			t->getPrec()->attackInside(getAttack()); //on attaque la case d'avant
		}
		else {
			t->getNext()->attackInside(getAttack()); //on attaque la case d'après
		}

	}

	setHasAttacked();
}