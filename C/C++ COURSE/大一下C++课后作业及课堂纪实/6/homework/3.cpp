//problem 6-3
#include <iostream>
#include <iomanip>
#include <cstring> // strcpy and strcat prototypes
#include <cstdlib> // exit prototype
using namespace std;
class String
{
    friend ostream &operator<<(ostream &out, const String &a)
    {
        if (a.length == 0)
        {
            return out << "";
        }
        for (int i = 0; i < a.length; i++)
        {
            out << a.sPtr[i];
        }
        return out;
    }
    friend istream &operator>>(istream &input, String &a)
    {
        for (int i = 0; i < a.length; i++)
        {
            input >> a.sPtr[i];
        }
        return input;
    }

public:
    String(const char *p = "") // conversion/default constructor
    {
        setString(p);
        cout << "Conversion (and default) constructor:";
        for (int i = 0; i < strlen(p); i++)
        {
            cout << p[i];
        }
        cout << endl;
    }
    String(const String &a)
    {
        setString(a.sPtr);
        cout << "Copy constructo:" << a.sPtr << endl;
    }
    ~String() // destructor
    {
        cout << "Destructor:" << this->sPtr << endl;
        delete[] sPtr;
    }
    const String &operator=(const String &a) // assignment operator
    {
        if (&a != this)
        {
            if (length != a.length)
            {
                delete[] sPtr;
                length = a.length;
                sPtr = new char[length];
                strcpy(sPtr, a.sPtr);
            }
        }
        cout << "operator = called" << endl;
        return *this;
    }
    const String &operator+=(const String &a) // concatenation operator
    {
        length += a.length;
        strcat(sPtr, a.sPtr);
        return *this;
    }
    bool operator!() const // is String empty?
    {
        if (length == 0)
        {
            return true;
        }
        return false;
    }
    bool operator==(const String &a) const // test s1== s2
    {
        if (this->length == a.length)
        {
            for (int i = 0; i < this->length; i++)
            {
                if (this->sPtr[i] != a.sPtr[i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    bool operator<(const String &s2) const // test s1 < s2
    {
        int judge = strcmp(this->sPtr, s2.sPtr);
        if (judge < 0)
        {
            return true;
        }
        return false;
    }
    bool operator!=(const String &s2) const // test s1 != s2
    {
        int judge = strcmp(this->sPtr, s2.sPtr);
        if (judge == 0)
        {
            return false;
        }
        return true;
    }
    bool operator>(const String &s2) const // test s1 > s2
    {
        int judge = strcmp(this->sPtr, s2.sPtr);
        if (judge > 0)
        {
            return true;
        }
        return false;
    }
    bool operator<=(const String &s2) const // test s1 <= s2
    {
        int judge = strcmp(this->sPtr, s2.sPtr);
        if (judge <= 0)
        {
            return true;
        }
        return false;
    }
    bool operator>=(const String &s2) const // test s1 >= s2
    {
        int judge = strcmp(this->sPtr, s2.sPtr);
        if (judge >= 0)
        {
            return true;
        }
        return false;
    }
    char &operator[](int n) // subscript operator (modifiable lvalue)
    {
        if (n < 0 || n >= length)
        {
            cout << "error:Subscript" << n << " out of range" << endl;
            exit(1);
        }
        return this->sPtr[n];
    }
    int getLength() const // return string length
    {
        return length;
    }

private:
    int length;                         // string length (not counting null terminator)
    char *sPtr;                         // pointer to start of pointer-based string
    void setString(const char *string1) // utility function};
    {
        if (strlen(string1) == 0)
        {
            length = 0;
            return;
        }
        length = strlen(string1);
        sPtr = new char[length];
        strcpy(sPtr, string1);
    }
};
int main()
{
    String s1("happy");
    String s2(" birthday");
    String s3;
    // test overloaded equality and relational opera-tors
    cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2
         << "\"; s3 is \"" << s3 << '\"'
         << boolalpha << "\n\nThe results of comparing s2 and s1:"
         << "\ns2 == s1 yields " << (s2 == s1)
         << "\ns2 != s1 yields " << (s2 != s1)
         << "\ns2 >  s1 yields " << (s2 > s1)
         << "\ns2 <  s1 yields " << (s2 < s1)
         << "\ns2 >= s1 yields " << (s2 >= s1)
         << "\ns2 <= s1 yields " << (s2 <= s1);
    // test overloaded String empty (!) operator
    cout << "\n\nTesting !s3:" << endl;
    if (!s3)
    {
        cout << "s3 is empty; assigning s1 to s3;" << endl;
        s3 = s1; // test overloaded assignment
        cout << "s3 is \"" << s3 << "\"";
    } // end if
      // test overloaded String concatenation operator
    cout << "\n\ns1 += s2 yields s1 = ";
    s1 += s2;   // test overloaded concatenation
    cout << s1; // test conversion constructor
    cout << "\n\ns1 += \" to you\" yields" << endl;
    s1 += " to you"; // test conversion constructor
    cout << "s1 = " << s1 << "\n";
    // test copy constructor
    String *s4Ptr = new String(s1);
    cout << "\n*s4Ptr = " << *s4Ptr << "\n";
    // test destructor
    delete s4Ptr;
    // test using subscript operator to create a modi-fiable lvalue
    s1[0] = 'H';
    s1[6] = 'B';
    cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is:" << s1 << "\n";
    // test subscript out of range
    cout << "Attempt to assign 'd' to s1[30] yields:" << endl;
    s1[30] = 'd'; // ERROR: subscript out of range
    return 0;
} // end main