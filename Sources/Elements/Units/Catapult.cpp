#include "Catapult.h"
#include <algorithm>

std::vector<std::string> Catapult::displayElement(bool reversed)
{
     std::vector<std::string> builded;

    builded.push_back(" " + displayLifeBar() + " ");
    builded.push_back("   /\\\\            ");
    builded.push_back("  /  \\\\           ");
    builded.push_back(" |    \\\\          ");
    builded.push_back(" |     \\\\         ");
    builded.push_back(" |      \\\\        ");
    builded.push_back(" |   ||-------|   ");
    builded.push_back(" U   /\\  \\==\\  \\  ");
    builded.push_back("    / -\\--\\==\\--\\ ");
    builded.push_back("   /    \\        \\");

    if(reversed)
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

}

void Catapult::action2()
{

}

void Catapult::action3()
{

}