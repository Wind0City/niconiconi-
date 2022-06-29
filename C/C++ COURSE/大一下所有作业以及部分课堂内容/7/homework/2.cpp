// problem 7-2
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
class PartFilledArrayWMax : public PartFilledArray
{
    friend ostream &operator<<(ostream &out, PartFilledArrayWMax &p);

public:
    PartFilledArrayWMax(int array_size);
    PartFilledArrayWMax(const PartFilledArrayWMax &object);
    ~PartFilledArrayWMax();
    void addValue(double newentry);
    double getMax();

private:
    double max_value;
};
ostream &operator<<(ostream &out, PartFilledArrayWMax &p)
{
    for (int i = 0; i < p.number_used; i++)
    {
        out << p.a[i] << " ";
    }
    out << endl;
    return out;
}
PartFilledArrayWMax::PartFilledArrayWMax(int array_size) : PartFilledArray(array_size) {}
PartFilledArrayWMax::PartFilledArrayWMax(const PartFilledArrayWMax &object) : PartFilledArray(object.max_number)
{
    this->number_used = object.number_used;
    this->a = new double[object.max_number];
    int max = object.a[0];
    for (int i = 0; i < this->number_used; i++)
    {
        this->a[i] = object.a[i];
    }
    this->max_value = object.max_value;
}
PartFilledArrayWMax::~PartFilledArrayWMax()
{
    delete[] a;
}
void PartFilledArrayWMax::addValue(double newentry)
{
    if (number_used >= max_number)
    {
        cout << "Adding to a full array." << endl;
        exit(1);
    }
    a[number_used++] = newentry;
    if (number_used == 1)
    {
        max_value = newentry;
    }
    else
    {
        if (newentry > max_value)
        {
            max_value = newentry;
        }
    }
}
double PartFilledArrayWMax::getMax()
{
    return max_value;
}
int main()
{
    PartFilledArrayWMax a(7);
    double x;
    cin >> x;
    while (x != 0)
    {
        a.addValue(x);
        cin >> x;
    }
    cout << a;
    cout << a.getMax() << endl;
    PartFilledArrayWMax b(a);
    cout << b;
    cout << b.getMax() << endl;
}
