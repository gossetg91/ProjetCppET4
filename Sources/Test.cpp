#include"Game.h"

#include"Field/Team.h"
#include"Field/Tile.h"

#include"Elements/GameElement.h"
#include"Elements/Base.h"

#include"Elements/Units/Unit.h"
#include"Elements/Units/Hoplite.h"
#include"Elements/Units/Catapult.h"
#include"Elements/Units/Bowman.h"

#include"Utils.h"

#include<iostream>
#include<string>

int main()
{
    displayTitle();
    Game generatedGame = startGameMenu();
    generatedGame.launchGame();
}

