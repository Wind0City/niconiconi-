#include <iostream>
#include <fstream>
using namespace std;
struct datas
{
    char num[10];
    char information[50];
};
int main()
{
    datas un[3] = {"000001", "Shen_fa_zhan", "600104", "Shang_hai_qi_che", "000096", "Guang_ju_neng_yuan"};
    fstream filename("stock.txt", ios::out);
    if (!filename)
    {
        cerr << "error" << endl;
        exit(1);
    }
    for (int i = 0; i < 3; i++)
    {
        filename.write((char *)&un[i], sizeof(un[i]));
    }
    filename.close();
    return 0;
}