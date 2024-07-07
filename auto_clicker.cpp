#include <iostream>
#include <windows.h>

using namespace std;

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

int main(){
    cout << "Welcome to Autoclicker\nPress L-left click\nPress R-right\nPress X - Disable Autoclicker" << endl;
    
    bool click = false;
    char type_click = 'L';
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
