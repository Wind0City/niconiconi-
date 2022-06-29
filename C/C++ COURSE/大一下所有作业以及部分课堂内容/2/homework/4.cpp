#include <iostream>
#include <string>
using namespace std;
class GradeBook
{
private:
    string CourseName, InstructorName;

public:
    GradeBook(string x, string y)
    {
        CourseName = x;
        InstructorName = y;
    }
    void setInstructorName(string x)
    {
        InstructorName = x;
    }
    string getInstructorName()
    {
        return InstructorName;
    }
    void displayMessage()
    {
        cout << "Welcome to the grade book for\n";
        cout << CourseName << "\n";
        cout << "This course is presented by" << getInstructorName() << "\n";
    }
};
int main()
{
    // create a GradeBook object; pass a course nameand instructor name
    GradeBook gradeBook("CS101 Introduction to C++ Programming", "Professor Smith");
    // display initial value of instructorName of GradeBook object
    cout << "gradeBook instructor name is: " << gradeBook.getInstructorName() << "\n";
    // modify the instructorName using set function
    gradeBook.setInstructorName("Assistant Professor Bates");
    // display new value of instructorName
    cout << "new gradeBook instructor name is: " << gradeBook.getInstructorName() << "\n";
    // display welcome message and instructor's name
    gradeBook.displayMessage();
    return 0; // indicate successful termination} // end main
}