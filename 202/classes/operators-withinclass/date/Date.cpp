#include <iostream>
#include <stdexcept>
#include <sstream>
#include "Date.h"

using std::runtime_error, std::cout, std::endl, std::invalid_argument;

Date::Date(): year(2021), month(1), day(1) {}

Date::Date(int year, int month, int day): 
            year(year), month(month), day(day) {
    if (!validYear(this->year))
      throw std::invalid_argument("Invalid year");
    if (!validMonth(this->month))
      throw std::invalid_argument("Invalid month");
    if (!validDay(this->day))
      throw std::invalid_argument("Invalid day");
  }

bool Date::validDay(int day) {
	cout << "day: " << day << endl;
	cout << "month: " << month << endl;
	if (day >= 1) {
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day <= 31)
				return true;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day <= 30)
				return true;
      break;
		case 2:
			if (day <= 28)
				return true;
      break;
		}
	}
	return false;
}

bool Date::validMonth(int month) {
	if (month >= 1 && month <= 12) {
		return true;
	}
	return false; // else return false
}
  
bool Date::validYear(int year) {
  if (year >= 1 && year <= 3000) {
    return true;
  }
  return false; // else return false
}


std::string Date::to_string() {
  std::ostringstream oss;
	oss << month << "/" << day << "/" << year << endl;
  return oss.str();
}

int Date::getDay() {
	return day;
}

void Date::setDay(int day) {
	if (validDay(day)) {
		this->day = day;
	}
	else
		throw runtime_error("Invalid Day");
}

int Date::getMonth() {
	return month;
}

void Date::setMonth(int month) {
	if (validMonth(month)) {
		this->month = month;
	}
	else
		throw runtime_error("Invalid Month");
}

int Date::getYear() {
	return year;
}

void Date::setYear(int year) {
	if (validYear(year)) {
		this->year = year;
	}
	else
		throw runtime_error("Invalid Year");
}
