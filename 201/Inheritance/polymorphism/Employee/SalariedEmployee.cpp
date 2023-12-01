#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee()
{
    //log("SalariedEmployee:SalariedEmployee()");
}

SalariedEmployee::SalariedEmployee(const std::string& first_name, const std::string& last_name,  double annual_salary) : Employee(first_name, last_name), annual_salary(annual_salary)
{
    //log("SalariedEmployee::SalariedEmployee(const std::string& first_name, const std::string& last_name, double annual_salary)");
}

SalariedEmployee& SalariedEmployee::operator=(const SalariedEmployee& rhs)
{
    //log("SalariedEmployee& SalariedEmployee::operator=(const SalariedEmployee&)");
    Employee::operator=(rhs);
    annual_salary = rhs.annual_salary;
    return *this;
}

std::string SalariedEmployee::to_str() const
{
    //log("std::string SalariedEmployee::to_str() const");
    std::stringstream os;
    os << Employee::to_str() << '\t' << get_annual_pay();
    return os.str();
}

std::ostream& operator<<(std::ostream& os, const SalariedEmployee& salariedEmployee)
{
    //salariedEmployee.log("std::ostream& operator<<(std::ostream&, const SalariedEmployee&)");
    //os << static_cast<Employee>(salariedEmployee) << '\t' << salariedEmployee.get_annual_pay());
    os << salariedEmployee.get_first_name() << ' ' << salariedEmployee.get_last_name() << '\t' << salariedEmployee.get_annual_pay();
    return os;
}