#include "Hero.h"

Hero::Hero(char av, int r, int c, string n) : Participant(av, r, c, new EscapeeBehaviour())
{
    name = n;
    health = MAX_HEALTH;
    rescued = false;
};

Hero::~Hero()
{
    //delete moveB;
}

void Hero::incurDamage(Participant *p)
{
    int damage = p->causeDamage();

    if (damage == RESCUE)
    {
        rescued = true;
        // their behaviour must be changed to rescued behaviour
        delete moveB;
        moveB = new RescuedBehaviour();
    }
    else
    {
        health -= damage;
        if (health <= 0)
        {
            dead = true;
            avatar = '+';
            health = 0;
        }
    }
}

int Hero::causeDamage()
{
    return 0;
}

bool Hero::isSafe()
{
    if (row == 0 && !dead)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Hero::getName() const
{
    return name;
}

int Hero::getHealth() const
{
    return health;
}

bool Hero::isRescued() const
{
    return rescued;
}

string Hero::getStatus()
{
    if (this->isDead())
    {
        return "Deceased";
    }
    else if (this->isRescued())
    {
        return "Rescued";
    }
    else if (this->isSafe())
    {
        return "Escaped";
    }
    else
    {
        return "";
    }
}