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

int main()
{
    
    system("pause");
    return 0;
}