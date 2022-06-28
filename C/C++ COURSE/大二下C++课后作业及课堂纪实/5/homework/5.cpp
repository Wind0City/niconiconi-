// problem 5-5
#include <iostream>
using namespace std;
class Circle
{
    friend void display(Circle &a)
    {
        cout << a.x << " " << a.y << "  "
             << "r=" << a.radius << endl;
    }

    friend double area(Circle &a)
    {
        return a.radius * a.radius * 3.14;
    }

public:
    Circle(double x = 0, double y = 0, double r = 0) : x(x), y(y), radius(r)
    {
        num++;
    }
    ~Circle()
    {
        num--;
    }
    void setx(double x)
    {
        this->x = x;
    }
    void sety(double y)
    {
        this->y = y;
    }
    void setradius(double radius)
    {
        this->radius = radius;
    }
    static void showCount()
    {
        cout << "The number is " << num << endl;
    }

private:
    double x, y, radius;
    static int num;
};
int Circle::num = 0;
int main()
{
    Circle cir(4, 5, 7);
    display(cir);
    cout << area(cir);
    return 0;
}