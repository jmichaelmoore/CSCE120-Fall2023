#include<iostream>
#include<sstream>
#include<string>

using std::string, std::cin, std::cout, std::endl;

class Student {
	string name;
	int id;
public:
	// constructors
	Student();
	Student(string name, int id);

	// accessors and mutators
	string getName();
	void setName(string name);

	int getID();
	void setID(int id);

  string getStudent();
};

int main() {
	Student a;
	a.setName("Michael");
	a.setID(123);

	Student b("Jon", 789);
	b.setName("John");

  cout << "a: " << a.getStudent() << endl;
  cout << "b: " << b.getStudent() << endl;
}

Student::Student() : name(), id(0) {}
Student::Student(string name, int id) : name(name), id(id) {}

string Student::getName() { return name; }
void Student::setName(string name) { this->name = name; }

int Student::getID() {return id; }
void Student::setID(int id) { this->id = id; }

string Student::getStudent() {
  std::ostringstream oss;
  oss << name << " (" << id << ")";
  return oss.str();
}