#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student_info
{
    string name;
    double midterm;
    double finalterm;
    vector<double> homeworks;
};

istream& read(istream& in, Student_info& s);

#endif