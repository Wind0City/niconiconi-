// problem 8-5
#include <iostream>
using namespace std;
class PFArrayD
{
public:
    PFArrayD(int capacityValue)
    {
        a = new double[capacityValue];
        capacity = capacityValue;
        used = 0;
    }
    PFArrayD(const PFArrayD &pfaObject)
    {
        a = new double[pfaObject.capacity];
        capacity = pfaObject.capacity;
        used = pfaObject.used;
        for (int i = 0; i < used; i++)
        {
            a[i] = pfaObject.a[i];
        }
    }
    //函数功能：向数组中添加一个数据element。
    void addElement(double element)
    {
        a[used++] = element;
    }
    //函数功能：判断数组是否已满。如果满，返回真。
    bool full() const
    {
        if (used == capacity)
        {
            return true;
        }
        return false;
    }
    //函数功能：返回数组的大小
    int getCapacity() const
    {
        return capacity;
    }
    //函数功能：返回数组已使用元素的个数。
    int getNumberUsed() const
    {
        return used;
    }
    //函数功能：将已使用数组元素个数used设置为0，表示清空数组。
    void emptyArray()
    {
        used = 0;
    }
    //函数功能：返回数组中下标为index的数组元素
    double &element(int index)
    {
        int ans;
        for (int i = 0; i < used; i++)
        {
            if (i == index)
            {
                ans = i;
            }
        }
        return a[ans];
    }
    ~PFArrayD()
    {
        delete[] a;
    }

protected:
    double *a;    //数组的起始地址.
    int capacity; //数组大小.
    int used;     //数组中已使用的数组元素个数
};
class PFArrayDBak : public PFArrayD
{
public:
    PFArrayDBak(int num) : PFArrayD(num)
    {
        b = new double[num];
        usedB = 0;
    }
    void backup()
    {
        usedB = used;
        for (int i = 0; i < used; i++)
        {
            b[i] = a[i];
        }
    }
    void restore()
    {
        for (int i = 0; i < usedB; i++)
        {
            a[i] = b[i];
        }
        used = usedB;
    }

private:
    double *b;
    int usedB;
};
int main()
{
    int cap;
    cin >> cap;
    PFArrayDBak a(cap);
    double next;
    cin >> next;
    while ((next >= 0) && (!a.full()))
    {
        a.addElement(next);
        cin >> next;
    }
    if (next >= 0)
    {
        cout << "输入数据的个数超过了数组大小，无法读入所有数据.\n";
        while (next >= 0)
        {
            cin >> next;
        }
    }
    int count = a.getNumberUsed();
    cout << "读入并存储了  " << count << "  个数:\n";
    int index;
    for (index = 0; index < count; index++)
    {
        cout << a.element(index) << " ";
    }
    cout << endl;
    cout << "数组备份.\n";
    a.backup();
    cout << "清空数组.\n";
    a.emptyArray();
    cout << "数组中有  " << a.getNumberUsed() << "  个数.\n";
    cout << "恢复数组.\n";
    a.restore();
    count = a.getNumberUsed();
    cout << "数组存储了 " << count << "个数" << endl;
    for (index = 0; index < count; index++)
    {
        cout << a.element(index) << " ";
    }
    cout << endl;
    return 0;
}