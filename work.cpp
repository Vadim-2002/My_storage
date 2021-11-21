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

        void to_name(std::string name) override
        {
            printf("to_name() ");
        }

        void drow() override
        {
            printf("drow() ");
        }
};

class ColoredEllipse: public Ellipse
{
    protected:
        int color;

    public:
        ColoredEllipse() : Ellipse()
        {
        
            color = 0;
        }

        ColoredEllipse(int x, int y, int a, int b, int color) : Ellipse(x, y, a, b)
        {
            this->color = color;
        }

        ColoredEllipse(const ColoredEllipse &object)
        {
            x = object.x;
            y = object.y;
            a = object.a;
            b = object.b;
            color = object.color;
        }

        ~ColoredEllipse()
        {
        }

        void change_color(int new_color)
        {
            color = new_color;
        }
};

class My_storage
{
    private:
        Thing** objects;
        int size;

    public:
        My_storage(int size)
        {
            this->size = size;
            objects = new Thing* [size];
        }

        ~My_storage()
        {
            delete[] objects;
            printf("delete\n");
        }

        void setObject(int i, Thing* object)
        {
            objects[i] = object;
        }

        int getCount()
        {
            return size;
        }

        Thing& getObject(int i)
        {
            return *objects[i];
        }

        void nullObject(int i)
        {
            objects[i] = NULL;
        }

        void deleteObject(int index)
        {
            size--;

            Thing** new_objects = new Thing* [size];

            for (int i = 0; i < index; i++)
            {
                new_objects[i] = objects[i];
            }

            for (int i = index; i < size; i++)
            {
                new_objects[i] = objects[i + 1];
            }
            
            delete[] objects;

            objects = new_objects;
        }

        void addObjects(int index, Thing* object)
        {
            size = index + 1;
            Thing** new_objects = new Thing* [size];

            for (int i = 0; i < index; i++)
                new_objects[i] = objects[i];
            
            delete[] objects;

            objects = new_objects;

            objects[index] = object;
        }
};

int main()
{
    
    system("pause");
    return 0;
}