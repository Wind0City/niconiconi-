//problem 5 - 3
#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    Student(double x = 0) : score(x) {}
    ~Student()
    {
        count--;
    }
    void account(double s)
    {
        score = s;
        totalScore += score;
        count++;
    }
    static void sum()
    {
        cout << "The sum score of all students is " << totalScore << endl;
    }
    static void average()
    {
        cout << "The average score of all students is " << totalScore / count << endl;
    }

private:
    double score;
    static int count;
    static double totalScore;
};
int Student::count = 0;
double Student::totalScore = 0;
int main()
{
    Student std[10];
    int n;
    double s;
    //    cout<<"Please input the number of students (1-10):";
    cin >> n;
    for (int i = 0; i < n; i++)
    { //        cout<<"please input the score of student "<<i+1<<" :";
        cin >> s;
        std[i].account(s);
    }
    cout.setf(ios::fixed);
    cout.precision(2);
    Student::sum();
    Student::average();
    return 0;
}