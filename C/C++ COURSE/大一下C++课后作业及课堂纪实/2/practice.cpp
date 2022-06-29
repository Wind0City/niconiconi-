#include <iostream>
using namespace std;
class practice
{
private:
    double w, h;

public:
    void set()
    {
        cout << "inputh width and length:";
        cin >> w >> h;
    }
    double size() const
    {
        return w * h;
    }
    double length() const
    {
        return w + w + h + h;
    }
};
int main()
{
    practice *p = new practice;
    p->set();
    cout << "size:" << p->size() << endl;
    cout << "length:" << p->length() << endl;
    delete p;
    return 0;
}
