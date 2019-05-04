#include <iostream>
using namespace std;

class area_cl
{
protected:
    double height;
    double width;
public:
    area_cl(double r, double s)
    {
        height = r;
        width = s;
    }
    virtual double area() = 0;
};
class rectangle: public area_cl
{
public:
    double area();
    rectangle(double r, double s, double s_area = 0);
private:
    double s_area;
};
class isosceles: public area_cl
{
public:
    double area();
    isosceles(double r, double s, double s_area = 0);
private:
    double s_area;
};
//rectangle
rectangle::rectangle(double r, double s, double s_area): area_cl(r, s)
{};
double rectangle::area()
{
    s_area = height * width;
    return s_area;
}
//isosceles
isosceles::isosceles(double r, double s, double s_area): area_cl(r, s)
{};
double isosceles::area()
{
    s_area = 0.5 * height * width;
    return s_area;
}

int main()
{
    rectangle r(10, 5);
    isosceles i(4, 6);
    cout << "Area of rectangle is " << r.area() << endl;
    cout << "Area of isosceles is " << i.area() << endl;

    area_cl *p;
    p = &r;
    cout << "pointer of base class gives the area: " << p->area() << endl;
    p = &i;
    cout << "pointer of base class gives the area: " << p->area() << endl;

    return 0;
}
