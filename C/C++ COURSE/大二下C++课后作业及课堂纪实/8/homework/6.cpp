//problem 8-6
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Person
{
public:
    Person(string name, int age, char gender, string id)
    {
        this->name = name;
        this->age = age;
        this->id = id;
        this->gender = gender;
    }
    Person(Person &a)
    {
        this->name = a.name;
        this->age = a.age;
        this->id = a.id;
        this->gender = a.gender;
    }

protected:
    string name;
    int age;
    char gender;
    string id;
};
class Doctor : public Person
{
public:
    Doctor(string name, int age, char gender, string id, string field, double cost) : Person(name, age, gender, id)
    {
        this->field = field;
        this->cfa = cost;
    }
    Doctor(Doctor &a) : Person(a)
    {
        this->field = a.field;
        this->cfa = a.cfa;
    }
    void show()
    {
        cout << "** Docter:\n";
        cout << "Name:" << name << " Age:" << age << " Gender:" << gender << "Id:" << id << endl;
        cout << "Specialty:" << field << " VisitFee:" << cfa << endl;
    }
    double getcfa()
    {
        return cfa;
    }

protected:
    string field;
    double cfa;
};
class Patient : public Person
{
public:
    Patient(string name, int age, char gender, string id, double costm, Doctor &a) : Person(name, age, gender, id)
    {
        this->cfm = costm;
        this->total = costm + a.getcfa();
    }
    Patient(Patient &a) : Person(a)
    {
        this->cfm = a.cfm;
        this->total = a.total;
    }
    double getpayment() const
    {
        return total;
    }
    void show()
    {
        cout << "** Patient:\n";
        cout << "Name:" << name << " Age:" << age << " Gender:" << gender << "Id:" << id << endl;
    }

private:
    double cfm;
    double total;
};
class Billing : public Doctor, public Patient
{
public:
    Billing(Patient &p, Doctor &d) : Doctor(d), Patient(p)
    {
        totalIncome += p.getpayment();
    }
    void show()
    {
        cout << "**** Billing information ****" << endl
             << endl;
        Patient::show();
        Doctor::show();
        cout << "\nPayment:" << getpayment() << endl;
    }
    static double getTotalIncome();

private:
    static double totalIncome;
};
double Billing::totalIncome = 0;
double Billing::getTotalIncome()
{
    return totalIncome;
}
int main()
{
    Doctor a("Wangli", 36, 'm', "74869304", "pediatrician", 100);
    Doctor b("zhanghai", 60, 'f', "23457576", "obstetrician", 50);
    Patient p1("xiaoming", 8, 'm', "89437584", 298.8, a);
    Patient p2("sun", 9, 'f', "34345", 78.9, b);
    Billing bill1(p1, a);
    Billing bill2(p2, b);
    bill1.show();
    bill2.show();
    cout << fixed << setprecision(2);
    cout << "Total income of Clinic:" << Billing::getTotalIncome() << endl;
    return 0;
}