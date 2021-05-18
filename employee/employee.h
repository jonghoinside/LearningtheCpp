#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include "string.h"

class Employee {
friend std::ostream& operator<<(std::ostream& out, const Employee& rhs);
private:
    int id_;
    String name_;
    Employee* pManager_;

    // not use..
    Employee(const Employee& rhs);
    Employee& operator=(const Employee& rhs);
public:
    Employee(int id, String name, const Employee* pManager);
    ~Employee();

    // Employee* operator&();
    // const Employee* operator&() const;

    int id() const;
    String name() const;
    const Employee* getManager() const;

    void setManager(const Employee *pManager);

    bool isManager() const;
};

#endif