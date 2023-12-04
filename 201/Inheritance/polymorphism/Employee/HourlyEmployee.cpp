#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee()
{
    //log("HourlyEmployee:HourlyEmployee()");
}

HourlyEmployee::HourlyEmployee(const std::string& first_name, const std::string& last_name, double hourly_wage, double weekly_hours) : Employee(first_name, last_name), hourly_wage(hourly_wage), weekly_hours(weekly_hours)
{
    //log("HourlyEmployee::HourlyEmployee(const std::string& first_name, const std::string& last_name, double hourly_wage, double weekly_hours)");
}

HourlyEmployee& HourlyEmployee::operator=(const HourlyEmployee& rhs)
{
    //log("HourlyEmployee& HourlyEmployee::operator=(const HourlyEmployee&)");
    Employee::operator=(rhs);
    hourly_wage = rhs.hourly_wage;
    return *this;
}

std::string HourlyEmployee::to_str() const
{
    //log("std::string HourlyEmployee::to_str() const");
    std::stringstream os;
    os << Employee::to_str() << '\t' << get_annual_pay();
    return os.str();
}

std::ostream& operator<<(std::ostream& os, const HourlyEmployee& hourlyEmployee)
{
    //hourlyEmployee.log("std::ostream& operator<<(std::ostream&, const HourlyEmployee&)");
    //os << static_cast<Employee>(hourlyEmployee) << '\t' << hourlyEmployee.get_hourly_wage();
    os << hourlyEmployee.get_first_name() << ' ' << hourlyEmployee.get_last_name() << '\t' << hourlyEmployee.get_annual_pay();
    return os;
}