#pragma once
#include "../Field/Team.h"

#include <vector>
#include <string>

class GameElement
{
    private:
        int life;
        int fullLife;

    protected:
        Team* relatedTeam;
        GameElement(int initialLife,Team* rTeam): life(initialLife), fullLife(initialLife), relatedTeam(rTeam){};
    public:
        bool dealDamage(int ammount);

        virtual std::vector<std::string> displayElement() =0;
        std::string displayLifeBar();

        int getLife();
        int getMaxLife();

        bool getRight();

        bool isDead() const;

        const Team& getRelatedTeam()const;

        ~GameElement(){};
};
