//problem 3
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void file_read_dosomething(char *filename);
int main()
{
    file_read_dosomething("data.txt");
    return 0;
}
void file_read_dosomething(char *filename)
{
    fstream files(filename, ios::in);
    if (!files)
    {
        cerr << "erroe" << endl;
        exit(1);
    }
    int ans1 = 0, ans2 = 0;
    char ch;
    char words[30];
    while (files.get(ch))
    {
        if (ch == '\n')
        {
            ans2++;
        }
    }
    files.clear(std::ios::goodbit);
    files.seekg(std::ios::beg);
    while (files >> words)
    {
        ans1++;
    }
    cout << ans1 << endl
         << ans2 + 1 << endl;
    files.close();
}