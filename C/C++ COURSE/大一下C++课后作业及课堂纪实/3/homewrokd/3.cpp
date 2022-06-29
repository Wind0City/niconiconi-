//problem 3-3
#include <iostream>
#include <iomanip>
using namespace std;
class Time
{
public:
    Time(int hr = 0, int mi = 0, int se = 0) 
    {
        totalSeconds=0;
    }
    void setTime(int hr, int mi, int se)
    {
        setHour(hr);
        setMinute(mi);
        setSecond(se);
    }
    void setHour(int h)
    {
        totalSeconds += (h >= 0 && h < 24) ? h * 3600 : 0;
    }
    void setMinute(int m)
    {
        totalSeconds += (m >= 0 && m < 60) ? m * 60 : 0;
    }
    void setSecond(int s)
    {
        totalSeconds += (s >= 0 && s < 60) ? s : 0;
    }
    int getHour() const
    {
        return totalSeconds / 3600;
    }
    int getMinute() const
    {
        return totalSeconds % 3600 / 60;
    }
    int getSecond() const
    {
        return totalSeconds % 60;
    }
    void printUniversal() const
    {
        cout << setfill('0') << setw(2) << getHour() << ":"
             << setw(2) << getMinute() << ":" << setw(2) << getSecond();
    }
    void printStandard() const
    {
        cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
             << ":" << setfill('0') << setw(2) << getMinute()
             << ":" << setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM");
    }

private:
    int totalSeconds;
};
int main()
{
    Time t; // create Time object
    int second, minute, hour;
    cin >> hour >> minute >> second;
    t.setTime(hour, minute, second);
    // output time in universal and standard formats
    cout << "Universal time: ";
    t.printUniversal();
    cout << "\nStandard time: ";
    t.printStandard();
    return 0;
}