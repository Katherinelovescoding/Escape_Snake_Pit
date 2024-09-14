/*
 * Purpose of the class: The MoveBehaviour class is an abstract behaviour class that encapsulates the move behaviour of a participant. It has 4 derived classes: EscapeeBehaviour, VillainBehaviour, RescuerBehaviour, and RescuedBehaviour.
 *
 * void move(int, int, int &, int &): The function that moves the participant.
 */

#ifndef MOVEBEHAVIOUR_H
#define MOVEBEHAVIOUR_H

#include "defs.h"

class MoveBehaviour
{
public:
    virtual void move(int, int, int &, int &) = 0;
    virtual ~MoveBehaviour() {};
};

class EscapeeBehaviour : public MoveBehaviour
{
    virtual void move(int, int, int &, int &);
    virtual ~EscapeeBehaviour() {};
};

class VillainBehaviour : public MoveBehaviour
{
    virtual void move(int, int, int &, int &);
    virtual ~VillainBehaviour() {};
};

class RescuerBehaviour : public MoveBehaviour
{
    virtual void move(int, int, int &, int &);
    virtual ~RescuerBehaviour(){};
};

class RescuedBehaviour : public MoveBehaviour
{
    virtual void move(int, int, int &, int &);
    virtual ~RescuedBehaviour() {};
};

#endif