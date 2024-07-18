#include <string>

using namespace std;
#pragma once

string ZeroDel(string str_time)
{
    for(int i = str_time.size() - 1; i >= 0; --i)
    {
        if(str_time[i] != '0' && str_time[i] != '.')
        {
            break;
        }
        else
        {
            str_time.pop_back();
        }
    }
    return str_time;
}