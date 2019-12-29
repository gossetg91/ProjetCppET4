#pragma once

#include "Team.h"
#include "Tile.h"
#include <string>

class Game
{

    private:
        
        int turnLimit;
        int turnNumber;

        Team leftTeam;
        Team rightTeam;

        Tile terrain[12]; 
    public:
        Game(int tLimit, std::string leftTeamName , bool lIsAi , std::string rightTeamName, bool rIsAi , int initialMoney): turnLimit(tLimit)
                                                                                                                            ,turnNumber(0)
                                                                                                                            ,leftTeam(leftTeamName,lIsAi,initialMoney)
                                                                                                                            ,rightTeam(rightTeamName,rIsAi,initialMoney)
        {
            for(int i = 0 ; i<12 ; i++)
            {
                terrain[i] = Tile(i);
                
                if(i == 0)
                {
                    terrain[i].setBase(leftTeam.getBaseRef());
                }
                else if(i == 11)
                {
                    terrain[i].setBase(rightTeam.getBaseRef());
                    
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

        ~Game(){};
};