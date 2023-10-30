#ifndef DATE_H
#define DATE_H

class Date {
	int year;
	int month;
	int day;

  bool validDay(int day);
  bool validMonth(int month);
  bool validYear(int year);

public:
  Date();
  Date(int year, int month, int day);
	std::string to_string();
	int getDay();
	void setDay(int day);
	int getMonth();
	void setMonth(int month);
	int getYear();
	void setYear(int year);
  // add ==
	bool operator==(const Date& rhs) {
		return (this->year == rhs.year) &&
			   (this->month == rhs.month) &&
			   (this->day == rhs.day);
	}
  // add <
  // rhs right hand side     lhs left hand side
	bool operator<(const Date& rhs) {
		if (this->year < rhs.year) {
			return true;
		} else if (this->year == rhs.year) {
			if (this->month < rhs.month) {
				return true;
			} else if (this->month == rhs.month) {
				if (this->day < rhs.day) {
					return true;
				}
			}
		}
		return false;
	}
};

#endif