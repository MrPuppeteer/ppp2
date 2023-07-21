#include "std_lib_facilities.h"

// simple Date (too simple?)
struct Date {
  int y;  // year
  int m;  // month in year
  int d;  // day of month
};

void init_day(Date& dd, int y, int m, int d)
{
  // check that (y,m,d) is a valid date 
  // if it is, use it to initialize dd
  // All months have 31 days for now
  if (d < 1 || d > 31)
    error("Invalid day");
  if (m < 1 || m > 12)
    error("Invalid month");

  dd.y = y;
  dd.m = m;
  dd.d = d;
}

void add_day(Date& dd, int n)
{
  // increase dd by n days
  dd.d += n;

  // check data overflows
  if (dd.d > 31) {
    dd.m += dd.d / 31;
    dd.d %= 31;
  }
  while (dd.d < 1) {
    --dd.m;
    dd.d += 31;
  }

  if (dd.m > 12) {
    dd.y += dd.m / 12;
    dd.m %= 12;
  }
  while (dd.m < 1) {
    --dd.y;
    dd.m += 12;
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
  Date today; // a Date variable (a named object)
  init_day(today, 1978, 6, 25);

  Date tomorrow {today};
  add_day(tomorrow, 1);

  cout << "Today: " << today << '\n';
  cout << "Tomorrow: " << tomorrow << '\n';

  // Test
  Date test;
  init_day(test, 2010, 12, 31);
  add_day(test, 6);   // 2011 Jan 6 
  cout << "6 Jan 2011? " << test << '\n';
  add_day(test, -6);  // 2010 Dec 31
  cout << "31 Dec 2010? " << test << '\n';
  add_day(test, -31);
  cout << "31 Nov 2010? " << test << '\n';
  add_day(test, -62);
  cout << "31 Sep 2010? " << test << '\n';

  init_day(test, 2010, 2, 5);
  add_day(test, -7);  // 2010 Jan 29
  cout << "29 Jan 2010? " << test << '\n';
  add_day(test, 7);   // 2010 Feb 5
  cout << "5 Feb 2010? " << test << '\n';

  // Invalid date
  Date err;
  init_day(err, 2004, 13, -5);

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
