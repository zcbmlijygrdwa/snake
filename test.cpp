#include <iostream>

#include <queue>
#include <map>

#include <unistd.h>

using namespace std;



class Location
{
    public:
        int x;
        int y;
        Location()
        {
            x = 0;
            y = 0;
        }

        Location(int a, int b)
        {
            x = a;
            y = b;
        }
};



class Snake
{
    public:
        queue<Location> joint_q;

        map<int,map<int,Location> > joint_map;

        int direction;
        // direction = 0 : up
        // direction = 1 : right
        // direction = 2 : down
        // direction = 3 : left

        Snake()
        {
            direction = 0;
            int i = 4;
            int j = 4;
            Location loc = Location(i,j);
            joint_q.push(loc);

            map<int,Location> temp_map;
            if(joint_map.find(i)!=joint_map.end())
            {
                temp_map = joint_map[i];
            }

            temp_map[j] = loc;
            joint_map[i] = temp_map;
        }



        bool hasLocation(int i, int j)
        {
            if(joint_map.find(i)!=joint_map.end())
            {
                map<int,Location> temp_map = joint_map[i];
                if(temp_map.find(j) != temp_map.end())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }


};


void Clrscr()
{
    cout<<"\033[2J\033[1;1H";
}



void printSnake(Snake* snake)
{
    Clrscr();
    string s = "";
    s = "";
    for(int j = 0 ; j < 10 ; j++)
    {
        for(int k = 0 ; k < 10 ; k++)
        {
            //cout<<"snake->hasLocation("<<j<<","<<k<<") = "<<snake->hasLocation(j,k)<<endl;
            if(snake->hasLocation(j,k))
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

int main()
{

    Snake* snake = new Snake();

    for(int frame = 0 ; frame < 100 ; frame++)
    {
        printSnake(snake);
    }
    return 0;
}

