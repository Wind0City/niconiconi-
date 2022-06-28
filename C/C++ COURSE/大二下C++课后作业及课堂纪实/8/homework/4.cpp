//problem 8-4
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
        for (int i = 0; i < size; i++)
        {
            this->ptr[i] = a.ptr[i];
        }
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
class SortArray : virtual public Array
{
public:
    SortArray(int num) : Array(num)
    {
        isSort = false;
    }
    void Sort()
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i; j >= 1; j--)
            {
                if (ptr[j] < ptr[j - 1])
                {
                    int temp = ptr[j];
                    ptr[j] = ptr[j - 1];
                    ptr[j - 1] = temp;
                }
            }
        }
        isSort = true;
    }

private:
    bool isSort;
};
class AverArray : virtual public Array
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
class MyArray : public AverArray, public SortArray
{
public:
    MyArray(int num) : Array(num), AverArray(num), SortArray(num) {}
    MyArray(MyArray &a) : Array(a), AverArray(a), SortArray(a) {}
};
int main()
{
    MyArray integers1(7);
    integers1.input();
    cout << "Integers1:" << endl;
    cout << "Before sort:" << endl;
    integers1.display();
    cout << "After sort:" << endl;
    integers1.Sort();
    integers1.display();
    integers1.aver();
    cout << fixed << setprecision(2);
    cout << "The average number of integers1 is " << integers1.getAver() << endl;
    MyArray integers2(integers1);
    cout << "Integers2:" << endl;
    integers2.display();
    cout << "The average number of integers2 is " << integers2.getAver() << endl;
    return 0;
}