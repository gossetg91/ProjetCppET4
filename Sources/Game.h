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
#include <iostream>

#define FIELD_WIDTH_DEF 12

class Game
{

    private:
        
        int turnLimit;
        int turnNumber;

        Team* leftTeam;
        Team* rightTeam;

        std::vector<Tile> terrain; 

		void action(bool asc, Team t, int nAction);
		void turnChoice(Team*);
        bool saveGame(std::string, Team* currentTeam);

        bool rightFirst;

        
    public:

        Game(int tLimit, std::string leftTeamName , bool lIsAi , std::string rightTeamName, bool rIsAi , int initialMoney,int fieldSize = FIELD_WIDTH_DEF): turnLimit(tLimit)
                                                                                                                                                            ,turnNumber(1)
                                                                                                                                                            ,leftTeam(new Team(leftTeamName,lIsAi,initialMoney,false))
                                                                                                                                                            ,rightTeam(new Team(rightTeamName,rIsAi,initialMoney,true))
                                                                                                                                                            ,terrain(std::vector<Tile>(fieldSize))
                                                                                                                                                            ,rightFirst(false)
        {
            //Generating 2 bases for each team
            Base* bL =new Base(leftTeam);
            Base* bR =new Base(rightTeam);

            //Field generation
            for(int i = 0 ; i < fieldSize; i++)
            {
				terrain.at(i) = Tile(i);
                
                if(i == 0) {
                    terrain.at(i).setBase(bL);

					terrain.at(i).setPrec(nullptr); //rajout�e
                }

                else if(i == fieldSize-1){
                    terrain.at(i).setBase(bR);
                    
                    terrain.at(i).setPrec(&terrain.at(i-1));
                    terrain.at(i-1).setNext(&terrain.at(i));

					terrain[i].setNext(nullptr); //rajout�e
                }

                else {
                    terrain.at(i).setPrec(&terrain.at(i-1));
                    terrain.at(i-1).setNext(&terrain.at(i));
                }
                
            } 
        };

        Game(int tLimit,int tcount, Team* lT, Team* rT, std::vector<Tile> terrain , bool rFirst) : turnLimit(tLimit)
                                                                                       ,turnNumber(tcount)
                                                                                       ,leftTeam(lT)
                                                                                       ,rightTeam(rT)
                                                                                       ,terrain(terrain)
                                                                                       ,rightFirst(rFirst)
        {};

        std::string DisplayField();

        void launchGame();

		std::string toDat(Team* currentTeam);

        ~Game(){};
};