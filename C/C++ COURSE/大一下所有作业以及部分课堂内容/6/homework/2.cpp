// Problem 6-2
#include <iostream>
#include <iomanip>
using namespace std;
#define N 101
class IntegerSet
{
    friend IntegerSet operator+(const IntegerSet &a, const IntegerSet &b)
    {
        IntegerSet temp;
        for (int i = 0; i < N; i++)
        {
            if (a.x[i] || (b.x[i]))
            {
                temp.x[i] = true;
            }
            else
            {
                temp.x[i] = false;
            }
        }
        return temp;
    }
    friend ostream &operator<<(ostream &out, const IntegerSet &a)
    {
        int j = 5;
        for (int i = 0; i < N; i++)
        {
            if (a.x[i])
            {
                for (int m = 0; i < N; i++)
                {
                    if (a.x[i] == true)
                    {
                        out << setw(5) << i;
                        j--;
                    }
                    if (j == 0)
                    {
                        out << "\n";
                        j = 5;
                    }
                }
                return out;
            }
        }
        out << "null";
        return out;
    }
    friend istream &operator>>(istream &input, IntegerSet &a)
    {
        int num;
        while (1)
        {
            input >> num;
            if (num == -1)
            {
                break;
            }
            if (num < 0 || num > 100)
            {
                cout << "Invalid Element\n";
                break;
            }
            a.x[num] = true;
        }
        return input;
    }

public:
    IntegerSet() //默认初始化构造
    {
        for (int i = 0; i < N; i++)
        {
            x[i] = false;
        }
    }

private:
    bool x[N];
};
int main()
{
    IntegerSet set1, set2, set3;
    cin >> set1;
    cin >> set2;
    cout << "set1:" << endl
         << set1 << endl;
    cout << "set2:" << endl
         << set2 << endl;
    cout << "set3:" << endl
         << set3;
    set3 = set1 + set2;
    cout << "\nafter set1+set2 ,set3:\n"
         << set3 << endl;
    return 0;
}