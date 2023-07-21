#include "std_lib_facilities.h"

#ifndef CHRONO_H
#define CHRONO_H

namespace Chrono {

constexpr int epoch_year {1970};

enum class Day {
  sun, mon, tue, wed, thu, fri, sat
};

constexpr Day epoch_dow {Day::thu};

Day operator + (const Day& d, int n);
Day& operator += (Day& d, int n);
ostream& operator << (ostream& os, const Day& d);

enum class Month {
  jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

int month_days(Month m, bool leap);

Month operator + (const Month& m, int n);
Month operator - (const Month& m, int n);
Month& operator += (Month& m, int n);
Month& operator ++ (Month& m);

bool operator < (const Month& m, int n);
bool operator > (const Month& m, int n);

class Date {
public:
  class Invalid {};

  Date(int yy, Month mm, int dd); // check for valid date and initialize
  Date();

  int day() const { return d; }
  Month month() const { return m; }
  int year() const { return y; }
  
  void add_day(int n);       // increase the Date by n days
  void add_month(int n);
  void add_year(int n);
private:
  int y;    // year
  Month m;
  int d;    // day
};

bool is_date(int y, Month m, int d);
bool leapyear(int y);

bool operator == (const Date& a, const Date& b);
bool operator != (const Date& a, const Date& b);
bool operator < (const Date& a, const Date& b);
bool operator <= (const Date& a, const Date& b);

ostream& operator << (ostream& os, const Date& d);
istream& operator >> (istream& is, Date& dd);

Day day_of_week(const Date& d);
Date next_Sunday(const Date d);
Date next_workday(const Date& d);
int week_of_year(const Date& d);

}

#endif
