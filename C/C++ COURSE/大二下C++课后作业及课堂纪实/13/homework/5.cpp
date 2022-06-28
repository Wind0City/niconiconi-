//11-5
#include <iostream>
#include <exception>
using namespace std;
class TriExcpt : public runtime_error
{
public:
    TriExcpt(char *a) : runtime_error(a), messages(a) {}
    const char *what() const throw()
    {
        return messages;
    }

private:
    char *messages;
};
class SubTriRxcpt : public TriExcpt
{
public:
    SubTriRxcpt(char *a) : TriExcpt(a), messages(a) {}
    const char *what() const throw()
    {
        return messages;
    }

private:
    char *messages;
};
class triangle
{
public:
    triangle(int x = 0, int y = 0, int z = 0) : a(x), b(y), c(z)
    {
        judgement();
    }
    int perimeter()
    {
        return a + b + c;
    }
    void judgement()
    {
        if (a == 0 & b == 0 && c == 0)
        {
            flag = 3;
            throw runtime_error("All o inputted");
        }
        if (a + b == c || a + c == b || b + c == a)
        {
            flag = 1;
            throw TriExcpt("Not a normal triangle, a=b+c.");
        }
        if (a + b < c || a + c < b || c + b < a || a == 0 || b == 0 || c == 0)
        {
            flag = 2;
            throw SubTriRxcpt("Not a triangle, a>b+c");
        }
    }

private:
    int a, b, c;
    int flag;
};

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    try
    {
        triangle Tr1(a, b, c);
        cout << Tr1.perimeter() << endl;
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }
    return 1;
}