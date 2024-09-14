#include "Participant.h"
Participant::Participant(char a, int r, int c, MoveBehaviour *m)
{
    avatar = a;
    row = r;
    col = c;
    moveB = m;
    dead = false;
}

Participant::~Participant()
{
    delete moveB;
}

void Participant::move()
{
    if (isDead() || isSafe())
    {
        return;
    }
    else
    {
        int newRow = 0;
        int newCol = 0;
        moveB->move(row, col, newRow, newCol);
        row = newRow;
        col = newCol;
    }
}

char Participant::getAvatar() const
{
    return avatar;
}

int Participant::getRow() const
{
    return row;
}

int Participant::getCol() const
{
    return col;
}

void Participant::setBehaviour(MoveBehaviour *m)
{
    moveB = m;
}

bool Participant::isDead() const
{
    return dead;
}