#include <iostream>
#include <cmath>
using namespace std;

class container
{
protected:
    double radius;
public:
    container(double radius1);
    virtual double surface_area() = 0;
    virtual double volume() = 0;
};
container::container(double radius1): radius(radius1)
{};

class cube: public container
{
public:
    cube(double radius1): container(radius1)
    {};
    double surface_area()
    {
        return pow(radius, 2) * 6;
    }
    double volume()
    {
        return pow(radius, 3);
    }
};
class sphere: public container
{
public:
    sphere(double radius1): container(radius1)
    {};
    double surface_area()
    {
        return 4 * 3.14 * pow(radius, 2);
    }
    double volume()
    {
        return 4.0/3.0 * 3.14 * pow(radius, 3);
    }
};
class cylinder: public container
{
private:
    double height;
public:
    cylinder(double r, double h): container(r), height(h)
    {};
    double surface_area()
    {
        return 3.14 * pow(radius, 2) * 2 + 2 * 3.14 * radius * height;
    }
    double volume()
    {
        return 3.14 * pow(radius, 2) * height;
    }
};


int main()
{
    container *p;
    cube c(6);
    sphere s(5);
    cylinder d(5, 6);
    p = &c;
    cout << "cube surface_area = " << p->surface_area() << endl;
    cout << "cube volume = " << p->volume() << endl;
    p = &s;
    cout << "sphere surface_area = " << p->surface_area() << endl;
    cout << "sphere volume = " << p->volume() << endl;
    p = &d;
    cout << "cylinder surface_area = " << p->surface_area() << endl;
    cout << "cylinder volume = " << p->volume() << endl;

    return 0;
}
