/*Write a C++ program to 
1) implement a class called Date 
2) that has private member variables for day, month, and year.
3) Include member functions to set and get these variables,
4) as well as to validate if the date is valid.
5) check for leap year.

the problem includes 5 points each point = 2 Marks
total is 10 marks for this quiz

An astronomical year lasts slightly less than 365 1/4 days.
The historic Julian calendar has three common years of 365 days 
followed by a leap year of 366 days, by extending February to 29 days
rather than the common 28. The Gregorian calendar, the world's most widely
used civil calendar, makes a further adjustment for the small error in the
Julian algorithm.
Again each leap year has 366 days instead of 365.
This extra leap day occurs in each year that is an integer
multiple of 4 (except for years evenly divisible by 100, but not by 400).
https://en.wikipedia.org/wiki/Leap_year
*/

#include <iostream>


class Date {
  private: int day;
  int month;
  int year;

  public:
    // Constructor
    Date(int d, int m, int y): day(d),
  month(m),
  year(y) {}

  // Member function to set the date
  void setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
  }

  // Member function to get the day
  int getDay() const {
    return day;
  }

  // Member function to get the month
  int getMonth() const {
    return month;
  }

  // Member function to get the year
  int getYear() const {
    return year;
  }

  // Member function to validate if the date is valid
  bool isValidDate() const {
    // Check if the month is valid
    if (month < 1 || month > 12)
      return false;

    // Check if the day is valid
    if (day < 1 || day > 31)
      return false;

    // Check for specific month-day combinations that are invalid
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
      return false;

    if (month == 2) {
      // Check for leap year
      if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        if (day > 29)
          return false;
      } else {
        if (day > 28)
          return false;
      }
    }

    // Date is valid
    return true;
  }
};

int main() {
  // Create a date object
  Date date(0, 0, 0);

  // Set the date
  int day, month, year;
  std::cout << "Input day: ";
  std::cin >> day;
  std::cout << "Input month: ";
  std::cin >> month;
  std::cout << "Input year: ";
  std::cin >> year;

  date.setDate(day, month, year);

  // Get and display the date
  std::cout << "Date: " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << std::endl;

  // Validate the date
  if (date.isValidDate())
    std::cout << "The date is valid." << std::endl;
  else
    std::cout << "The date is invalid." << std::endl;

  return 0;
}


