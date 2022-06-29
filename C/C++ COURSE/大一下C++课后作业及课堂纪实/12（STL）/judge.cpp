#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
#include <string>
using namespace std;
vector<string> a;
class judge
{
public:
    string operator()(const string &s1, const string &s2)
    {
        return "hello";
    }
} judg;
int num(string p)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == p)
        {
            return i;
        }
    }
    return -1;
}

int main()
{ /*
     int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     vector<int> a(b, b + 10);
     vector<int> c(b, b + 5);
     vector<int>::iterator it;
     for (it = a.begin(); it != a.end(); it++)
     {
         cout << *it << " ";
     }
     cout << endl;
     a.clear();
     cout << a.size() << endl;

     for (it = c.begin(); it != c.end(); it++)
     {
         cout << *it << " ";
     }
     cout << endl;
     cout << c.size() << endl;

     a.assign(4, 2);
     for (it = a.begin(); it != a.end(); it++)
     {
         cout << *it << " ";
     }
     cout << endl;
     cout << a.size() << endl;

     cout << endl;
     c.insert(c.begin() + 1, 3, 5);
     for (it = c.begin(); it != c.end(); it++)
     {
         cout << *it << " ";
     }
     cout << endl;
     a.swap(c);
     for (it = a.begin(); it != a.end(); it++)
     {
         cout << *it << " ";
     }
     cout << endl;
     for (it = c.begin(); it != c.end(); it++)
     {
         cout << *it << " ";
     }
     cout << endl;
     cout << a.capacity();
     */
    /*
    list<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.push_back(i + 1);
    }
    vector<int> a(l.begin(), l.end());
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, "|"));
    cout << endl;
*/

    /* string str = "he is@ a@ good boy";
     string substr = "12345";
     str = str.replace(str.find("is"), 5, substr, substr.find("1")+1, 6); //用substr的指定字符串替换str指定字符串
     cout << str << endl;
     return 0;*/
    char f[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    cout << atoi(f) << endl;
}