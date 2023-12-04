#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include <iostream>
#include <string>
#include <sstream>
#include "Employee.h"

class HourlyEmployee : public Employee {
public:
    HourlyEmployee();
    HourlyEmployee(const std::string&, const std::string&, double, double);
    HourlyEmployee& operator=(const HourlyEmployee&);
    std::string to_str() const; // hides Employee's to_str()
    double get_hourly_wage() const {return hourly_wage;}
    double get_weekly_hours() const {return weekly_hours;}
    double get_annual_pay() const {return hourly_wage*weekly_hours*52.1429;}
private:
    double hourly_wage;
    double weekly_hours;
};

std::ostream& operator<<(std::ostream&, const HourlyEmployee&);

#endif