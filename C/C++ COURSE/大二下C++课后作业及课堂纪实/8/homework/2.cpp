//problem 8-2
#include <iostream>
#include <iomanip>
using namespace std;
class Array
{
public:
    Array(int a) // default constructor
    {
        size = a;
        ptr = new int[a];
    }
    Array(const Array &a) // copy constructor
    {
        this->size = a.size;
        this->ptr = new int[a.size];
    }
    ~Array() // destructor
    {
        delete[] ptr;
    }
    void input() // input numbers
    {
        for (int i = 0; i < size; i++)
        {
            cin >> ptr[i];
        }
    }
    int getSize() const // return size
    {
        return size;
    }
    void display() const // display array
    {
        for (int i = 0; i < size; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

protected:
    int size; // pointer-based array size
    int *ptr; // pointer to first element of pointer-based array
};            // end class Array
class AverArray : public Array
{
public:
    AverArray(int size) : Array(size) {}
    void aver()
    {
        double ans = 0;
        for (int i = 0; i < size; i++)
        {
            ans += ptr[i];
        }
        ans = ans / size;
        average = ans;
        return;
    }
    double getAver()
    {
        return average;
    }

private:
    double average;
};
int main()
{
    AverArray integers1(7);
    integers1.input();
    cout << "Integers1:" << endl;
    integers1.display();
    integers1.aver();
    cout << fixed << setprecision(2);
    cout << "The average number of integers1 is " << integers1.getAver() << endl;
    return 0;
}
