#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
    string FirstName, LastName;
    int MonthlySalary;

public:
    Employee(string x, string y, int h)
    {
        FirstName = x;
        LastName = y;
        MonthlySalary = h;
    }
    void setFirstName(string x)
    {
        FirstName = x;
    }
    void setLastName(string y)
    {
        LastName = y;
    }
    void setMonthlySalary(int x)
    {
        if (x < 0)
        {
            x = 0;
        }
        MonthlySalary = x;
    }
    string getFirstName()
    {
        return FirstName;
    }
    string getLastName()
    {
        return LastName;
    }
    int getMonthlySalary()
    {
        return MonthlySalary;
    }
};
int main()
{
    // create two Employee objects
    Employee employee1("Lisa", "Roberts", 4500);
    Employee employee2("Mark", "Stein", 4000);
    // display each Employee's yearly salary
    cout << "Employees' yearly salaries: " << endl;
    // retrieve and display employee1's monthly salary multiplied by 12
    int monthlySalary1 = employee1.getMonthlySalary();
    cout << employee1.getFirstName() << " " << employee1.getLastName() << ": $" << monthlySalary1 * 12 << endl;
    // retrieve and display employee2's monthly salary multiplied by 12
    int monthlySalary2 = employee2.getMonthlySalary();
    cout << employee2.getFirstName() << " " << employee2.getLastName() << ": $" << monthlySalary2 * 12 << endl;
    // give each Employee a 10% raise    employee1.setMonthlySalary( monthlySalary1 * 1.1 );
    employee2.setMonthlySalary(monthlySalary2 * 1.1);
    // display each Employee's yearly salary again
    cout << "\nEmployees' yearly salaries after 10%raise: " << endl;
    // retrieve and display employee1's monthly salary multiplied by 12
    monthlySalary1 = employee1.getMonthlySalary();
    cout << employee1.getFirstName() << " " << employee1.getLastName() << ": $" << monthlySalary1 * 12 << endl;
    monthlySalary2 = employee2.getMonthlySalary();
    cout << employee2.getFirstName() << " " << employee2.getLastName() << ": $" << monthlySalary2 * 12 << endl;

    return 0; // indicate successful termination} // end main
}