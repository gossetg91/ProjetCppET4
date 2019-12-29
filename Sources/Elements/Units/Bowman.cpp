#include"Bowman.h"

std::vector<std::string> Bowman::displayElement()
{
     std::vector<std::string> builded;

    builded.push_back(" " + displayLifeBar() + " ");
    builded.push_back("      /\\         ");
    builded.push_back("     /__\\_{)     ");
    builded.push_back("    |--<<)__\\    ");
    builded.push_back("     \\  /  (     ");
    builded.push_back("      \\/ __)     ");
    builded.push_back("         \\ |__   ");
    builded.push_back("          ~    ~  ");

    return builded;
}

void Bowman::action1()
{

}

void Bowman::action2()
{

}

void Bowman::action3()
{

}