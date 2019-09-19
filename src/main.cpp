/*!
 * \file main.cpp
 * \brief Contains the main function of the program
 * \author Cedric BERNEZ
 * \version 0.1
 */

#include <iostream>
#include <Game.h>
#include <windows.h>
#include <conio2.h>

using namespace std;


/**
 * \fn int main (void)
 * \brief Entry point of the program.
 *
 * \return 0 if exited cleanly.
 */
int main(void)
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};//Curseur cach¨¦
 	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//Curseur cach¨¦
    // Creates an instance of a Game
    Game myGame;
    // Start game
    myGame.run();


    textcolor(LIGHTGRAY);
    gotoxy(1, 26); // Put the text cursor at the end of screen
    return 0;
}
