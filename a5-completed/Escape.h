/*
 * Purpose of the class: Perform as the control object for the program.
 *
 * int numSnorcs: The number of Snorcs in the pit.
 * Hero *h1: The first hero in the pit.
 * Hero *h2: The second hero in the pit.
 * List<Participant *> participants: A list of all participants in the pit.
 *
 * void runEscape(): The function that runs the game.
 * static bool withinBounds(int, int): A static function that checks if a given position is within the bounds of the pit.
 * void spawnSnorcs(): Spawns the Snorcs in the pit. At most 12 Snorc objects can be spawned.
 * void spawnNinja(): Spawns the Ninja in the pit.
 * void moveParticipants(): Moves all participants in the pit.
 * Participant *checkForCollision(Participant *): Checks if a participant has collided with the other given participant.
 * bool isOver(): Determines if each hero has either escaped the Pit or died.
 * void printPit(): Prints the pit with all participants.
 * void printOutcome(Hero *): Prints the outcome for the given hero, including whether they escaped, or were rescued, or died.
 */

#ifndef ESCAPE_H
#define ESCAPE_H

#include "List.h"
#include "Participant.h"
#include "Hero.h"
#include "Snorc.h"
#include "Ninja.h"

class Escape
{
public:
    Escape();
    ~Escape();
    void runEscape();
    static bool withinBounds(int, int);

    // debugging

private:
    int numSnorcs;
    Hero *h1;
    Hero *h2;
    List<Participant *> participants;

    void spawnSnorcs();
    void spawnNinja();
    void moveParticipants();
    Participant *checkForCollision(Participant *);
    bool isOver();
    void printPit();
    void printOutcome(Hero *);
};
#endif