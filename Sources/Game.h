#pragma once

#include"Field/Team.h"
#include"Field/Tile.h"

#include"Elements/GameElement.h"
#include"Elements/Base.h"

#include"Elements/Units/Unit.h"
#include"Elements/Units/Hoplite.h"
#include"Elements/Units/Catapult.h"
#include"Elements/Units/Bowman.h"

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
                                                                                                                            ,turnNumber(1)
                                                                                                                            ,leftTeam(leftTeamName,lIsAi,initialMoney,false)
                                                                                                                            ,rightTeam(rightTeamName,rIsAi,initialMoney,true)
                                                                                                                            ,terrain(std::vector<Tile>())
        {
            //Generating 2 bases for each team
            Base* bL =new  Base(&leftTeam);
            Base* bR =new Base(&rightTeam);

            //possible parameter to widen shorten the field.
            for(int i = 0 ; i<12 ; i++)
            {
                terrain.push_back(i);
                
                if(i == 0)
                {
                    terrain[i].setBase(bL);
                }
                else if(i == 11)
                {
                    terrain[i].setBase(bR);
                    
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

        void launchGame();
        void turnChoice(Team*);

        ~Game(){};
};