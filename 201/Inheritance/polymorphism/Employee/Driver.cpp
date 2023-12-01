#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
using namespace std;

int main (int argc, char * argv[])
{
    HourlyEmployee h1("Jill", "Williamson", 20.0, 40);
    cout << h1 << endl;
    SalariedEmployee s1("Jack", "Smith", 40000);
    cout << s1 << endl << endl;

    vector<Employee*> employees;
    employees.push_back(&h1);
    employees.push_back(&s1);
    for (int i = 0; i < employees.size(); ++i) {
        string e = employees.at(i)->to_str();
        cout << e << endl;
    }

    return 0;
}