/*
 * Purpose of the class: The Ninja class is a derived class of the Participant class. It holds the data and methods for a single Ninja object.
 *
 * int strength: The strength of the ninja.
 * bool poisoned: Whether the ninja is poisoned.
 *
 * void incurDamage(Participant *): The function that causes the ninja to incur damage.
 * int causeDamage(): The function that causes the ninja to cause damage.
 * bool isSafe(): The function that checks if the ninja is safe.
 */

#ifndef NINJA_H
#define NINJA_H

#include "Participant.h"

class Ninja : public Participant
{
public:
    Ninja(int = 0, int = 0);
    virtual ~Ninja();
    virtual void incurDamage(Participant *);
    virtual int causeDamage();
    virtual bool isSafe();

private:
    int strength;
    bool poisoned;
};

#endif