#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class Student
{
    friend bool operator<(const Student a, const Student b)
    {
        return a.getscore() < b.getscore();
    }
    friend bool operator==(const Student a, const Student b)
    {
        if (a.getid() == b.getid())
        {
            return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &out, const Student &a)
    {
        out << "id: " << a.getid() << " score" << a.getscore() << endl;
        return out;
    }

public:
    Student(string idc, double scored) : id(idc), score(scored) {}
    string getid() const { return id; }
    double getscore() const { return score; }

private:
    string id;
    double score;
};
vector<Student> mm;
/* template <class InputIt, class T>
InputIt find(InputIt first, InputIt last, const T &value)
{
    InputIt it;
    for (it = first; it != last; it++)
    {
        if (*it == value)
        {
            return it;
        }
    }
    return last;
} */
bool cmp(const Student a, const Student b)
{
    return a.getscore() > b.getscore() ? true : false;
}
void a(string idc, double score)
{
    mm.push_back(Student(idc, score));
}
void p()
{
    vector<Student>::iterator it;
    for (it = mm.begin(); it != mm.end(); it++)
    {
        cout << *it;
    }
}
void f(string id)
{
    vector<Student>::iterator it;
    it = find(mm.begin(), mm.end(), Student(id, 0));
    if (it == mm.end())
    {
        cout << "student" << id << "do not exists" << endl;
    }
    else
    {
        cout << *it;
    }
}
void s()
{
    sort(mm.begin(), mm.end(), less<Student>());
}
void d(string id)
{
    mm.erase(find(mm.begin(), mm.end(), Student(id, 0)));
}
void q()
{
    cout << "bye" << endl;
}
int main()
{
    cout << "a [id] [score] to add\nd[id] to delete f[id] to find\ns to sort\np to print\nq to quit " << endl;
    string choice;
    string idc;
    double score;
    while (1)
    {
        cout << "Enter your choice(q/a/d/f/s/p):";
        cin >> choice;
        if (choice == "a")
        {
            cout << "id:";
            cin >> idc;
            cout << "score:";
            cin >> score;
            a(idc, score);
            cout << idc << " added" << endl;
        }
        if (choice == "d")
        {
            cout << "id:";
            cin >> idc;
            d(idc);
            cout << idc << " deleted" << endl;
        }
        if (choice == "q")
        {
            q();
            break;
        }
        if (choice == "f")
        {
            cout << "id:";
            cin >> idc;
            f(idc);
        }
        if (choice == "s")
        {
            s();
            cout << "sort end!" << endl;
        }
        if (choice == "p")
        {
            vector<Student>::iterator it;
            for (it = mm.begin(); it != mm.end(); it++)
            {
                cout << *it;
            }
        }
    }
    return 0;
}