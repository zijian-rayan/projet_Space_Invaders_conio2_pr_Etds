#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

/*!
 * \file Level.h
 * \brief Contains Level class declarations
 * \author Cedric BERNEZ
 * \version 0.1
 */

#include "Sprite.h"

#include <vector>


const unsigned int LEVEL_HORIZONTAL_SIZE = 80;
const unsigned int LEVEL_VERTICAL_SIZE = 20;


/*! \class Level
 * \brief Class representing a level of the game
 *
 */
class Level
{
public:
    /*!
    *  \brief Constructor
    *
    *  Constructor of Level class
    *
    *  Creates a default level
    */
    Level();

    /*!
     *  \brief Display the level
     *
     *  Display all the level elements on the current screen
     */
    void display();
    void fire(Sprite &spr);
    /*!
     *  \brief Actualize the level
     *
     *  Actualize the invaders positions to "animate" the level,
     *  generate random missiles shooting from invaders,
     *  animate missiles and detect collisions between missiles, player and invaders
     *
     *  \param spr : the player sprite for coordinates providing and missiles collisions detection
     *
     *  \return True if player has been hit, false otherwise
     */
    bool actualize(Sprite &spr);
    void refresh();
    void invader_fire();
    std::vector<Sprite> invaders_vect;
private:
    unsigned short invaders_rows_nb;
    unsigned short invaders_columns_nb;

    std::vector<Sprite> invaders_missiles_vect;
    std::vector<Sprite> player_missiles_vect;
};


#endif // LEVEL_H_INCLUDED
