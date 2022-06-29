#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct datas
{
    char num[10];
    char information[50];
};
int main()
{
    fstream filname("stock.txt", ios::in);
    datas un[30];
    for (int i = 0; i < 3; i++)
    {
        filname.read((char *)&un[i], sizeof(un[i]));
    }
    for (int i = 0; i < 3; i++)
    {
        cout << left << setw(10) << un[i].num << left << un[i].information << endl;
    }
    filname.close();
    return 0;
}