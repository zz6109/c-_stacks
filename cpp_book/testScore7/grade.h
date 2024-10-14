#ifndef GRADE_H
#define GRADE_H
#include <vector>
#include <stdexcept>
#include "student_info.h"
using namespace std;

double grade(double midterm, double finalterm, double homework);
double grade(double midterm, double finalterm, const vector<double>& homeworks);
double grade(const Student_info& s);

#endif