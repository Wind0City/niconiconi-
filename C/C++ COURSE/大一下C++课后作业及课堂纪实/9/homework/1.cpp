//problem 9-1
#include <iostream>
using namespace std;
#define Pi 3.141592
class Shape
{
    friend ostream &operator<<(ostream &out, Shape &a)
    {
        a.output();
        return out;
    }

public:
    Shape(float xd = 0, float yd = 0) : x(xd), y(yd) {}
    virtual void output() {}

protected:
    float x, y;
};
class TwoDimensionalShape : public Shape
{
public:
    TwoDimensionalShape(float xd = 0, float yd = 0) : Shape(xd, yd) {}
    float getArea()
    {
        return area;
    }

protected:
    float area;
};
class ThreeDimensionalShape : public Shape
{
public:
    ThreeDimensionalShape(float xd = 0, float yd = 0) : Shape(xd, yd) {}
    float getArea()
    {
        return area;
    }
    float getVolume()
    {
        return volume;
    }

protected:
    float area;
    float volume;
};
class Circle : public TwoDimensionalShape
{
public:
    Circle(float r = 0, float xd = 0, float yd = 0) : TwoDimensionalShape(xd, yd), radius(r)
    {
        area = Pi * radius * radius;
    }
    void output()
    {
        cout << "Circle with radius " << radius << ":"
             << "center at (" << x << "," << y << ")\n";
    }

private:
    float radius;
};
class Square : public TwoDimensionalShape
{

public:
    Square(float sl, float xd, float yd) : TwoDimensionalShape(xd, yd), side_length(sl)
    {
        area = sl * sl;
    }
    void output()
    {
        cout << "Square with side length " << side_length << ":"
             << "center at (" << x << "," << y << ")\n";
    }

private:
    float side_length;
};
class Cube : public ThreeDimensionalShape
{

public:
    Cube(float sl = 0, float xd = 0, float yd = 0) : ThreeDimensionalShape(xd, yd), side_length(sl)
    {
        area = side_length * side_length * 6;
        volume = side_length * side_length * side_length;
    }
    void output()
    {
        cout << "Cube with side length " << side_length << ":"
             << "center at (" << x << "," << y << ")\n";
    }

private:
    float side_length;
};
class Sphere : public ThreeDimensionalShape
{

public:
    Sphere(float r = 0, float xd = 0, float yd = 0) : ThreeDimensionalShape(xd, yd), radius(r)
    {
        area = 4 * Pi * radius * radius;
        volume = Pi * radius * radius * radius * (4.0f / 3.0f);
    }
    void output()
    {
        cout << "Sphere with radius " << radius << ":"
             << "center at (" << x << "," << y << ")\n";
    }

private:
    float radius;
};
int main()
{
    Shape *shapes[4];
    // initialize vector with Shapes
    shapes[0] = new Circle(3.5, 6, 9);
    shapes[1] = new Square(12, 2, 2);
    shapes[2] = new Sphere(5, 1.5, 4.5);
    shapes[3] = new Cube(2.2);
    // output Shape objects and display area and volume as appropriate
    for (int i = 0; i < 4; i++)
    {
        cout << *(shapes[i]) << endl;
        // downcast pointer
        TwoDimensionalShape *twoDimensionalShapePtr = dynamic_cast<TwoDimensionalShape *>(shapes[i]);
        // if Shape is a TwoDimensionalShape, dis-play its area
        if (twoDimensionalShapePtr != 0)
            cout << "Area: " << twoDimensionalShapePtr->getArea() << endl;
        // downcast pointer
        ThreeDimensionalShape *threeDimensionalShapePtr = dynamic_cast<ThreeDimensionalShape *>(shapes[i]);
        // if Shape is a ThreeDimensionalShape, display its area and volume
        if (threeDimensionalShapePtr != 0)
            cout << "Area: " << threeDimensionalShapePtr->getArea() << "\nVolume: " << threeDimensionalShapePtr->getVolume() << endl;
        cout << endl;
    } // end for
    return 0;
} // end main