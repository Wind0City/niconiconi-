#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
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
    int choice;
    while (1)
    {
        cout << "请输入你的选择 1or2" << endl;
        cin >> choice;
        if (choice == 2)
        {
            break;
        }
        if (choice == 1)
        {
            cout << "请输入股票好" << endl;
            char choice2[10];
            cin >> choice2;
            for (int i = 0; i < 3; i++)
            {
                if (strcmp(un[i].num, choice2) == 0)
                {
                    cout << un[i].information << endl;
                }
            }
        }
    }
    return 0;
}