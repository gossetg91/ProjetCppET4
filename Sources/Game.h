#pragma once

#include"Field/Team.h"
#include"Field/Tile.h"

#include"Elements/GameElement.h"
#include"Elements/Base.h"

#include"Elements/Units/Unit.h"
#include"Elements/Units/Hoplite.h"
#include"Elements/Units/Catapult.h"
#include"Elements/Units/Bowman.h"

#include"Utils.h"

#include <string>
#include "iostream"

#define FIELD_WIDTH 12

class Game
{

    private:
        
        int turnLimit;
        int turnNumber;

        Team leftTeam;
        Team rightTeam;

        std::vector<Tile> terrain; 

		void action(bool asc, Team t, int nAction);
		void turnChoice(Team*);
        
    public:

        Game(int tLimit, std::string leftTeamName , bool lIsAi , std::string rightTeamName, bool rIsAi , int initialMoney): turnLimit(tLimit)
                                                                                                                            ,turnNumber(1)
                                                                                                                            ,leftTeam(leftTeamName,lIsAi,initialMoney,false)
                                                                                                                            ,rightTeam(rightTeamName,rIsAi,initialMoney,true)
                                                                                                                            ,terrain(std::vector<Tile>(FIELD_WIDTH))
        {
            //Generating 2 bases for each team
            Base* bL =new Base(&leftTeam);
            Base* bR =new Base(&rightTeam);

            //Field generation
            for(int i = 0 ; i < FIELD_WIDTH; i++)
            {
				terrain.at(i) = Tile(i);
                
                if(i == 0) {
                    terrain.at(i).setBase(bL);

					terrain.at(i).setPrec(nullptr); //rajoutée
                }

                else if(i == FIELD_WIDTH-1){
                    terrain.at(i).setBase(bR);
                    
                    terrain.at(i).setPrec(&terrain.at(i-1));
                    terrain.at(i-1).setNext(&terrain.at(i));

					terrain[i].setNext(nullptr); //rajoutée
                }

                else {
                    terrain.at(i).setPrec(&terrain.at(i-1));
                    terrain.at(i-1).setNext(&terrain.at(i));
                }
                
            } 
        };

        std::string DisplayField();

        void launchGame();


        ~Game(){};
};