#pragma once

#include "Field/Tile.h"
#include "Field/Team.h"
#include <string>

class Game
{

    private:
        
        int turnLimit;
        int turnNumber;

        Team leftTeam;
        Team rightTeam;

        std::vector<Tile> terrain; 
    public:
        Game(int tLimit, std::string leftTeamName , bool lIsAi , std::string rightTeamName, bool rIsAi , int initialMoney): turnLimit(tLimit)
                                                                                                                            ,turnNumber(0)
                                                                                                                            ,leftTeam(leftTeamName,lIsAi,initialMoney,false)
                                                                                                                            ,rightTeam(rightTeamName,rIsAi,initialMoney,true)
                                                                                                                            ,terrain(std::vector<Tile>())
        {
            //possible parameter to widen shorten the field.
            for(int i = 0 ; i<12 ; i++)
            {
                terrain.push_back(i);
                
                if(i == 0)
                {
                    terrain[i].setBase();
                }
                else if(i == 11)
                {
                    terrain[i].setBase();
                    
                    terrain[i].setPrec(&terrain[10]);
                    terrain[10].setNext(&terrain[i]);
                }
                else
                {
                    terrain[i].setPrec(&terrain[i-1]);
                    terrain[i-1].setNext(&terrain[i]);
                }
                
            } 
        };

        std::string DisplayField();

        ~Game(){};
};