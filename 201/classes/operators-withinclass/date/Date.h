#ifndef DATE_H
#define DATE_H

class Date {
	int day;
	int month;
	int year;

	bool validDay(int day);
  bool validMonth(int month);
  bool validYear(int year);

public:
  Date();
  Date(int day, int month, int year);
	std::string to_string();
	int getDay();
	void setDay(int day);
	int getMonth();
	void setMonth(int month);
	int getYear();
	void setYear(int year);
  // add ==
  // add <
  // rhs right hand side     lhs left hand side
};

#endif