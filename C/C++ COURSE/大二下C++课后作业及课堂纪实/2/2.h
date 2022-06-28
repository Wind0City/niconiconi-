#include <iostream>
using namespace std;
//定义 类：
class point //给定长宽，求面积周长
{
public: //函数定义在此中看作内联函数
    //定义构造函数，和类名字相同，没有函数类型(默认参数)
    /*point(double ww = 1, double hh = 2)
    {
        w = ww;
        h = hh;
        print();
        cout << "constructed function used";
    }*/

    double area() const //内部定义
    {
        return w * h;
    }

    double length() const
    {
        return w + w + h + h;
    }
    void setwidth()
    {
        cout << "input width:";
        cin >> w;
        if (w <= 0)
        {
            w = 1;
        }
    }
    void setheight()
    {
        cout << "input height:";
        cin >> h;
        if (h <= 0)
            {
                h=1;
            }
    }
private: //私有访问
    double w, h;
    /*void print()
    {
        printf("hello world!\n");
    }
    */
};
