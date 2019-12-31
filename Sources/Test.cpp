#include"Game.h"

#include"Field/Team.h"
#include"Field/Tile.h"

#include"Elements/GameElement.h"
#include"Elements/Base.h"

#include"Elements/Units/Unit.h"
#include"Elements/Units/Hoplite.h"
#include"Elements/Units/Catapult.h"
#include"Elements/Units/Bowman.h"

#include<iostream>
#include<string>

int main()
{
    Game testGame = Game(1000,"t1",false,"t2",false,500);
    

    Team test1 = Team("test",false,1000,true);
    Team test2 = Team("test",false,1000,false);

    Catapult testC1 = Catapult(&test1);

    Catapult testC2 = Catapult(&test2);

    for (auto &current : testC1.displayElement())
    {
        std::cout << current << std::endl;
    }
    
     for (auto &current : testC2.displayElement())
    {
        std::cout << current << std::endl;
    }
    
    std::cout << testGame.DisplayField() << std::endl;
}