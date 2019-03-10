#include <iostream>

#include <queue>
#include <map>

#include <unistd.h>

#include <simple2d.h>


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

        int size;

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

            size = 10;

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

Snake* snake = NULL;

void update() {

    queue<Location> temp_q = snake->joint_q;

    while(temp_q.size()>0)
    {
        Location loc = temp_q.front();
        temp_q.pop();
        cout<<"loc.x = "<<loc.x<<endl;
        cout<<"loc.y = "<<loc.y<<endl;

        S2D_DrawCircle(loc.x, loc.y, snake->size, 16,   1,   1,   1, 0.6);
    }

    snake->update();

    //S2D_DrawCircle(50, 50, 10, 16,   1,   1,   1, 0.6);
}

void render() {
}

int main(int iArgc, char** cppArgv)
{

    snake = new Snake(500,500);


    S2D_Diagnostics(true);

    S2D_Window *window;


    window = S2D_CreateWindow("Simple 2D — Test Card", 600, 500, update, render, S2D_RESIZABLE);


    S2D_Show(window);

    S2D_FreeWindow(window);

    return 0;
}

