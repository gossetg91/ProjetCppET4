#include "Base.h"
#include <algorithm>

std::vector<std::string> Base::displayElement()
{
    std::vector<std::string> builded;

    std::string lifeBar = displayLifeBar();

    int limit = (42-lifeBar.length())/2;

    for(int i = 0; i<limit ; i++)
        lifeBar = " " + lifeBar + " ";

    if(lifeBar.length() < 42)
    {
        lifeBar += " ";
    }
    
    builded.push_back("                     |>>>                ");
    builded.push_back("                     |       \\,/         ");
    builded.push_back("       |>>>      _  _|_  _         |>>>  ");
    builded.push_back("       |   /`\\  |;| |;| |;|        |     ");
    builded.push_back("   _  _|_  _    \\\\.    .  /    _  _|_  _ ");
    builded.push_back("  |;|_|;|_|;|    \\\\:. ,  /    |;|_|;|_|;|");
    builded.push_back("  \\\\..      /    ||;   . |    \\\\.    .  /");
    builded.push_back("   \\\\.  ,  /     ||:  .  |     \\\\:  .  / ");
    builded.push_back("    ||:   |_   _ ||_ . _ | _   _||:   |  ");
    builded.push_back("    ||:  .|||_|;|_|;|_|;|_|;|_|;||:.  |  ");
    builded.push_back("    ||:   ||.    .     .      . ||:  .|  ");
    builded.push_back("    ||: . || .     . .   .  ,   ||:   |  ");
    builded.push_back("    ||:   ||:  ,  _______   .   ||: , |  ");
    builded.push_back("    ||:   || .   /+++++++\\    . ||:   |  ");
    builded.push_back("    ||:   ||.    |+++++++| .    ||: . |  ");
    builded.push_back(" __ ||: . ||: ,  |+++++++|.  . _||_   |  ");
    builded.push_back("    '--~~__|.    |+++++__|----~    ~`---,");
    builded.push_back("           ~---__|,--~'                  ");
    builded.push_back(lifeBar);

    if(relatedTeam->isRight())
    {
        for(size_t i = 0 ; i < builded.size()-1 ; i++)
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