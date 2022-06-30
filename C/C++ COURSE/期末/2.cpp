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
    friend bool operator==(Date &a, Date &b)
    {
        if (a.Year != b.Year)
        {
            return false;
        }
        if (a.Month != b.Month)
        {
            return false;
        }
        if (a.Day != b.Day)
        {
            return false;
        }
        return true;
    }
    friend bool operator!=(Date &a, Date &b)
    {
        if (a.Year != b.Year)
        {
            return true;
        }
        if (a.Month != b.Month)
        {
            return true;
        }
        if (a.Day != b.Day)
        {
            return true;
        }
        return false;
    }
    friend bool operator>(Date &a, Date &b)
    {
        if (a.Year > b.Year)
        {
            return true;
        }
        else if (a.Year == b.Year)
        {
            if (a.Month > b.Month)
            {
                return true;
            }
            else if (a.Month == b.Month)
            {
                if (a.Day > b.Day)
                {
                    return true;
                }
                return false;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    friend bool operator>=(Date &a, Date &b)
    {
        if (a.Year > b.Year)
        {
            return true;
        }
        else if (a.Year == b.Year)
        {
            if (a.Month > b.Month)
            {
                return true;
            }
            else if (a.Month == b.Month)
            {
                if (a.Day >= b.Day)
                {
                    return true;
                }
                return false;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    friend bool operator<(Date &a, Date &b)
    {
        if (a.Year < b.Year)
        {
            return true;
        }
        else if (a.Year == b.Year)
        {
            if (a.Month < b.Month)
            {
                return true;
            }
            else if (a.Month == b.Month)
            {
                if (a.Day < b.Day)
                {
                    return true;
                }
                return false;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    friend bool operator<=(Date &a, Date &b)
    {
        if (a.Year < b.Year)
        {
            return true;
        }
        else if (a.Year == b.Year)
        {
            if (a.Month < b.Month)
            {
                return true;
            }
            else if (a.Month == b.Month)
            {
                if (a.Day <= b.Day)
                {
                    return true;
                }
                return false;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    friend ostream &operator<<(ostream &out, Date &a)
    {
        out << a.Year << "年" << a.Month << "月" << a.Day << "日" << endl;
        return out;
    }
    friend istream &operator>>(istream &input, Date &a)
    {
        int x, y, z;
        input >> x >> y >> z;
        a.Day = z;
        a.Month = y;
        a.Year = x;
        return input;
    }

private:
    int Year, Month, Day;

public:
    Date(int m = 0, int d = 0, int y = 0)
    {
        Year = y;
        if (m <= 0)
        {
            m = 1;
        }
        if (m > 12)
        {
            m = 12;
        }
        Month = m;
        if (judge(y))
        {
            if (d <= 0)
            {
                d = 1;
            }
            if (d > date1[m - 1])
            {
                d = date1[m - 1];
            }
        }
        else
        {
            if (d <= 0)
            {
                d = 1;
            }
            if (d > date2[m - 1])
            {
                d = date2[m - 1];
            }
        }
        Day = d;
    }
    Date &operator++()
    {
        if (judge(this->Year))
        {
            this->Day++;
            if (this->Day > date2[this->Month - 1])
            {
                this->Day = 1;
                this->Month++;
            }
            if (this->Month > 12)
            {
                this->Month = 1;
                this->Year++;
            }
        }
        else
        {
            this->Day++;
            if (this->Day > date1[this->Month - 1])
            {
                this->Day = 1;
                this->Month++;
            }
            if (this->Month > 12)
            {
                this->Month = 1;
                this->Year++;
            }
        }
        return *this;
    }
    Date &operator--()
    {
        this->Day--;
        if (this->Day < 1)
        {
            this->Month--;
        }
        if (this->Month < 1)
        {
            this->Month = 12;
            this->Year--;
        }

        if (judge(this->Year))
        {
            this->Day = date2[this->Month - 1];
        }
        if (!judge(this->Year))
        {
            this->Day = date1[this->Month - 1];
        }
        return *this;
    }
};
// StudybarCommentBegin
int main()
{
    Date day;
    cin >> day;
    // cout << "请输入比较对象的日期day2:";
    Date day2; // 比较对象的日期
    cin >> day2;

    cout << boolalpha;
    cout << "day  = " << day;
    cout << "day2 = " << day2;
    cout << "day  == day2  = " << (day == day2) << '\n';
    cout << "day  != day2  = " << (day != day2) << '\n';
    cout << "day  >  day2  = " << (day > day2) << '\n';
    cout << "day  >= day2  = " << (day >= day2) << '\n';
    cout << "day  <  day2  = " << (day < day2) << '\n';
    cout << "day  <= day2  = " << (day <= day2) << '\n';
}
// StudybarCommentEnd