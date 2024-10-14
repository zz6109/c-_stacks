#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout; using std::cin; 
using std::vector; using std::string;

string::size_type width(const vector<string>& v)
{
    string::size_type maxLen = 0;
    for (auto it =v.cbegin(); it != v.cend(); ++it)
    {
        maxLen = std::max(maxLen, it->size());   
    }
    return maxLen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> result;

    string::size_type maxLen = width(v);
    string boarder(maxLen + 4, '*');

    result.push_back(boarder);
    for (auto it =v.cbegin(); it != v.cend(); ++it)
    {
        string s = "* " + *it + string(maxLen - it->size(), ' ') + " *";
        result.push_back(s);
    }
    

    return result;
}

vector<string> vertical_cat(const vector<string>& v1, const vector<string>& v2)
{
    vector<string> result;
    result = v1;

    for (auto it =v2.cbegin(); it != v2.cend(); ++it)
    {
        result.push_back(*it);
    }


    return result;
}
int main()
{
    vector<string> lines;
    lines.push_back("this it an");
    lines.push_back("example");
    lines.push_back("to");
    lines.push_back("illustrate");
    lines.push_back("framing");

    vector<string> result = frame(lines);

    for (auto it =result.cbegin(); it != result.cend(); ++it)
    {

    }

    return 0;
}