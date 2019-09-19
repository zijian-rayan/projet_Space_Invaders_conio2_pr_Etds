/*!
 * \file Coordinates_2D.cpp
 * \brief Contains the Coordinates, Position and Speed classes methods definitions
 * \author Cedric BERNEZ
 * \version 0.1
 */

#include <Coordinates_2D.h>



Coordinates operator+(const Coordinates &c1, const Coordinates &c2)
{
    Coordinates cres;

    cres.x = c1.x + c2.x;
    cres.y = c1.y + c2.y;

    return cres;
}



Coordinates::Coordinates(int xx, int yy)
{
    // Constructor
    x = xx;
    y = yy;
}


Position::Position(int xx, int yy) : Coordinates(xx, yy)
{
    // Constructor
}


Speed::Speed(int xx, int yy) : Coordinates(xx, yy)
{
    // Constructor
}
