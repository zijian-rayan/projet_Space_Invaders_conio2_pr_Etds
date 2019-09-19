#ifndef SPRITE_H
#define SPRITE_H

/*!
 * \file Sprite.h
 * \brief Contains the Sprite class declaration
 * \author Cedric BERNEZ
 * \version 0.1
 */

#include <vector>
#include "Coordinates_2D.h"

/**
 * \enum COLLISION_TYPES
 * \brief Collisions constants.
 */
enum COLLISION_TYPES
{
    NO_COLLISION = 0x00,
    VERTICAL_COLLISION = 0x01,
    HORIZONTAL_COLLISION = 0x10
};


/*! \class Sprite
 * \brief Class representing a sprite in the game
 *
 *  This class represents a moving element of the game,
 *  associated with an image, such as player
 */
class Sprite
{
public:
    /*!
     *  \brief Default constructor
     *
     *  Default Constructor of Sprite class
     */
    Sprite();
    /*!
     *  \brief Constructor
     *
     *  Constructor of Sprite class with initialization parameters
     *
     *  \param col : color of the sprite
     *  \param ps : position of the sprite
     *  \param sp : moving speed
     *  \param img : image associated with the sprite (2D table of characters)
     */
    Sprite(int col, Position ps, Speed sp, std::vector< std::vector<char> > img );
    // Getters and setters
    int getColor()
    {
        return color;
    }
    void setColor(int val)
    {
        color = val;
    }
    int getWidth() const
    {
        return w;
    }
    int getHeight() const
    {
        return h;
    }
    Position getPos() const
    {
        return pos;
    }
    void setPos(Position val)
    {
        pos = val;
    }
    Speed getSpd()
    {
        return spd;
    }
    void setSpd(Speed val)
    {
        spd = val;
    }

    /*!
     *  \brief Display the sprite
     *
     *  Display the sprite on the current screen
     */
    void display();
    void displayi(unsigned int i,unsigned int j);
    /*!
     *  \brief Erase the sprite
     *
     *  Erase the sprite on the current screen
     */
    void cleanoff();

    /*!
     *  \brief Change sprite coordinates
     *
     *  Change sprite coordinates according to its speed within [xmin, xmax] and [ymin, ymax]
     *  Otherwise, function has no effect
     */
    void movexy(int xmin, int xmax, int ymin, int ymax);

    /*!
     *  \brief Change sprite y coordinate
     *
     *  Change sprite coordinates according to its speed within [ymin, ymax]
     *  Otherwise, function has no effect
     */
    void movey(int ymin, int ymax);

    /*!
     *  \brief Change sprite x coordinate
     *
     *  Change sprite coordinates according to its speed within [xmin, xmax]
     *  Otherwise, function has no effect
     */
    void movex(int xmin, int xmax);

    /*!
     *  \brief Check collision with another sprite
     *
     *  \param spr : the sprite to check with
     *  \return True if the sprite collides with the one given in parameter, false otherwise
     */
    bool isInCollisionWith(const Sprite &spr);


private:
    int color;
    int w;
    int h;
    Position pos;
    Speed spd;
    std::vector< std::vector<char> > image;
};

#endif // SPRITE_H
