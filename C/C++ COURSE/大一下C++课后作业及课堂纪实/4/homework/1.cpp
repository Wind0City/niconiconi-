//Problem 4-1
#include <iostream>
using namespace std;
class Cargo
{
public:
    Cargo(int, int);
    void total();

private:
    int cartons;
    int items;
};
Cargo::Cargo(int it, int ca) : items(it), cartons(ca) {}
void Cargo::total()
{
    cout << "The total number of items is " << items * cartons << endl;
}
int main()
{
    Cargo *p = new Cargo[5]{Cargo(1, 10), Cargo(2, 20), Cargo(3, 30), Cargo(4, 40), Cargo(5, 50)};
    for (int i = 0; i < 5; i++)
    {
        (p + i)->total();
    }
    return 0;
}