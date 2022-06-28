#include <iostream>
#include <cstring>
#include <iomanip> //使用流操纵算子需要
#include <fstream>
using namespace std;
ostream &tab(ostream &outpurt) //用户自定义流操纵算子
{
    return outpurt << '\t';
}
int main()
{
    char x;
    char str[20];
    //输入流的成员函数
    x = cin.get();              //单独读入一个字符
    cin.get(str, 20, '\n');     //将20-1个字符读入str（指针类型），或者以'\n'结束
    cin.getline(str, 20, '\n'); //与上方一样
    cin.eof();                  //类似于C中的scanf("%d%d", &M, &N) == EOF，逻辑非可以用来做循环条件
    cin.peek();                 //返回的时当前输入流指针对应的字符，可以用来判断当前是不是空格，是不是特定的字符；
    cin.putback('j');           //相当于把一个字符放入当前输入流中
    cin.ignore(10, '\n');       //将当前流中10个字符删除，或者遇到换行符停止

    //固定字节的输入输出
    cin.read(str, 10);
    cout.write(str, cin.gcount());
    /*read是读入10-1个字节的字符，即使输入多的不会计入，write是输出10个字符*，gcount指放入流中的字符个数*/

    //整数流的基数：流操纵算子
    int n = 144;
    cout << hex << n << endl;         //十六进制
    cout << dec << n << endl;         //十进制
    cout << oct << n << endl;         //八进制
    cout << setbase(10) << n << endl; //十六进制

    //控制浮点数精度的流操纵算子
    double x = 1234567.89;
    //小数点后位数控制，保留太多会补0
    cout << setiosflags(ios::fixed) << setprecision(2); //第一种写法
    cout.setf(ios::fixed);
    cout << setprecision(2);          //第二种写法
    cout << fixed << setprecision(2); //第三种写法
    /*这三种都是一次使用，后面一直有效*/
    cout << resetiosflags(ios::fixed); //取消保留输出，即否定上面的所有

    //控制有效数字,保留的太多不会补0
    cout << setprecision(6) << x << endl; // setprecision(6)表示浮点数输出最多六位有效数字，如果小数点前的位数多于你要保留位数，则会使用科学计数法。

    //设置域宽的流操纵算子，即是占的字节数
    /*cin.width(5)==cin>>setw(5):每次只接收4个字符,其他的放在流中等待接收*/
    /*输入操作提取字符串的最大宽度比定义的域宽小1，这是因为在输入的字符串后面必须加上一个空字符。*/
    //设置域宽的都是一次性的，每次使用前都要设置

    //用户自定义流操纵算子使用：算子定义见函数
    cout << tab << x << endl;

    int a;
    char name[30];
    double balance;
    /*ascii文件以及二进制文件的操作*/
    //首先要定义文件流类队形，输出用ofstream，输入用ifstream，当然推荐fstrea一劳永逸
    fstream inclientfile("test.txt", ios::out);
    fstream files;
    files.open("test.txt", ios::out); //不同的方式，一样的操作
    /*名字随便定义，第一个参数为文件名，第二个参数为模式，如果是追加的话（大部分写应该都是追加），要用ios::app*/
    /*如果是二进制参数，必须是ios::binary*/
    //写入用 文件名<<写入内容（多种内容要用一个空格字符分开） 读用文件名>>内容名(每次是一行一行的进行操作)
    inclientfile << "hello";
    inclientfile >> name;
    //也可以用其他方法：
    inclientfile.read(name, 30);  //读文件，第一个参数为字符指针，第二个为其长度，
    inclientfile.write(name, 30); //参数意义没变
    //与文件指针有关的流成员函数
    inclientfile.tellg();             //返回输入文件指针当前位置
    inclientfile.tellp();             //返回输出文件指针当前位置
    inclientfile.seekg(10, ios::beg); //将输入文件中的指针移动到指定的位置
    inclientfile.seekg(10, ios::beg); //将输出文件中的指针移动到指定的位置58
    files.clear(std::ios::goodbit);
    files.seekg(std::ios::beg); //读取一次读取到文件末尾，因此此时的流状态时eof，需要将其设置为goodbit才能成功将文件指针移动到文件开头!!!!
    //两个seek函数，第一个参数是位移量，第二个参数是参照位置
    //参照位置有ios::beg(开始，默认值)ios::end(结束)ios::cur(当前位置)
    /*文件操作多实践*/
}