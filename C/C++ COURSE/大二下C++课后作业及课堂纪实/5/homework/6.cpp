#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Location
{
    friend double distanceBy(Location &a, Location &b)
    {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

public:
    Location(double x = 0, double y = 0) : x(x), y(y) {}
    void print()
    {
        cout << "(" << x << "," << y << ")";
    }
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
    double distance(Location &a)
    {
        return sqrt((a.x - this->x) * (a.x - this->x) + (a.y - this->y) * (a.y - this->y));
    }

private:
    double x, y;
};
int main()
{
    Location A(-10, -20), B(-40, 60);
    cout << "A";
    A.print();
    cout << ",B";
    B.print();
    cout << endl;
    cout << "Distance= " << A.distance(B) << endl;
    cout << "Distance= " << distanceBy(A, B) << endl;
    return 0;
}