#include "Snorc.h"

Snorc::Snorc(int r, int c, int s) : Participant('s', r, c, new VillainBehaviour())
{
    strength = s;
}

Snorc::~Snorc(){
    //delete moveB;
};

void Snorc::incurDamage(Participant *p){

};

int Snorc::causeDamage()
{
    return strength;
};

bool Snorc::isSafe()
{
    return false;
};