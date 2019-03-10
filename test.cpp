#include <iostream>
#include <unistd.h>

using namespace std;


void Clrscr()
{
cout<<"\033[2J\033[1;1H";
}

int main()
{
    string s = "";

        for(int i = 0 ; i < 10 ; i++)
        {

            Clrscr();

            s = "[";
            s += to_string(i);
            s += "]";
            cout<<s<<endl;


            usleep(1000000);
        }
    return 0;
}

