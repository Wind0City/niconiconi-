// 11-6
/*
new:string自带的find（）
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> str;
int t;
string cmd;
string detect(); //采用递归流程
int num(int p = 0);
void print_all(vector<string> hello, int t)
{
    for (int i = 0; i < t; i++)
    {
        cout << str[i] << endl;
    }
}
bool isNum(string str)
{
    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            ans++;
        }
    }
    return ans == str.size();
}

int num(string p) //将代表下标的字符串转化成数字下标
{
    int num;
    num = stoi(p);
    return num;
    /*另一种字符串转换成数字的方法
    atoi(char*)
    atoi(string.c_str)//对于string类型的字符串，需要调用c_str()函数转换为字符数组后才能作为参数转换
    */
}
string detect()
{
    cin >> cmd;
    if (cmd == "over")
    {
        return "";
    }
    else if (cmd == "add")
    {
        string a;
        string b;

        a = detect();
        b = detect();
        if (isNum(a) && isNum(b) && num(a) >= 0 && num(a) <= 99999 && num(b) >= 0 && num(b) <= 99999)
            return to_string(num(a) + num(b));
        else
            return a + b;
    }
    else if (cmd == "copy")
    {
        int xu, pos, len;
        xu = num(detect());
        pos = num(detect());
        len = num(detect());

        return str[xu - 1].substr(pos, len);
    }

    else if (cmd == "find")
    {
        string search;
        int xu;

        search = detect();
        xu = num(detect());
        if (str[xu - 1].find(search, 0) != string::npos)   //如果找不到，则返回值为string::npos,对于string，通过a.find(val)==string::npos来做判断是否查找成功
            return to_string(str[xu - 1].find(search, 0)); // find(string ,location)在特定位置开始查找
        else
            return to_string((int)search.length());
    }
    else if (cmd == "rfind")
    {
        string search;
        int xu;

        search = detect();
        xu = num(detect());
        if (str[xu - 1].rfind(search, str[xu - 1].length() - 1) != string::npos)
            return to_string(str[xu - 1].rfind(search, str[xu - 1].length() - 1));
        else
            return to_string((int)search.length());
    }

    else if (cmd == "print")
    {
        int xu;
        xu = num(detect());
        cout << str[xu - 1] << endl;
    }
    else if (cmd == "printall")
        print_all(str, t);

    else if (cmd == "insert")
    {
        string inserterr;
        int xu;
        int pos;

        inserterr = detect();
        xu = num(detect());
        pos = num(detect());
        str[xu - 1].insert(pos, inserterr);
    }
    else if (cmd == "reset")
    {
        string reseterr;
        int xu;
        reseterr = detect();
        xu = num(detect());
        str[xu - 1].assign(reseterr);
    }
    else
        return cmd;
    return "";
}

int main()
{
    cin >> t;
    string tmp;
    for (int i = 0; i < t; i++)
    {
        cin >> tmp;
        str.push_back(tmp);
    }
    while (cmd != "over")
    {
        detect();
    }
    return 0;
}
