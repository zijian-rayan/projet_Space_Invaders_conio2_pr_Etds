/*!
 * \file Level.cpp
 * \brief Contains the Level class methods definitions
 * \author Cedric BERNEZ
 * \version 0.1
 */

#include "Level.h"
#include <iostream>
#include <conio2.h>

using namespace std;


Level::Level()
{
    // Default Constructor
    unsigned short i, j;

    // Default invader sprite
    Position ps(1,1);
    Speed sp(0,0);
    vector<char> line1 = {' ', '\'', '\'', ' '};
    vector<char> line2 = {'/', 'o', 'o', '\\'};
    vector<char> line3 = {' ', '\\', '/', ' '};
    vector< vector<char> > img = {line1, line2, line3};
    Sprite default_invader(LIGHTRED, ps, sp, img);

    // 4x3 invaders by default
    invaders_columns_nb = 4;
    invaders_rows_nb = 3;
    //Sprite** dinvader ;
    int x, y;
    for(j=0; j<invaders_rows_nb; j++)
    {
        for(i=0; i<invaders_columns_nb; i++)
        {
            x = 10 + i*(default_invader.getWidth() + 10);
            y = 1 + j*(default_invader.getHeight() + 2);
            default_invader.setPos(Position(x, y));
            invaders_vect.push_back(default_invader);
        }
    }
}


void Level::display()
{

    vector<Sprite>::iterator iti,itm;//Initialize iterator
    unsigned int i;
    unsigned int j;
    bool tag = 0;
    for(i=0, iti=invaders_vect.begin();  iti!=invaders_vect.end();)
    {
        for(j=0, itm=player_missiles_vect.begin(); itm!=player_missiles_vect.end();)
        {
            if(invaders_vect.at(i).isInCollisionWith(player_missiles_vect.at(j)))//Determine if there is a collision
            {
                invaders_vect.at(i).cleanoff();//Remove the intruder if the intruder is hit
                player_missiles_vect.at(j).cleanoff();
                //If the missile and the invader overlap, remove the missile (otherwise the invader will be penetrated by the missile and deleted)
                itm=player_missiles_vect.erase(itm);//Update the value of the iterator
                tag=true;
            }
            else
            {
                itm++;j++;//Read all invaders sequentially
            }
        }
        if(tag)
        {
            iti=invaders_vect.erase(iti);
            tag=false;
        }
        else
        {
            iti++;i++;
        }
    }
    for(i=0; i<invaders_vect.size(); i++)
    {
        invaders_vect.at(i).display();//Refresh invaders
        Speed s;
        s.setX(0);
        s.setY(1);
        invaders_vect.at(i).setSpd(s);//Set the speed of the invaders
        //invaders_vect.at(i).movey(0,35);
    }

    if(invaders_vect.empty()){//Judge if the player wins
        gotoxy(1, 20);
        cout<<endl<<endl;
        cout<<"****************************************"<<endl;
        cout<<"*             YOU WIN !!!              *"<<endl;
        cout<<"****************************************"<<endl<<endl;
    }

}




bool Level::actualize(Sprite &spr)
{
    bool actualized = false;

    // Complete the code
    unsigned int i;
    for(i=0;i<invaders_missiles_vect.size();i++)
        actualized=invaders_missiles_vect.at(i).isInCollisionWith(spr);//Determine if it is hit

    //actualized = true;
    return actualized;
}

void Level::refresh()//Refresh all missiles
{
    unsigned int i;
    vector<Sprite>:: iterator it;

    for(i=0; i<player_missiles_vect.size(); i++)//Clear the player's missile
        {
            player_missiles_vect.at(i).cleanoff();
        }

    for(it=player_missiles_vect.begin(),i=0;it!=player_missiles_vect.end(); )//The displacement of the player's missile
    {

        Speed s;
        s.setX(0);
        s.setY(-1);
        player_missiles_vect.at(i).setColor(WHITE);
        player_missiles_vect.at(i).setSpd(s);
        player_missiles_vect.at(i).movey(1,29);
        if(player_missiles_vect.at(i).getPos().getY()< 2)//Determine if the missile has reached the edge
            it=player_missiles_vect.erase(it);//Remove the missile at the edge
        else
           {
            player_missiles_vect.at(i).display();//Display the missiles
            it++;i++;
           }
    }

    for(i=0; i<invaders_missiles_vect.size(); i++)//Clear invader's missiles
        {
            invaders_missiles_vect.at(i).cleanoff();
        }

    for(it=invaders_missiles_vect.begin(),i=0;it!=invaders_missiles_vect.end(); )//Displacement of the intruder's missile
    {

        Speed s;
        s.setX(0);
        s.setY(1);
        invaders_missiles_vect.at(i).setColor(WHITE);
        invaders_missiles_vect.at(i).setSpd(s);
        invaders_missiles_vect.at(i).movey(1,29);
        if(invaders_missiles_vect.at(i).getPos().getY()>28)//Determine if the missile has reached the edge
            it=invaders_missiles_vect.erase(it);//Remove the missile at the edge
        else
           {
            invaders_missiles_vect.at(i).display();//Display the missiles
            it++;i++;
           }
    }

}
void Level::invader_fire(){//Invaders launch missiles
    int i;
    i=rand()%invaders_vect.size();
    Position posi(invaders_vect.at(i).getPos().getX()+2,invaders_vect.at(i).getPos().getY());
    //The missile is issued from the center of the intruder
    Speed sp(0,-1);//Missile speed
    vector<char> line1 = {'@'};//Missile shape
    vector< vector<char> > img = {line1};
    Sprite default_invaders_missile(LIGHTRED, posi, sp, img);
    invaders_missiles_vect.push_back(default_invaders_missile);
}
void Level::fire(Sprite &spr)//Player launches missile
{
    Position posi(spr.getPos().getX()+2,spr.getPos().getY());//The position at which the missile was fired
    Speed sp(0,0);//Initialize missile speed (change to the correct value in the refresh function)
    vector<char> missileimg = {'!'};//The shape of the player's missile
    vector< vector<char> > missileimag = {missileimg};
    Sprite default_player_missile(LIGHTBLUE, posi, sp, missileimag);
    player_missiles_vect.push_back(default_player_missile);
}
