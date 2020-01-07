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
		GameElement(int initialLife, Team* rTeam) : life(initialLife), fullLife(initialLife), relatedTeam(rTeam) {};

    public:
        bool dealDamage(int ammount);

        virtual std::vector<std::string> displayElement() =0;
        std::string displayLifeBar();

        int getLife();
        int getMaxLife();
		void setLife(int l) { life = l; }

        bool getRight();

        bool isDead() const;

        const Team& getRelatedTeam() const;


        ~GameElement(){};
};