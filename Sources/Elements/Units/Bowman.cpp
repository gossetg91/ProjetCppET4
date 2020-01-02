#include"Bowman.h"
#include<algorithm>

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

void Bowman::action1()
{
	attack();
}

void Bowman::action2()
{
	if (checkMove()) move();
}

void Bowman::action3()
{
	resetAction();
}

int Bowman::getUnitPrice()
{
    return 12;
}

void Bowman::attack() {

	Tile* t = checkAttack();
	if (t == nullptr) return;

	if (!(t->isEmpty())) t->getElement()->dealDamage(getAttack()); //on attaque le Unit (attention au cas Super !!! -> update attackStat)

	else t->getBase().dealDamage(getAttack()); //on attaque la Base

	setHasAttacked();
}