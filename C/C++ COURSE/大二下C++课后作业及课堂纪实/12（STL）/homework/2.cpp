//11-2
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;
string greet(string from, string lastname, string title, int pos, int length)
{
    from = from.replace(from.find("Daisy"), 5, lastname);
    string temp(title.begin() + pos, title.begin() + pos + length);
    from = from.replace(from.find("Ms"), 2, temp);
    return from;
}
int main()
{
    string generic1("Dear Ms Daisy:");
    string generic2("MrsMrMissPeople");
    string lastName("Annap");
    string salute = greet(generic1, lastName, generic2, 5, 4);
    cout << salute;
    return 0;
}