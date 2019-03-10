#ifndef snake_hpp
#define snake_hpp

#include <iostream>


#include <queue>
#include <map>

using namespace std;

class Snake
{
    public:
        queue<Location> joint_q;

        Location prev_loc;

        int size;

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

        }


        void eat()
        {
            Location new_loc = Location(prev_loc);
            cout<<"new_loc.y old = "<<new_loc.y<<endl;
            if(direction == 0)
            {
                if(new_loc.y<=0)
                    new_loc.y = maxY-1;
                else
                    new_loc.y -= size;
            }
            else if(direction == 1)
            {
                if(new_loc.x>=maxX-1)
                    new_loc.x = 0;
                else
                    new_loc.x += size;
            }
            else if(direction == 2)
            {
                if(new_loc.y>=maxY-1)
                    new_loc.y = 0;
                else
                    new_loc.y += size;
            }
            else if(direction == 3)
            {
                if(new_loc.x<=0)
                    new_loc.x = maxX-1;
                else
                    new_loc.x -= size;
            }
            cout<<"new_loc = ["<<new_loc.x<<","<<new_loc.y<<"]"<<endl;

            //push new joint into queue
            joint_q.push(new_loc);

            prev_loc = new_loc;
        }
        void update()
        {
            Location new_loc = Location(prev_loc);
            //cout<<"new_loc.y old = "<<new_loc.y<<endl;
            if(direction == 0)
            {
                if(new_loc.y<=0)
                    new_loc.y = maxY-1;
                else
                    new_loc.y -= size;
            }
            else if(direction == 1)
            {
                if(new_loc.x>=maxX-1)
                    new_loc.x = 0;
                else
                    new_loc.x += size;
            }
            else if(direction == 2)
            {
                if(new_loc.y>=maxY-1)
                    new_loc.y = 0;
                else
                    new_loc.y += size;
            }
            else if(direction == 3)
            {
                if(new_loc.x<=0)
                    new_loc.x = maxX-1;
                else
                    new_loc.x -= size;
            }
            //push new joint into queue
            joint_q.push(new_loc);

            prev_loc = new_loc;

            //pop tail
            joint_q.pop();
        }

};


#endif
