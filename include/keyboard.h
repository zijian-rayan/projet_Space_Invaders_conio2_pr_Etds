#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

/*!
* \file keyboard.h
* \brief Contains keyboard constants and functions
* \author Cedric BERNEZ
* \version 0.1
*/


/**
* \enum KEYCODES
* \brief Keyboard keys constants declaration.
*/
enum KEYCODES {VK_NOKEYPRESSED, VK_ESCAPE, VK_SPACE, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN};


/*!
*  \brief Get the key code of the last pressed key
*
*  \return a mapped constant corresponding to the key pressed,
* VK_NOKEYPRESSED if no key was pressed
*/
int getKey();


#endif // KEYBOARD_H_INCLUDED
