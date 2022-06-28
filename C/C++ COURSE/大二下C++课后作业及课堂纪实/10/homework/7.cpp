//problem 10-7
#include <iostream>
using namespace std;

template <class T>
class AList
{
private:
    int maxSize;
    // Maximum size of list
    int listSize;
    // Actual number of elements in list
    T *listArray;
    // Array holding list elements
public:
    AList(int size)
    {
        maxSize = size;
        listArray = new T[size];
        listSize = 0;
    }
    ~AList()
    {
        delete[] listArray;
    }
    bool append(const T &item)
    {
        if (listSize >= maxSize)
            return false;
        listArray[listSize++] = item;
        return true;
    }
    bool insert(const T &item, int pos)
    {
        if (listSize == maxSize)
            return false;
        T temp = listArray[pos + 1];
        for (int i = listSize; i >= pos + 1; i--)
        {
            listArray[i] = listArray[i - 1];
        }
        listArray[pos] = item;
        listSize++;
        return true;
    }
    bool remove(T &item, int pos);
    void print() const
    {
        int pos = 0;
        while (pos < listSize)
            cout << listArray[pos++] << " ";
        cout << endl;
    }
};
template <class T>
bool AList<T>::remove(T &item, int pos)
{
    if (listSize == 0)
    {
        return false;
    }
    item = listArray[pos];
    for (int i = pos; i <= listSize - 2; i++)
    {
        listArray[i] = listArray[i + 1];
    }
    listSize--;
    return true;
}
int main()
{
    AList<int> listInt(8);
    int x, num;
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        listInt.append(x);
    }
    if (listInt.insert(4, 1))
        cout << "success" << endl;
    else
        cout << "fail" << endl;
    listInt.print();
    listInt.remove(num, 2);
    cout << "delete " << num << endl;
    listInt.print();

    AList<string> liststring(5);
    string s, temp;
    for (int i = 0; i < 5; i++)
    {
        cin >> s;
        liststring.append(s);
    }
    if (liststring.insert("hello", 3))
        cout << "success" << endl;
    else
        cout << "fail" << endl;
    liststring.print();
    liststring.remove(temp, 3);
    cout << "delete " << temp << endl;
    liststring.print();
}
