#include "Escape.h"

Escape::Escape()
{
    srand((unsigned)time(NULL));
    numSnorcs = 0;

    int randomCol = random(10) + 7;
    h1 = new Hero('T', MAX_ROW - 2, randomCol, "Timmy");

    int randomCol2 = random(10) + 7;
    while (randomCol2 == randomCol)
    {
        randomCol2 = random(10) + 7;
    }
    h2 = new Hero('H', MAX_ROW - 2, randomCol2, "Harold");

    participants += h1;
    participants += h2;
};

Escape::~Escape(){
    
};

void Escape::runEscape()
{
    bool gameOver = false;
    printPit();
    int debug = 0;

    while (!gameOver) //&& debug < 10
    {
        debug++;
        usleep(200000);

        int snorcProb = random(100);
        if (snorcProb < 90 && numSnorcs < MAX_SNORCS)
        {
            spawnSnorcs();
        }

        int ninjaProb = random(100);
        if (ninjaProb < 33)
        {
            spawnNinja();
        }

        moveParticipants();

        system("clear");
        printPit();

        if (isOver())
        {
            gameOver = true;
        }
    }
    printOutcome(h1);
    printOutcome(h2);
};

bool Escape::isOver()
{
    if ((h1->isSafe() || h1->isDead()) && (h2->isSafe() || h2->isDead()))
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool Escape::withinBounds(int row, int col)
{
    if (row >= 0 && row < MAX_ROW && col >= 0 && col < MAX_COL)
    {
        return true;
    }
    else
    {
        return false;
    }
};

void Escape::spawnSnorcs()
{
    int randomCol = random(MAX_COL);
    int randomRow = random(5) + 1;
    int streng = random(3) + 2;
    Snorc *s = new Snorc(MAX_ROW - 1 - randomRow, randomCol, streng);
    participants += s;
    numSnorcs++;
};

void Escape::spawnNinja()
{
    int randomCol = random(MAX_COL);
    Ninja *n = new Ninja(1, randomCol);
    participants += n;
};

Participant *Escape::checkForCollision(Participant *p)
{
    int arrSize = 0;
    Participant *arr[MAX_ARR];
    participants.convertToArray(arr, arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] != p && arr[i]->getRow() == p->getRow() && arr[i]->getCol() == p->getCol())
        {
            return arr[i];
        }
    }
    return nullptr;
};

void Escape::moveParticipants()
{
    int arrSize = 0;
    Participant *arr[MAX_ARR];
    participants.convertToArray(arr, arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        if (!arr[i]->isDead() && !arr[i]->isSafe())
        {
            arr[i]->move();

            Participant *collision = checkForCollision(arr[i]);
            if (collision != nullptr)
            {
                arr[i]->incurDamage(collision);
                collision->incurDamage(arr[i]);
            }
        }
    }
}

void Escape::printPit()
{
    char pit[MAX_ROW + 1][MAX_COL + 3] = {
        "---------------------------",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "---------------------------"};

    Participant *arr[MAX_ARR];
    int arrSize = 0;
    participants.convertToArray(arr, arrSize);

    for (int i = arrSize - 1; i >= 0; i--)
    {
        if (arr[i]->getRow() != 0 && arr[i]->getRow() != MAX_ROW - 1)
        {
            int r = arr[i]->getRow();
            int c = arr[i]->getCol();
            pit[r][c + 1] = arr[i]->getAvatar();
        }
    }

    for (int i = 0; i < MAX_ROW - 2; i++)
    {
        for (int j = 0; j < MAX_COL + 3; j++)
        {
            cout << pit[i][j];
        }
        cout << endl;
    }

    for (int j = 0; j < MAX_COL + 3; j++)
    {
        cout << pit[MAX_ROW - 2][j];
    }
    cout << left << noshowbase << setfill(' ');
    cout << "     " << setw(8) << h1->getName() << " : " << h1->getHealth() << "    " << h1->getStatus() << endl;

    for (int j = 0; j < MAX_COL + 3; j++)
    {
        cout << pit[MAX_ROW - 1][j];
    }
    cout << left << noshowbase << setfill(' ');
    cout << "     " << setw(8) << h2->getName() << " : " << h2->getHealth() << "    " << h2->getStatus() << endl;
};

void Escape::printOutcome(Hero *h)
{
    if (h->isRescued() && h->isSafe())
    {
        cout << h->getName() << " was safely rescued!" << endl;
    }
    else if (!h->isRescued() && h->isSafe())
    {
        cout << h->getName() << " escaped on his own!!!" << endl;
    }
    else if (h->isDead())
    {
        cout << h->getName() << " died..." << endl;
    }
}