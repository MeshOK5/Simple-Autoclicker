#include <iostream>
#include <windows.h>

using namespace std;

void Click()
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

int main(){
    cout << "Welcome to Autoclicker\nZ - Start/Stop click\nX - Disable Autoclicker" << endl;
    
    bool click = false;
    while(true){
        if(GetAsyncKeyState('Z'))
        {
            switch (click)
            {
            case 1:
                click = 0;
                break;
            case 0:
                click = 1;
                break;

            default:
                break;
            }
            Sleep(100);
        }
        else if(GetAsyncKeyState('X'))
        {
            break;
        }
        
        if(click)
        {
            Click();
        }

        Sleep(10);
    }
}