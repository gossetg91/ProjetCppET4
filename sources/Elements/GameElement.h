#pragma once

class GameElement
{
    private:
        int life;
    
    protected:
        GameElement(int initialLife): life(initialLife){};
    public:
        bool dealDamage(int ammount);
        ~GameElement();
};
