#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

class Thing
{
    public:
        virtual ~Thing()
        {
            printf("~Thing()\n");
        }

        virtual void to_name(std::string name) = 0;

        virtual void drow() = 0;
};

class Ellipse : public Thing
{
    protected:
        int x, y;
        int a, b;
        std::string name;

    public:
        Ellipse()
        {
            x = 0, y = 0;
            a = 0, b = 0;
        }

        Ellipse(int x, int y, int a, int b)
        {
            this->x = x;
            this->y = y;
            this->a = a;
            this->b = b;
        }

        Ellipse(const Ellipse &object)
        {
            x = object.x;
            y = object.y;
            a = object.a;
            b = object.b;
        }

        ~Ellipse() override
        {
        }

        double eccentricity()
        {
            return sqrt(1 - (b*b/a/a));
        }
};

int main()
{
    
    system("pause");
    return 0;
}