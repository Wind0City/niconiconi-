#include <iostream>
#include <string>
using namespace std;
const int date1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //非闰年的各个月份的天数
const int date2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //如年的各个月份的天数
bool judge(int x)                                                       //判断年份是否是闰年
{
    if (x % 400 == 0)
    {
        return true;
    }
    else
    {
        if (x % 4 == 0 && x % 100 != 0)
        {
            return true;
        }
        else
            return false;
    }
}
class Date
{
private:
    int Year, Month, Day;

public:
    Date(int m, int d, int y)
    {
        Year = y;
        if (m <= 0 || m > 12)
        {
            m = 1;
        }
        Month = m;
        if (judge(y))
        {
            if (d <= 0 || d > date1[m - 1])
            {
                d = 1;
            }
        }
        else
        {
            if (d <= 0 || d > date2[m - 1])
            {
                d = 1;
            }
        }
        Day = d;
    }
    void setMonth(int m)
    {
        if (m <= 0 || m > 12)
        {
            m = 1;
        }
        Month = m;
    }
    void setYear(int y)
    {
        Year = y;
    }
    void setDay(int d)
    {
        if (judge(Year))
        {
            if (d <= 0 || d > date1[Month - 1])
            {
                d = 1;
            }
        }
        else
        {
            if (d <= 0 || d > date2[Month - 1])
            {
                d = 1;
            }
        }
        Day = d;
    }
    int getYear()
    {
        return Year;
    }
    int getDay()
    {
        return Day;
    }
    int getMonth()
    {
        return Month;
    }
    void displayDate()
    {
        cout << Month << "/" << Day << "/" << Year << endl;
    }
};
int main()
{
    Date date(5, 6, 1981); // create a Date object for May 6, 1981
                           // display the values of the three Date data members
    cout << "Month: " << date.getMonth() << endl;
    cout << "Day: " << date.getDay() << endl;
    cout << "Year: " << date.getYear() << endl;
    cout << "\nOriginal date:" << endl;
    date.displayDate(); // output the Date as 5/6/1981
                        // modify the Date
    date.setMonth(13);  // invalid month
    date.setDay(1);
    date.setYear(2005);
    cout << "\nNew date:" << endl;
    date.displayDate(); // output the modified date(1/1/2005)
    return 0;           // indicate successful termination} // end main
}