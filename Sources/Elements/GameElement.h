#pragma once

#include "../Field/Team.h"

class Tile;

class GameElement
{
    private:
        int life;
        int fullLife;

    protected:
        Team* relatedTeam;
		Tile* ptile;
		GameElement(int initialLife, Team* rTeam) : life(initialLife), fullLife(initialLife), relatedTeam(rTeam), ptile(nullptr) {};

    public:
        bool dealDamage(int ammount);

        virtual std::vector<std::string> displayElement() =0;
        std::string displayLifeBar();

        int getLife();
        int getMaxLife();

        bool getRight();

        bool isDead() const;

        const Team& getRelatedTeam()const;

		void setPtile(Tile* pt) { ptile = pt; }

        ~GameElement(){};
};