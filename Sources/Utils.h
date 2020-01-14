#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <tuple>

#include "Game.h"

void displayTitle();
Game createGame();
Game startGameMenu();
Game* loadFromSave(std::string loadPath);