#ifndef Location_HPP
#define Location_HPP
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
#endif
