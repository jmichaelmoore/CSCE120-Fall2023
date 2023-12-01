#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <sstream>

class Employee {
public:
    Employee();
    Employee(const std::string&, const std::string&);
    Employee& operator=(const Employee&);
    std::string get_first_name() const {return first_name;}
    std::string get_last_name() const {return last_name;}
    std::string to_str() const;

    void log(const std::string& what) const;
private:
    std::string first_name, last_name;
};

std::ostream& operator<<(std::ostream&, const Employee&);

#endif