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

        Location prev_loc;

        map<int,map<int,Location> > joint_map;

        int direction;
        // direction = 0 : up
        // direction = 1 : right
        // direction = 2 : down
        // direction = 3 : left

        int maxY, maxX;

        Snake(int maxX, int maxY)
        {
            this->maxX = maxX;
            this->maxY = maxY;

            direction = 0;
            int i = 4;
            int j = 4;
            prev_loc = Location(i,j);
            joint_q.push(prev_loc);

            map<int,Location> temp_map;
            if(joint_map.find(i)!=joint_map.end())
            {
                temp_map = joint_map[i];
            }

            temp_map[j] = prev_loc;
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

        void eat()
        {
            Location new_loc = Location(prev_loc);
            cout<<"new_loc.y old = "<<new_loc.y<<endl;
            if(direction == 0)
            {
                if(new_loc.y==0)
                    new_loc.y = maxY-1;
                else
                    new_loc.y--;
            }
            else if(direction == 1)
            {
                if(new_loc.x==maxX-1)
                    new_loc.x = 0;
                else
                    new_loc.x++;
            }
            else if(direction == 2)
            {
                if(new_loc.y==maxY-1)
                    new_loc.y = 0;
                else
                    new_loc.y++;
            }
            else if(direction == 3)
            {
                if(new_loc.x==0)
                    new_loc.x = maxX-1;
                else
                    new_loc.x--;
            }
            cout<<"new_loc = ["<<new_loc.x<<","<<new_loc.y<<"]"<<endl;

            //push new joint into queue
            joint_q.push(new_loc);

            prev_loc = new_loc;

            map<int,Location> temp_map;

            if(joint_map.find(new_loc.x) != joint_map.end())
            {
                temp_map = joint_map[new_loc.x];
            }

            temp_map[new_loc.y] = new_loc;

            joint_map[new_loc.x] = temp_map;
        }
        void update()
        {
            Location new_loc = Location(prev_loc);
            cout<<"new_loc.y old = "<<new_loc.y<<endl;
            if(direction == 0)
            {
                if(new_loc.y==0)
                    new_loc.y = maxY-1;
                else
                    new_loc.y--;
            }
            else if(direction == 1)
            {
                if(new_loc.x==maxX-1)
                    new_loc.x = 0;
                else
                    new_loc.x++;
            }
            else if(direction == 2)
            {
                if(new_loc.y==maxY-1)
                    new_loc.y = 0;
                else
                    new_loc.y++;
            }
            else if(direction == 3)
            {
                if(new_loc.x==0)
                    new_loc.x = maxX-1;
                else
                    new_loc.x--;
            }
            cout<<"new_loc = ["<<new_loc.x<<","<<new_loc.y<<"]"<<endl;

            //push new joint into queue
            joint_q.push(new_loc);

            prev_loc = new_loc;


            map<int,Location> temp_map;

            if(joint_map.find(new_loc.x) != joint_map.end())
            {
                temp_map = joint_map[new_loc.x];
            }
            else
            {
                temp_map = map<int,Location>();
            }

            temp_map[new_loc.y] = new_loc;

            joint_map[new_loc.x] = temp_map;



            //remove tail
            Location tail = joint_q.front();
            temp_map = joint_map[tail.x];
            cout<<"temp_map.size() = "<<temp_map.size()<<endl;
            temp_map.erase(tail.y);
            cout<<"after erase temp_map.size() = "<<temp_map.size()<<endl;

            if(temp_map.size()>0)
            {
                joint_map[tail.x] = temp_map;
            }
            else
            {
                joint_map.erase(tail.x);
            }

            //pop tail
            joint_q.pop();
            tail = joint_q.front();
            cout<<"after pop tail.x = "<<tail.x<<", tail.y = "<<tail.y<<endl;
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
    for(int j = 0 ; j < snake->maxX ; j++)
    {
        for(int k = 0 ; k < snake->maxY ; k++)
        {
            //cout<<"snake->hasLocation("<<j<<","<<k<<") = "<<snake->hasLocation(j,k)<<endl;
            if(snake->hasLocation(k,j))
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
} 

int main()
{

    Snake* snake = new Snake(10,10);

    for(int frame = 0 ; frame < 100 ; frame++)
    {
        if(frame == 3 || frame == 4 )
            snake->eat();
       
        if(frame == 8)
            snake->direction = 1;
 
        printSnake(snake);

        //after print, update snake
        snake->update();


        cout<<"joint_q.size() = "<<snake->joint_q.size()<<endl;
        usleep(1000000);

    }
    return 0;
}

