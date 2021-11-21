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

        int getVolume()
        {
            int volume = 0;

            for (int i = 0; i < size; i++)
                if (objects[i] != NULL)
                    volume++;
            
            return volume;
        }
};

void test_my_storage(int number)
{
    int t = clock();

    srand(time(NULL));

    My_storage s1(number);

    for (int i = 0; i < s1.getCount(); i++)
    {
        s1.setObject(i, new Ellipse(i, -i*2, i/5, i/10));
    }

    for (int i = 0; i < s1.getCount(); i++)
    {
        if (rand() % 2 == 0)
            s1.getObject(i).drow();
        else
            s1.getObject(i).to_name("Name");
    }

    printf("\n\nInitial size = %d\n", s1.getCount());

    s1.addObjects(s1.getCount(), new ColoredEllipse());

    printf("\n\nSize after adding ColoredEllipse = %d\n", s1.getCount());

    s1.nullObject(rand()%number);

    printf("Size after zeroing the object = %d\n", s1.getCount());

    printf("Number of non-empty objects = %d\n", s1.getVolume());

    s1.deleteObject((rand()*rand())%number);

    printf("Size after object deletion = %d\n", s1.getCount());

    printf("Number of non-empty objects = %d\n", s1.getVolume());

    printf("\n\nExecution time = %.5f sec\n", (double)t / (double)CLOCKS_PER_SEC);
}

int main()
{
    
    system("pause");
    return 0;
}