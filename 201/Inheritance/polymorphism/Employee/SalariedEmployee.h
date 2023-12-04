#ifndef SALARIEDEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include <iostream>
#include <string>
#include <sstream>
#include "Employee.h"

class SalariedEmployee : public Employee {
public:
    SalariedEmployee();
    SalariedEmployee(const std::string&, const std::string&, double);
    SalariedEmployee& operator=(const SalariedEmployee&);
    std::string to_str() const; // hides Employee's to_str()
    double get_annual_pay() const {return annual_salary;}
private:
    double annual_salary;
};

std::ostream& operator<<(std::ostream&, const SalariedEmployee&);

#endif