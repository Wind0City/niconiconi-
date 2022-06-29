//problem 5-2
#include <iostream>
using namespace std;
class Circle
{
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
    void display()
    {
        cout << x << " " << y << "  "
             << "r=" << radius << endl;
    }
    double setarea()
    {
        return radius * radius * 3.14;
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
    Circle::showCount();
    Circle r1;
    r1.display();
    {
        Circle r2(3, 4, 5);
        r2.display();
        Circle::showCount();
    }
    r1.showCount();
    return 0;
}