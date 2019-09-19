#ifndef COORDINATES_2D_H
#define COORDINATES_2D_H

/*!
 * \file Coordinates_2D.h
 * \brief Contains coordinates, Position and Speed declarations
 * \author Cedric BERNEZ
 * \version 0.1
 */


 /*! \class Coordinates
  * \brief Class representing an (x, y) doublet in a 2D system
  *
  * This class represents the (x, y) integer coordinates
  * in a 2D view (screen, text console...)
  */
class Coordinates
{
    // External operators
    friend Coordinates operator+(const Coordinates &, const Coordinates &);

    public:
        Coordinates(int xx=0, int yy=0);
        int getX() { return x; }
        void setX( int val) { x = val; }
        int getY() { return y; }
        void setY( int val) { y = val; }

    private:
        int x;
        int y;
};


/*! \class Position
 * \brief Class representing the (x, y) position of an element
 *
 */
class Position : public Coordinates
{
    public:
        Position(int xx=0, int yy=0);
};

/*! \class Speed
 * \brief Class representing the speed of an element in a 2D coordinate system
 *
 */
class Speed : public Coordinates
{
    public:
        Speed(int xx=0, int yy=0);
};

#endif // COORDINATES_2D_H
