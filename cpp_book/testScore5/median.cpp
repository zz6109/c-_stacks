#include "median.h"

double median(const vector<double>& vec)
{
    vector<double> vec2 = vec;
    sort(vec2.begin(), vec2.end());

    const vector<double>::size_type mid = vec2.size() / 2;
    double median;
    if (vec2.size() % 2 != 0)
    {
        median = vec2[mid];
    }
    else
    {
        median = (vec2[mid] + vec2[mid-1]) / 2;
    }
    return median;
}