#pragma once

#include <vector>
#include <string>

class GameElement
{
    private:
        int life;
        int fullLife;
    
    protected:
        GameElement(int initialLife): life(initialLife), fullLife(initialLife){};
    public:
        bool dealDamage(int ammount);

        virtual std::vector<std::string> displayElement() =0;
        std::string displayLifeBar();

        ~GameElement(){};
};
