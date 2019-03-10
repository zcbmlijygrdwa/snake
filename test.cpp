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
    for(int frame = 0 ; frame < 100 ; frame++)
    {

        Clrscr();
        s = "";
        for(int j = 0 ; j < 10 ; j++)
        {
            for(int k = 0 ; k < 10 ; k++)
            {
                if(j*10+k==frame)
                {
                    s += " ";
                }
                else
                {
                    s += "*";
                }
            }
        s+="\n"; 
        }
        cout<<s;
        usleep(100000);
    }
    return 0;
}

