/*!
 * \file Sprite.cpp
 * \brief Contains the Sprite class methods definitions
 * \author Cedric BERNEZ
 * \version 0.1
 */

#include "Sprite.h"

#include <cstdlib>
#include <iostream>
#include <conio2.h>

using namespace std;


Sprite::Sprite()
{
    // Default constructor
    color = LIGHTGRAY;
    pos = Position(1,1);
    spd = Speed(0,0);
    vector<char> line = {'*', '*', '*'};
    vector< vector<char> > img = {line, line};
    image = img;
    w = line.size();
    h = img.size();
}

Sprite::Sprite(int col, Position ps, Speed sp, std::vector< std::vector<char> > img )
{
    // Constructor
    unsigned int i, max_char_count;
    color = col;
    pos = ps;
    spd = sp;
    image = img;
    // Find the maximum width of sprite
    max_char_count = 0;
    for(i=0; i<image.size(); i++)
    {
        if( image.at(i).size()>max_char_count )
        {
            max_char_count = image.at(i).size();
        }
    }
    // Actualize width of the sprite
    w = max_char_count;
    // Actualize height of the sprite
    h = image.size();
}


void Sprite::display()
{
    unsigned short i, j;

    textcolor(color);
    for (j=0; j<image.size(); j++)
    {
        for(i=0; i<image.at(j).size(); i++)
        {
            gotoxy(pos.getX()+i, pos.getY()+j);
            cout << image.at(j).at(i);
        }
    }
}
/*
void Sprite::displayi(unsigned int i,unsigned int j)
{
    unsigned int ii = i;
    unsigned int jj = j;
    textcolor(color);
    for (; j<image.size()+jj; j++)
    {
        for(; i<image.at(j).size()+ii; i++)
        {
            gotoxy(pos.getX()+i, pos.getY()+j);
            cout << image.at(j).at(i);
        }
    }
}*/


void Sprite::cleanoff()
{
    // Complete the code
unsigned short i, j;

    textcolor(color);
    for (j=0; j<image.size(); j++)
    {
        for(i=0; i<image.at(j).size(); i++)
        {
            gotoxy(pos.getX()+i, pos.getY()+j);//Moving the cursor
            cout << ' ';//Delete everything in the cursor position
        }
    }

}


void Sprite::movexy(int xmin, int xmax, int ymin, int ymax)
{
    // Complete the code
    if(Sprite::pos.getX()<xmax&&Sprite::pos.getX()>xmin&&Sprite::pos.getY()<ymax&&Sprite::pos.getY()>ymin){
            //Determine if it is in the game interface
        Sprite::pos.setX(Sprite::pos.getX()+Sprite::spd.getX());//Move (position = original position + speed)
        Sprite::pos.setY(Sprite::pos.getY()+Sprite::spd.getY());}//Move (position = original position + speed)
}

void Sprite::movex(int xmin, int xmax)
{
    // Complete the code
    if(Sprite::pos.getX()>xmin&&Sprite::pos.getX()<xmax)//Determine if it is in the game interface
        Sprite::pos.setX(Sprite::pos.getX()+Sprite::spd.getX());//Move (position = original position + speed)

    else
        Sprite::pos.setX(Sprite::pos.getX());
}


void Sprite::movey(int ymin, int ymax)
{
    // Complete the code
    if(Sprite::pos.getY()<ymax&&Sprite::pos.getY()>ymin)//Determine if it is in the game interface
        Sprite::pos.setY(Sprite::pos.getY()+Sprite::spd.getY());//Move (position = original position + speed)
    else
        Sprite::pos.setY(Sprite::pos.getY());
}



bool Sprite::isInCollisionWith(const Sprite &spr)//Detect collision
{
  /*  bool is_colliding = false;

    // Complete the code
    Position thispos = this->pos;
    Position sprpos = spr.pos;
    int wid = spr.getWidth();
    if(thispos.getX()>=sprpos.getX()&&thispos.getX()<=(sprpos.getX()+wid)&&thispos.getY()==sprpos.getY())
        is_colliding = true;

    return is_colliding;*/
    bool is_colliding = false;//The initial value is no collision
//If there is a coincident part of the position of the two sprites, it is judged that a collision has occurred.
    if(pos.getX()<=(spr.getPos().getX()+spr.getWidth())&&(pos.getX()+w>=spr.getPos().getX())&&pos.getY()<=(spr.getPos().getY()+spr.getHeight())&&(pos.getY()+h>=spr.getPos().getY()))
       is_colliding=true;//Collision

   return is_colliding;
}


