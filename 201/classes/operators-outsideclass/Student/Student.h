#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
	std::string name;
	int id;
public:
	// constructors
	Student();
	Student(std::string name, int id);

	// accessors and mutators
	std::string getName();
	void setName(std::string name);

	int getID();
	void setID(int id);
};

#endif