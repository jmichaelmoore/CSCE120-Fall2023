#include "Employee.h"

Employee::Employee() : first_name(""), last_name("")
{
    //log("Employee::Employee()");
}

Employee::Employee(const std::string& first_name, const std::string& last_name) : first_name(first_name), last_name(last_name)
{
    //log("Employee::Employee(const std::string&, const std::string&)");
}

Employee& Employee::operator=(const Employee& rhs)
{
    //log("Employee& Employee::operator=(const Employee&)");
    first_name = rhs.first_name;
    last_name = rhs.last_name;
    return *this;
}

std::string Employee::to_str() const
{
    //log("std::string Employee::to_str() const");
    std::stringstream os;
    os << first_name << ' ' << last_name;
    return os.str();
}

void Employee::log(const std::string& what) const
{
    std::cout << "[" << this << "] " << what << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
    //employee.log("std::ostream& operator<<(std::ostream&, const Employee&)");
    os << employee.get_first_name() << ' ' << employee.get_last_name();
    return os;
}