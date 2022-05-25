// 11-4
#include <map>
#include <iostream>
#include <list>
#include <set>
#include <algorithm>
using namespace std;
int x[10000] = {0};
list<int> k(x, x + 1000);
int main()
{
    int n;
    map<int, list<int>> a;
    cin >> n;
    getchar();
    while (n--)
    {
        int id;
        string choice0;
        cin >> choice0 >> id;
        string choice(choice0.begin(), choice0.begin() + 3);
        if (choice == "new")
        {
            a.insert(make_pair(id, 0));
        }
        if (choice == "add")
        {
            int num;
            cin >> num;
            a[id].push_back(num);
        }
        if (choice == "mer")
        {
            int id2;
            cin >> id2;
            a[id].insert(a[id].end(), a[id2].begin(), a[id2].end());
            a[id2].clear();
        }
        if (choice == "uni")
        {
            list<int>::iterator it;
            it = unique(a[id].begin(), a[id].end());
            a[id].erase(it, a[id].end());
        }
        if (choice == "out")
        {
            a[id].sort();
            for (list<int>::iterator it = a[id].begin(); it != a[id].end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}