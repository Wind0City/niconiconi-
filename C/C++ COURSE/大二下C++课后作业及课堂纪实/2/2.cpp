/*有关重载函数：
 *不能以返回值类型区分重载函数；
 *只要函数签名不同便可区分
 *形参的.类型.个数.顺序.必须有一个不同
 */
#include "2.h"
#include <iostream>
#include <string> //string所需要的头文件
using namespace std;

int add(int x = 5, int y = 5) // 带默认参数的函数
{
    return x + y;
}

/*带默认参数的函数
int add(int x,int y=5,int z=6)///right
int add(int x=5, int y,int z=6)///wrong
int add(int x=5,int y=6,int z)///wrong
即从右往左判断
*/
/*inline内联函数
  inline:函数前加inline可直接将程序中的函数引用替换为整个语句
*/
/*string
 *可当字符数组处理，即可以通过取下标进行操作
 *可以 通过加号连接
 *常用函数：//https://www.cplusplus.com/reference/string/basic_string/
 */

int main()
{

    {       //类的使用
       /*   
             point obj; //定义对象时。系统自动调用
             cout << "area:" << obj.area() << endl;
             cout << "length:" << obj.length() << endl;
      */
        point *p = new point; //创建一个对象，在堆里开辟一个对象需要的空间，也会自动调用
        p->setheight();
        p->setwidth();
        cout << "area:" << p->area() << endl;
        cout << "length:" << (*p).length() << endl;
        delete p;
    }

    cout << endl;

    { // 带默认参数的函数
        cout << add(10, 2) << endl;
        cout << add(5) << endl;
        cout << add() << endl;
    }

    cout << endl;

    { // string

        string s1 = "hello";
        string s2("world");
        string s3 = s1 + s2;
        cout << s1 << " " << s2 << " " << s3 << endl;

        string world;
        cout << "ctrl+z to stop" << endl;
        while (cin >> world) //反复读取到文件末尾,通过ctrl+z进行停止输入
            cout << world << endl;
        cout << "ctrl+z to stop" << endl;

        string str("some thing");
        for (auto c : str)    // auto标识自动识别类型，循环必须以数组类型形式
            cout << c << " "; //识别并单个输出
        cout << endl;
    }

    return 0;
}