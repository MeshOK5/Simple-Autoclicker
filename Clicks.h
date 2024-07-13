#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
#pragma once

namespace Clicks
{
    string logo = R"(
 __       __                      __         ______   __  __            __                           
|  \     /  \                    |  \       /      \ |  \|  \          |  \                          
| $$\   /  $$  ______    _______ | $$____  |  $$$$$$\| $$ \$$  _______ | $$   __   ______    ______  
| $$$\ /  $$$ /      \  /       \| $$    \ | $$   \$$| $$|  \ /       \| $$  /  \ /      \  /      \ 
| $$$$\  $$$$|  $$$$$$\|  $$$$$$$| $$$$$$$\| $$      | $$| $$|  $$$$$$$| $$_/  $$|  $$$$$$\|  $$$$$$\
| $$\$$ $$ $$| $$    $$ \$$    \ | $$  | $$| $$   __ | $$| $$| $$      | $$   $$ | $$    $$| $$   \$$
| $$ \$$$| $$| $$$$$$$$ _\$$$$$$\| $$  | $$| $$__/  \| $$| $$| $$_____ | $$$$$$\ | $$$$$$$$| $$      
| $$  \$ | $$ \$$     \|       $$| $$  | $$ \$$    $$| $$| $$ \$$     \| $$  \$$\ \$$     \| $$      
 \$$      \$$  \$$$$$$$ \$$$$$$$  \$$   \$$  \$$$$$$  \$$ \$$  \$$$$$$$ \$$   \$$  \$$$$$$$ \$$  )";
    bool click = false;
    char type_click;
    int button;

    void Question()
    {
        button = 'X';

        while(button == 'X')
        {
            cout << "Key to on/off autocliker is" << endl;
            button = toupper(getch());
        }

        cout << (char)button << endl;
        
        while(true)
        {
            cout << "Type L-LMB autoclicker or R-RMB autoclicker" << endl;
            cin >> type_click;
            type_click = (char)toupper(type_click);
            if(type_click == 'L' || type_click == 'R')
            {
                break;
            }
        }
        cout << "Press X to change setings" << endl;
    }

    void Left_Click()
    {
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    }

    void Right_Click()
    {
        mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
    }
}