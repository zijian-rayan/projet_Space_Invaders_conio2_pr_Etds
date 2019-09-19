/*!
 * \file Game.cpp
 * \brief Contains the Game class methods definitions
 * \author Cedric BERNEZ
 * \version 0.1
 */

#include "Game.h"
#include <iostream>
#include <conio2.h>
#include "keyboard.h"
#include "Coordinates_2D.h"
#include "Level.h"



using namespace std;


Game::Game()
{
    // Constructor
    cont = true;
}


Game::~Game()
{
    // Destructor
}


void Game::run()
{
//    int collision_type;
    bool has_moved;
    bool missile_ready=false;
    Speed s=(0,0);


    long long int refreshPeriod = 0;//refresh time
    long long int refreshPeriod2 = 0;//Judge the time of the attack
    long long int refreshPeriod3 = 0;//The refresh time of the missiles of the player
    long long int refreshPeriod4 = 0;//The refresh time of the missiles of the invaders
    int times = 0;
    // Temporary sprite for player move management and collisions detection
    Sprite spr_tmp;

    // No cursor must be visiblevoid Sprite::displayi(unsigned int i,unsigned int j)
    _setcursortype(_NOCURSOR);

    // Instantiate player spritevoid Sprite::displayi(unsigned int i,unsigned int j)
    vector<char> img_player = {'/', '-', '^', '-', '\\'};

    Sprite player(LIGHTBLUE, Position(35, 20), Speed(0,0), {img_player});

    // Instantiate level with default map
    Level test_lvl;
    // First display
    test_lvl.display();
    player.display();

    while(cont) // Game main loop
    {
        refreshPeriod++;
        refreshPeriod2++;
        refreshPeriod3++;
        Position p = player.getPos();
        if((refreshPeriod >= 1e7))  // Fix the interval between two moves of game sprites
        {
            refreshPeriod = 0;
            refreshPeriod4++;
            // Keyboard management
            if(kbhit())
            {
                has_moved = false;
                switch(getKey())
                {
                case VK_ESCAPE:
                    cont = false;
                case VK_LEFT:
                    // Complete the code
                    s.setX(-1);
                    s.setY(0);
                    player.setSpd(s);//Set the speed
                    has_moved=1;
                    player.cleanoff();//After the player moves, clear the player in the previous position
                    player.movex(2,10 + 4*14-7+1);//Displace to the left
                    break;
                case VK_RIGHT:
                    // Complete the code
                    s.setX(1);
                    s.setY(0);
                    player.setSpd(s);//Set the speed
                    has_moved=1;
                    player.cleanoff();//After the player moves, clear the player in the previous position
                    player.movex(1,10 + 4*14-7);//Displace to the right
                    break;
                case VK_UP:
                    // Complete the code
                    s.setX(0);
                    s.setY(-1);
                    player.setSpd(s);//Set the speed
                    has_moved=1;
                    player.cleanoff();//After the player moves, clear the player in the previous position
                    player.movey(14,14+15);//Upward displacement
                    break;
                case VK_DOWN:
                    // Complete the code
                    s.setX(0);
                    s.setY(1);
                    player.setSpd(s);//Set the speed
                    has_moved=1;
                    player.cleanoff();//After the player moves, clear the player in the previous position
                    player.movey(13,13+15);//Downward displacement
                    break;
                case VK_SPACE://Player launches missiles
                    //Sprite missile(WHITE,Position(s.getX(),s.getY()),Speed(0,-1),{missileimg});
                    //this-> missile =  Sprite(WHITE,Position(p.getX()+2,p.getY()-1),Speed(0,-1),{missileimg});
                    /*Position pp;
                    pp.setX(p.getX()+2);
                    pp.setY(p.getY()-1);
                    missile.setPos(pp);
                    missile.setSpd(0,-1);*/
                    //missile.display();
                    missile_ready=1;
                    break;

                }
            }
            // Player Animation
            if(has_moved)
            {
                // Complete the code
                player.display();//Display the position of the player

            }
            if(missile_ready)//Player launches missiles
            {

                test_lvl.fire(player);
                //for(int ii = 0;ii<30;ii++)
                //{
                    if(refreshPeriod2 >= 1e7)
                    {
                        //missile.display();
                       /* s.setX(0);
                        s.setY(-1);
                        missile.setSpd(s);
                        missile.cleanoff();
                        missile.movey(1,14+15);
                        missile.display();
                        if(missile.getPos().getY()==1)
                            missile.cleanoff();*/

                        test_lvl.display();
                    }

                        missile_ready=0;

                //}
                //missile.cleanoff();

            }
               if(refreshPeriod3>=1e4)//The displacement of the player's missiles
            {
                refreshPeriod3=0;
                test_lvl.refresh();//refresh
                test_lvl.display();//Display
            }

            if(refreshPeriod4>=10)//The displacement of the invaders' missiles
            {
                refreshPeriod4=0;
                test_lvl.invader_fire();
                test_lvl.refresh();
                test_lvl.display();
            }
            /*if(missile.isInCollisionWith(test_lvl.invaders_vect))
            {
                missile_ready=0;
                test_lvl.actualize();

            }*/
            if(test_lvl.invaders_vect.empty())//Judge if the player wins
                cont=false;//The game stops if the player wins

            // Level Animation and collisions detections
            if (test_lvl.actualize(player)) // An invader missile has shot the player
            {
                // Complete the code
                test_lvl.display();
                cout<<endl<<endl;
                cout<<"\t\t"<<"****************************************"<<endl;
                cout<<"\t\t"<<"*            Game Over !!!             *"<<endl;
                cout<<"\t\t"<<"****************************************"<<endl<<endl;
                cont = false;//The game stops if the player is shot
            }
        }
    }
}
