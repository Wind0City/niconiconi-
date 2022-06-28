// problem 7-1
#include <iostream>
using namespace std;
class PartFilledArray
{
    friend ostream &operator<<(ostream &out, PartFilledArray &p);

public:
    PartFilledArray(int array_size);
    PartFilledArray(const PartFilledArray &object);
    ~PartFilledArray();
    void addValue(double newentry);

protected:
    double *a;
    int max_number;
    int number_used;
};
ostream &operator<<(ostream &out, PartFilledArray &p)
{
    for (int i = 0; i < p.number_used; i++)
    {
        out << p.a[i] << " ";
    }
    out << endl;
    return out;
}
PartFilledArray::PartFilledArray(int array_size)
{
    max_number = array_size;
    number_used = 0;
    a = new double[max_number];
}
PartFilledArray::PartFilledArray(const PartFilledArray &object)
{
    this->max_number = object.max_number;
    this->a = new double[object.max_number];
    this->number_used = object.number_used;
    for (int i = 0; i < object.number_used; i++)
    {
        this->a[i] = object.a[i];
    }
}
PartFilledArray::~PartFilledArray()
{
    delete[] a;
}
void PartFilledArray::addValue(double newntry)
{
    if (number_used >= max_number)
    {
        cout << "Adding to a full array." << endl;
        exit(1);
    }
    a[number_used++] = newntry;
}
int main()
{
    PartFilledArray a(7);
    double x;
    cin >> x;
    while (x != 0)
    {
        a.addValue(x);
        cin >> x;
    }
    cout << a;
    PartFilledArray b(a);
    cout << b;
}
