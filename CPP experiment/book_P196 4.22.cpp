#include <iostream>
using namespace std;

class person
{
public:
    void input()
    {
        cout << "Num: ";
        cin >> num;
        cout << "Name: ";
        cin >> name;
    }
    void display()
    {
        cout << "Num: " << num << endl;
        cout << "Name: " << name << endl;
    }
protected:
    string num, name;
};
class student: public person
{
public:
    void input()
    {
        cout << "Student" << endl;
        person::input();
        cout << "Classnum: ";
        cin >> classnum;
        cout << "Grade: ";
        cin >> grade;
    }
    void display()
    {
        person::display();
        cout << "Classnum: " << classnum << endl;
        cout << "Grade: "  << grade << endl;
    }
private:
    string classnum;
    float grade;
};
class teacher: public person
{
public:
    void input()
    {
        cout <<"Teacher" << endl;
        person::input();
        cout << "Position: ";
        cin >> pos;
        cout << "Department: ";
        cin >> dep;
    }
    void display()
    {
        person::display();
        cout << "Position: " << pos << endl;
        cout << "Department: " << dep << endl;
    }
private:
    string pos, dep;
};


int main()
{
    student s;
    teacher k;

    cout << "INPUT: " << endl;
    s.input();
    k.input();
    cout << "OUTPUT: " << endl;
    s.display();
    k.display();

    return 0;
}
