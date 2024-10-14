#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "string.h"

class Employee
{
friend std::ostream &operator<<(std::ostream &out, const Employee &rhs);

private:
    int id_;
    String name_;
    const Employee *pManager_;

    Employee(const Employee& ths);              // 사용못하게 막음
    Employee& operator=(const Employee& rhs);   // 사용못하게 막음
public:
    Employee(int id, String name, const Employee *p);
    // ~Employee();

    int getID() const;
    String getName() const;
    const Employee* getPManager() const;
};



#endif