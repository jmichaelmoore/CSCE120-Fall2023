#include<iostream>
#include<sstream>
#include<string>
#include "Student.h"

using std::string, std::cin, std::cout, std::endl;

void printStudent(string label, const Student& s) {
	cout << label << ": " << s.getName() << " (" << s.getID() << ")" << endl;
}

int main() {
	Student a;
	a.setName("Michael");
	a.setID(123);

	Student b("Jon", 789);
	b.setName("John");

  printStudent("a", a);
  printStudent("b", b);
}