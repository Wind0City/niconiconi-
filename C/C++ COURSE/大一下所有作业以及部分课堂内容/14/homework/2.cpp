//problem 2
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    char name1[30];
    char name2[30];
    cin.get(name1, 11, '.');
    cin >> name2;
    cout << name1 << endl
         << name2 << endl;
    cin.get();
    cin.get(name1, 11, '.');
    cin.ignore(1);
    cin >> name2;
    cout << name1 << endl
         << name2 << endl;
    return 0;
}