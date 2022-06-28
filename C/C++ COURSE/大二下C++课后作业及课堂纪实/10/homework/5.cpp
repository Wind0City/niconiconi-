//problem 10-5
#include <iostream>
using namespace std;
template <class T, int numberOfElements>
class Array
{
    friend ostream &operator<<(ostream &out, const Array<T, numberOfElements> &a)
    {
        int account = a.getSize();
        for (int i = 0; i < account; i++)
        {
            out << a.ptr[i] << " ";
        }
        out << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Array<T, numberOfElements> &a)
    {
        int account = a.getSize();
        for (int i = 0; i < account; i++)
        {
            in >> a.ptr[i];
        }
        return in;
    }

public:
    static int getArrayCount();
    Array();
    int getSize() const
    {
        return size;
    }
protected:
    T ptr[numberOfElements]; // ptr指向数组的起始位置
    int size;                // 数组大小，即为numberOfElements 
    static int arrayCount;//数组不需要析构函数
}; // end class Array

template <class T, int numberOfElements>
int Array<T, numberOfElements>::arrayCount = 0;

template <class T, int numberOfElements>
int Array<T, numberOfElements>::getArrayCount()
{
    return arrayCount;
}

template <class T, int numberOfElements>
Array<T, numberOfElements>::Array()
{
    this->size = numberOfElements;
    arrayCount++;
}
int main()
{
    // create intArray object
    Array<int, 5> intArray1;

    // initialize intArray with user input values
    cin >> intArray1;

    // create intArray object
    Array<int, 5> intArray2;

    // initialize intArray with user input values
    cin >> intArray2;

    // create floatArray
    Array<float, 5> floatArray;

    cin >> floatArray;

    // output intArray1
    cout << "\nIntArray1 contains " << intArray1.getSize() << " Elements.\n";
    cout << "The values in intArray are:\n";
    cout << intArray1;

    // output intArray2
    cout << "\nIntArray2 contains " << intArray2.getSize() << " Elements.\n";
    cout << "The values in intArray are:\n";
    cout << intArray2;

    // output floatArray
    cout << "\nDoubleArray contains " << floatArray.getSize() << " Elements.\n";
    cout << "The values in the doubleArray are:\n";
    cout << floatArray;

    cout << "\nThere are " << Array<int, 5>::getArrayCount() << " Array<int,5> objects.\n";
    cout << "\nThere are " << Array<float, 5>::getArrayCount() << " Array<float,5> objects.\n";

    return 0;

} // end main