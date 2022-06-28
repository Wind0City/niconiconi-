/*
类型转换：
隐式转换类型与显式转换类型：类型名（数据）
隐式转换，不做操作，例如int i=5，i=i+1.5；使用关键字explict后会出错
显式转换：类中定义的转换构造，和构造一个道理；
类型转换函数：必须是类中成员函数
例子：operator (转换目标类型int等) (){code}
等号可看成构造函数，
*/

/*
3 ways:public,private,protected
class son  : way father1,way father2....
{
    code
    
}
*/
/*
shunxu:1.对基类数据成员初始化；2.对子对象数据成员初始化；3.对派生类数据成员初始化。
*/
#include <iostream>
using namespace std;
enum{something = 15};//常数的一种定义方式
int main()
{

}