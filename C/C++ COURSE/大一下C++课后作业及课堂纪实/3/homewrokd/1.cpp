//problem 3-1
#include <iostream>
#include <iomanip>
#define PI 3.1415926
using namespace std;
class Cylinder
{
private:
    double radius, height;

public:
    Cylinder(int x = 1, int y = 1) : radius(x), height(y) {}
    ~Cylinder()
    {
        printf("\nhello,baby!\n");
    }
    void setradius(double x)
    {
        radius = x;
    }
    double getradius()
    {
        return radius;
    }
    void setheight(double y)
    {
        height = y;
    }
    double getheight()
    {
        return height;
    }
    void volume()
    {
        double volume;
        volume = radius * radius * PI * height;
        cout << fixed << setprecision(2) << volume << endl;
    }
};
int main()
{
    double radius, height;
    //    cout<<"Please input the radius of cylinder:";
    cin >> radius;
    //    cout<<"Please input the height of cylinder:";
    cin >> height;
    Cylinder first(radius, height);
    first.volume();
    cout << "The volume of Cylinder with default data:" << endl;
    Cylinder second;
    second.volume();
    return 0;
}