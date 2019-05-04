#include <iostream>
#include <cmath>
using namespace std;

class Location
{
public:
    Location(double, double);
    double cal_dis(Location &);
    double getx();
    double gety();
    friend double cal_dis(Location &, Location &);

private:
    double x, y;
};

Location :: Location(double x1, double y1):x(x1), y(y1)
{}

double Location :: getx()
{
    return x;
}

double Location :: gety()
{
    return y;
}

double Location :: cal_dis(Location &b1)
{
    double res;
    res = sqrt(pow((x - b1.x), 2) + pow((y - b1.y), 2));

    return res;
}

double cal_dis(Location &a1, Location &b1)
{
    double res;
    res = sqrt(pow((a1.x - b1.x), 2) + pow((a1.y - b1.y), 2));

    return res;
}

int main()
{
    double x1, y1, x2, y2;
    cout << "x1 = ";
    cin >> x1;
    cout << "y1 = ";
    cin >> y1;
    cout << "x2 = ";
    cin >> x2;
    cout << "y2 = ";
    cin >> y2;
    Location a(x1, y1);
    Location b(x2, y2);
    cout << "A(" << a.getx() << "," << a.gety() << ")" << endl;
    cout << "B(" << b.getx() << "," << b.gety() << ")" << endl;
    cout << "Distance1 = " << cal_dis(a, b) << endl;
    cout << "Distance2 = " << a.cal_dis(b) << endl;

    return 0;
}
