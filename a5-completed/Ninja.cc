#include "Ninja.h"

Ninja::Ninja(int r, int c) : Participant('N', r, c, new RescuerBehaviour())
{
    strength = 0;
    poisoned = false;
};

Ninja::~Ninja(){
    //delete moveB;
};

void Ninja::incurDamage(Participant *p)
{

    if (poisoned)
    {
        return;
    }
    else
    {
        int damage = p->causeDamage();
        if (damage == RESCUE)
        {
            return;
        }
        else if (damage == 0)
        {
            // rescue the hero, implement this later
            delete moveB;
            moveB = new RescuedBehaviour();
        }
        else
        {
            avatar = 'S';
            strength = random(3) + 6;
            poisoned = true;
            delete moveB;
            moveB = new VillainBehaviour();
        }
    }
}

int Ninja::causeDamage()
{
    if (poisoned)
    {
        return strength;
    }
    else
    {
        return RESCUE;
    }
}

bool Ninja::isSafe()
{
    if (poisoned)
    {
        return false;
    }
    else if (row == 0 || row == MAX_ROW - 1)
    {
        return true;
    }
    return false;
}