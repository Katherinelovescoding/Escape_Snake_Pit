#include "MoveBehaviour.h"

void EscapeeBehaviour::move(int oldRow, int oldCol, int &newRow, int &newCol)
{
    int row_move = random(5) - 2;
    newRow = oldRow + row_move;
    if (newRow < 0 || newRow >= MAX_ROW - 1)
    {
        newRow = oldRow;
    }

    int col_move = random(3) - 1;
    newCol = oldCol + col_move;
    if (newCol < 0 || newCol >= MAX_COL)
    {
        newCol = oldCol;
    }
};

void VillainBehaviour::move(int oldRow, int oldCol, int &newRow, int &newCol)
{
    int row_move = random(2);
    if (row_move == 0)
    {
        row_move = -1;
    }

    newRow = oldRow + row_move;
    if (newRow < 0 || newRow >= MAX_ROW - 1)
    {
        newRow = oldRow;
    }

    if (newRow < MAX_ROW - 1 - 7)
    {
        newRow = oldRow;
    }

    int col_move = random(3) - 1;
    newCol = oldCol + col_move;
    if (newCol < 0 || newCol >= MAX_COL)
    {
        newCol = oldCol;
    }
};

void RescuerBehaviour::move(int oldRow, int oldCol, int &newRow, int &newCol)
{
    newRow = oldRow + 1;
    if (newRow < 0 || newRow >= MAX_ROW)
    {
        newRow = oldRow;
    }
    newCol = oldCol;
};

void RescuedBehaviour::move(int oldRow, int oldCol, int &newRow, int &newCol)
{
    newRow = oldRow - 1;
    if (newRow < 0)
    {
        newRow = 0;
    }
    if (newRow >= MAX_ROW - 1)
    {
        newRow = MAX_ROW - 2;
    }
    newCol = oldCol;
};