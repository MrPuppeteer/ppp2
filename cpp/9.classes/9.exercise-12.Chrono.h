#include "std_lib_facilities.h"

#ifndef CHRONO_H
#define CHRONO_H

namespace Chrono {

enum class Day {
  sun, mon, tue, wed, thu, fri, sat
};

Day operator + (const Day& d, int n);
Day& operator += (Day& d, int n);
ostream& operator << (ostream& os, const Day& d);

enum class Month {
  jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

int month_days(Month m, bool y);

Month& operator ++ (Month& m);

constexpr int epoch_year {1970};
constexpr Day epoch_dow {Day::thu};

class Date {
public:
  class Invalid {};

  Date(int yy, Month mm, int dd); // check for valid date and initialize
  Date (long int days);
  Date();

  int day() const;
  Month month() const;
  int year() const;
  long int get_days_since_epoch() const;
  
  void add_day(int n);       // increase the Date by n days
  void add_month(int n);
  void add_year(int n);
private:
  long int days_since_epoch;
};

bool is_date(int y, Month m, int d);
bool leapyear(int y);
int n_leaps(int y);

long int get_days_since_epoch(int y, Month m, int d);
Day day_of_week(const Date& d);
Date next_Sunday(const Date d);
Date next_workday(const Date& d);
int week_of_year(const Date& d);

bool operator == (const Date& a, const Date& b);
bool operator != (const Date& a, const Date& b);
bool operator <= (const Date& a, const Date& b);
ostream& operator << (ostream& os, const Date& d);
istream& operator >> (istream& is, Date& dd);

}

#endif
