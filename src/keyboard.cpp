/*!
 * \file keyboard.cpp
 * \brief Contains the keyboard management functions definitions
 * \author Cedric BERNEZ
 * \version 0.1
 */

#include <keyboard.h>
#include <conio2.h>

// Return a mapped constant corresponding to the key pressed
// Returns None if no key pressed
int getKey()
{
    int key, retKeyCode;

    if (kbhit()) // A key was pressed
    {
        key = getch();
        retKeyCode = key; // Returns ASCII code by default
        // Special keys
        if(key==224)
        {
            key = getch();
            switch(key)
            {
            case 75:
                retKeyCode = VK_LEFT;
                break;
            case 72:
                retKeyCode = VK_UP;
                break;
            case 77:
                retKeyCode = VK_RIGHT;
                break;
            case 80:
                retKeyCode = VK_DOWN;
                break;
            default:
                break;
            }
        }
        else
        {
            switch(key)
            {
            case ' ':
                retKeyCode = VK_SPACE;
                break;
            case 27:
                retKeyCode = VK_ESCAPE;
                break;
            default:
                break;
            }
        }
    }
    else   // no key pressed since last call
    {
        retKeyCode = VK_NOKEYPRESSED;
    }

    return retKeyCode;
}
