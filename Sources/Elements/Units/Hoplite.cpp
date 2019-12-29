#include "Hoplite.h"

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
    
    
    return builded;
}

void Hoplite::action1()
{

}

void Hoplite::action2()
{

}

void Hoplite::action3()
{

}