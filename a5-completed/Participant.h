/*
 * Purpose of the class: The Participant class is an abstract class that hold the data and methods for a single participant in the game.
 *
 * char avatar: The avatar of the participant.
 * bool dead: Whether the participant is dead.
 * int row: The row of the participant.
 * int col: The column of the participant.
 * MoveBehaviour *moveB: The move behaviour of the participant.
 *
 * void incurDamage(Participant *): The function that causes the participant to incur damage.
 * int causeDamage(): The function that causes the participant to cause damage.
 * bool isSafe(): The function that checks if the participant is safe.
 * void move(): The function that moves the participant.
 */

#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "defs.h"
#include "MoveBehaviour.h"

class Participant
{
public:
    Participant(char = 'A', int = 0, int = 0, MoveBehaviour * = nullptr);
    virtual ~Participant();
    virtual void incurDamage(Participant *) = 0;
    virtual int causeDamage() = 0;
    virtual bool isSafe() = 0;
    virtual void move();
    char getAvatar() const;
    int getRow() const;
    int getCol() const;
    void setBehaviour(MoveBehaviour *);
    bool isDead() const;

protected:
    char avatar;
    bool dead;
    int row;
    int col;
    MoveBehaviour *moveB;
};

#endif