#include <iostream>
#include <windows.h>
#include "Clicks.h"

using namespace std;

Clicks click;

int main(){
    cout << "Welcome to Autoclicker\nPress L-left click\nPress R-right\nPress X - Disable Autoclicker" << endl;
    
    while(true){
        if(GetAsyncKeyState('L'))
        {
            click.click ^= 1;
            click.type_click = 'L';
            Sleep(100);
        }
        else if(GetAsyncKeyState('R'))
        {
            click.click ^= 1;
            click.type_click = 'R';
            Sleep(100);
        }
        else if(GetAsyncKeyState('X'))
        {
            break;
        }
        
        if(click.click)
        {
            switch(click.type_click)
            {
                case 'L':
                    click.Left_Click();
                    break;
                case 'R':
                    click.Right_Click();
                    break;
                default:
                    break;
            }
        }

        Sleep(10);
    }
}