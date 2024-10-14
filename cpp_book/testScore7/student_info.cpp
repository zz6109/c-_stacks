#include "student_info.h"

static istream& read_hw(istream& in, vector<double>& homeworks)
{
    if (in)
    {
        homeworks.clear();

        double homework;
        while (in >> homework)
        {
            homeworks.push_back(homework);
        }

        in.clear();
    }
    return in;
}

istream& read(istream& in, Student_info& s)
{
    cin >> s.name >> s.midterm >> s.finalterm;
    read_hw(in, s.homeworks);

    return in;
}