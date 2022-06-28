// Problem 4-5
#include <iostream>
#include <iomanip>
using namespace std;
#define N 101
class IntegerSet
{
private:
    bool x[N];

public:
    IntegerSet() //默认初始化构造
    {
        for (int i = 0; i < N; i++)
        {
            x[i] = false;
        }
    }
    IntegerSet(int *p, int length) //接收一个整型数组和该数组元素个数构造
    {
        for (int i = 0; i < N; i++)
        {
            x[i] = false;
        }
        for (int i = 0; i < length; i++)
        {
            if (p[i] < 0 || p[i] > 100)
            {
                cout << "Invalid insert attempted!\n";
                continue;
            }
            x[p[i]] = true;
        }
    }
    IntegerSet intersectionOfSets(IntegerSet a) //交集
    {
        for (int i = 0; i < N; i++)
        {
            if (this->x[i] == (a.x[i]) && (a.x[i]) == true)
            {
                a.x[i] = true;
            }
            else
            {
                a.x[i] = false;
            }
        }
        return a;
    }
    IntegerSet unionOfSets(IntegerSet a) //并集
    {
        for (int i = 0; i < N; i++)
        {
            if (this->x[i] || (a.x[i]))
            {
                a.x[i] = true;
            }
            else
            {
                a.x[i] = false;
            }
        }
        return a;
    }
    void inputSet() //输入
    {
        int num;
        while (1)
        {
            cin >> num;
            if (num == -1)
            {
                break;
            }
            if (num < 0 || num > 100)
            {
                cout << "Invalid Element\n";
                break;
            }
            x[num] = true;
        }
    }
    bool isEqualTo(IntegerSet &B) //判断两集合是否相等
    {
        for (int i = 0; i < N; i++)
        {
            if (this->x[i] != (B.x[i]))
            {
                return false;
            }
        }
        return true;
    }
    void insertElement(int num) //插入
    {
        if (num < 0 || num > 100)
        {
            cout << "Invalid Element\n";
            return;
        }
        x[num] = true;
    }
    void deleteElement(int num) //删除
    {
        if (num < 0 || num > 100)
        {
            return;
        }
        x[num] = false;
    }
    void printSet() //输出当前集合
    {
        for (int i = 0; i < N; i++)
        {
            if (x[i] == true)
            {
                cout << "{";
                for (int i = 0; i < N; i++)
                {
                    if (x[i])
                    {
                        cout << i << " ";
                    }
                }
                cout << "}\n";
                return;
            }
        }
        cout << setw(4) << "{---}";
        cout << endl;
    }
};
int main()
{
    IntegerSet a;
    IntegerSet b;
    IntegerSet c;
    IntegerSet d;
    //    cout << "Enter set A:\n";
    a.inputSet();
    //    cout << "\nEnter set B:\n
    b.inputSet();
    c = a.unionOfSets(b);
    d = a.intersectionOfSets(b);
    cout << "\nUnion of A and B is:\n";
    c.printSet();
    cout << "Intersection of A and B is:\n";
    d.printSet();
    return 0;
} // end main
