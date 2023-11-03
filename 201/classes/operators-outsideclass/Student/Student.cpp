#include <string>
#include "Student.h"

using std::string;

Student::Student() : name(), id(0) {}
Student::Student(string name, int id) : name(name), id(id) {}

string Student::getName() { return name; }
void Student::setName(string name) { this->name = name; }

int Student::getID() { return id; }
void Student::setID(int id) { this->id = id; }