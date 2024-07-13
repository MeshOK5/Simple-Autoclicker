#include <iostream>
#include <windows.h>
#include "Clicks.h"

using namespace std;
using namespace Clicks;

int main(){
    cout << logo << endl;
    cout << "\nWelcome to Autoclicker" << endl;
    Question();
    
    while(true){
        if(GetAsyncKeyState(button) & 0x8000)
        {
            click ^= 1;
            cout << "Autoclicker is " << click << endl;
            Sleep(100);
        }
        else if(GetAsyncKeyState('X') & 0x8000)
        {
            Question();
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
