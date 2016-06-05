#include <iostream>
#include "Student.cpp"
using namespace std;

int main(int argc, char *argv[]) {
    Student stu1(1001, "hello");
    Student stu2(1002, "world");
    Score sco1(1001, 1, 100);
    Score sco2(1002, 2, 88);
    Course cou1(1);
    Course cou2(2);
    stu1.pushScore(sco1);
    stu2.pushScore(sco2);
    Student stu3 = stu2;
    cout << stu1 << endl;
    cout << stu2 << endl;
    cout << stu3 << endl;
    return 0;
}