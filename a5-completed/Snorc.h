/*
 * Purpose of the class: The Snorc class is a derived class of the Participant class. It holds the data and methods for a single Snorc object.
 *
 * int strength: The strength of the snorc.
 *
 * void incurDamage(Participant *): The function that causes the snorc to incur damage.
 * int causeDamage(): The function that causes the snorc to cause damage.
 * bool isSafe(): The function that checks if the snorc is safe.
 */

#ifndef SNORC_H
#define SNORC_H

#include "Participant.h"

class Snorc : public Participant
{
public:
    Snorc(int = 0, int = 0, int = 0);
    virtual ~Snorc();
    virtual void incurDamage(Participant *);
    virtual int causeDamage();
    virtual bool isSafe();

private:
    int strength;
};
#endif