#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

int main() {
   int hour, minute, second;
   cout<<"enter hour: ";
   cin>>hour;  
   cout<<"enter minute: ";
    cin>>minute;
    cout<<"enter second: ";
    cin>>second;
    if(hour<0 || hour>23 || minute<0 || minute>59 || second<0 || second>59)
    {
        cout<<"Invalid time input!"<<endl;
        return 1;
    }
    while(true)
    {
        system("cls");
        cout<<hour<<":"<<minute<<":"<<second<<endl;
        Sleep(1000);
        second++;
        if(second==60)
        {
            second=0;
            minute++;
            if(minute==60)
            {
                minute=0;
                hour++;
                if(hour==24)
                {
                    hour=0;
                }
            }
        }
    }
   
    return 0;
}