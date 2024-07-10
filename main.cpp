#include <iostream>
#include <windows.h>
#include "Clicks.h"

using namespace std;
using namespace Clicks;

int main(){
    cout << "Welcome to Autoclicker\nPress L-left click\nPress R-right\nPress X - Disable Autoclicker" << endl;
    
    while(true){
        if(GetAsyncKeyState('L'))
        {
            click ^= 1;
            type_click = 'L';
            Sleep(100);
        }
        else if(GetAsyncKeyState('R'))
        {
            click ^= 1;
            type_click = 'R';
            Sleep(100);
        }
        else if(GetAsyncKeyState('X'))
        {
            break;
        }
        
        if(click)
        {
            switch(type_click)
            {
                case 'L':
                    Left_Click();
                    break;
                case 'R':
                    Right_Click();
                    break;
                default:
                    break;
            }
        }

        Sleep(10);
    }
}
