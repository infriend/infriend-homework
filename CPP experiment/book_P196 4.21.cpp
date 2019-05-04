#include <iostream>
using namespace std;

class Time
{
public:
    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }
    void display()
    {
        cout << "Birth time: " << hours << "H" << minutes << "M" << seconds << "S" << endl;
    }
protected:
    int hours, minutes, seconds;
};
class Date
{
public:
    Date(int m, int d, int y)
    {
        month = m;
        day = d;
        year = y;
    }
    void display()
    {
        cout << "Birth year/month: " << year << "Y" << month << "M" << day << "D" << endl;
    }
protected:
    int month, day, year;
};
class Birthtime: public Time, public Date
{
public:
    Birthtime(int h, int min, int s, int mon, int d, int y, string name);
    void printname();
private:
    string Childname;
};
Birthtime::Birthtime(int h, int min, int s, int mon, int d, int y, string name): Time(h, min, s), Date(mon, d, y), Childname(name)
{};
void Birthtime::printname()
{
    cout << "Name is " << Childname << endl;
}

int main()
{
    Birthtime b(19, 28, 36, 3, 9, 1999, "MAHIRU");
    b.printname();
    b.Time::display();
    b.Date::display();

    return 0;
}
