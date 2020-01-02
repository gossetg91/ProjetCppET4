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

}

void Bowman::action2()
{

}

void Bowman::action3()
{

}

int Bowman::getUnitPrice()
{
    return 12;
}