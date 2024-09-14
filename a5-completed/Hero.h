/*
 * Purpose of the class: The Hero class is a derived class of the Participant class. It holds the data and methods for a single Hero object.
 *
 * string name: The name of the hero.
 * int health: The health of the hero.
 * bool rescued: Whether the hero has been rescued by a ninja.
 *
 * void incurDamage(Participant *): The function that causes the hero to incur damage.
 * int causeDamage(): The function that causes the hero to cause damage.
 * bool isSafe(): The function that checks if the hero is safe.
 */

#ifndef HERO_H
#define HERO_H

#include "Participant.h"

class Hero : public Participant
{
public:
    Hero(char = 'A', int = 0, int = 0, string = "");
    virtual ~Hero();
    virtual void incurDamage(Participant *);
    virtual int causeDamage();
    virtual bool isSafe();
    string getName() const;
    int getHealth() const;
    bool isRescued() const;
    // helper functions
    string getStatus();

private:
    string name;
    int health;
    bool rescued;
};
#endif