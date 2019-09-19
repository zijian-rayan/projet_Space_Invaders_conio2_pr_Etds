#ifndef GAME_H
#define GAME_H

/*!
 * \file Game.h
 * \brief Contains the Game class declaration
 * \author Cedric BERNEZ
 * \version 0.1
 */

#include "Sprite.h"

/*! \class Game
 * \brief Class representing the game
 *
 *  This class represents the game
 *  and manages all the game processes
 */
class Game
{
public:
    /*!
     *  \brief Constructor
     *
     *  Constructor of Game class
     */
    Game();

    /*!
    *  \brief Destructor
    *
    *  Destructor of Game class
    */
    ~Game();

    /*!
     *  \brief Run the game
     *
     *  This is the main method of the game.
     *  It initializes all games parameters and runs the infinite loop.
     */
    void run();

private:
    bool cont;
    Sprite missile;
};

#endif // GAME_H
