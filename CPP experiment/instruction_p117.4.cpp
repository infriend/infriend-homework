#include <iostream>
using namespace std;

class Student
{
public:
    void account(double);
    static void sum();
    static double average();

private:
    double score;
    static double total_score, count;
};
double Student :: count = 0, Student :: total_score = 0;
//every time you use the static argu, you need to declear the domain

void Student :: account(double s)
{
    score = s;
    total_score += score;
    ++count;
}

void Student :: sum()
{
    cout << total_score << endl;
}

double Student :: average()
{
    return total_score/count;
}

int main()
{
    double s;
    Student s1, s2, s3;
    cout << "score1 = ";
    cin >> s;
    s1.account(s);
    cout << "score2 = ";
    cin >> s;
    s2.account(s);
    cout << "score3 = ";
    cin >> s;
    s3.account(s);

    cout << "Sum = ";
    Student :: sum();
    cout << "Average = " << Student :: average() << endl;

    return 0;
}
