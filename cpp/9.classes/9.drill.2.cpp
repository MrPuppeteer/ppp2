#include "std_lib_facilities.h"

// simple Date 
// guarantee initialization with constructor
// provide some notational convenience
struct Date {
  int y, m, d;  // year, month, day
  Date(int yy, int mm, int dd); // check for valid date and initialize
  void add_day(int n);       // increase the Date by n days
};

Date::Date(int yy, int mm, int dd)
{
  // check that (y,m,d) is a valid date 
  // if it is, use it to initialize dd
  // All months have 31 days for now
  if (dd < 1 || dd > 31)
    error("Invalid day");
  if (mm < 1 || mm > 12)
    error("Invalid month");

  y = yy;
  m = mm;
  d = dd;
}

void Date::add_day(int n)
{
  // increase dd by n days
  d += n;

  // check data overflows
  if (d > 31) {
    m += d / 31;
    d %= 31;
  }
  while (d < 1) {
    --m;
    d += 31;
  }

  if (m > 12) {
    y += m / 12;
    m %= 12;
  }
  while (m < 1) {
    --y;
    m += 12;
  }
}

ostream& operator << (ostream& os, const Date& d)
{
  return os << '(' << d.y
            << ',' << d.m
            << ',' << d.d << ')';
}

int main()
try {
  Date today {1978, 6, 25}; // a Date variable (a named object)

  Date tomorrow {today};
  tomorrow.add_day(1);

  cout << "Today: " << today << '\n';
  cout << "Tomorrow: " << tomorrow << '\n';

  // Test
  Date test {2010, 12, 31};
  test.add_day(6);   // 2011 Jan 6 
  cout << "6 Jan 2011? " << test << '\n';
  test.add_day(-6);  // 2010 Dec 31
  cout << "31 Dec 2010? " << test << '\n';
  test.add_day(-31);
  cout << "31 Nov 2010? " << test << '\n';
  test.add_day(-62);
  cout << "31 Sep 2010? " << test << '\n';

  test = Date {2010, 2, 5};
  test.add_day(-7);  // 2010 Jan 29
  cout << "29 Jan 2010? " << test << '\n';
  test.add_day(7);   // 2010 Feb 5
  cout << "5 Feb 2010? " << test << '\n';

  // Invalid date
  Date err {2004, 13, -5};

  return 0;
}
catch (exception& e) {
  cerr << e.what() << '\n';
  return 1;
}
catch (...) {
  cerr << "Unknown exception!\n";
  return 2;
}
