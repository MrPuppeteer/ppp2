#include "std_lib_facilities.h"

enum class Month {
  jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator + (const Month& m, int n)
{
  int r = int(m) + n;
  r %= int(Month::dec);

  if (r == 0)
    return Month::dec;
  return Month(r);
}

Month operator - (const Month& m, int n)
{
  return (m + (-n));
}

Month& operator += (Month& m, int n)
{
  m = m + n;
  return m;
}

bool operator < (const Month& m, int n)
{
  return int(m) < n;
}

bool operator > (const Month& m, int n)
{
  return int(m) > n;
}

// simple Date (use Month type)
class Date {
public:
  class Invalid {};
  Date(int yy, Month mm, int dd); // check for valid date and initialize
  void add_day(int n);       // increase the Date by n days
  Month month() const { return m; }
  int day() const { return d; }
  int year() const { return y; }
private:
  int y;    // year
  Month m;
  int d;    // day
  bool is_valid();
};

Date::Date(int yy, Month mm, int dd)
    :y{yy}, m{mm}, d{dd}
{
  if (!is_valid()) throw Invalid{};
}

bool Date::is_valid()
{
  if (d < 1 || d > 31)
    return false;
  if (m < Month::jan || m > Month::dec)
    return false;
  return true;
}

void Date::add_day(int n)
{
  d += n % 31;

  int nm = (n / 31) % 12;
  int ny = n / (31 * 12);

  // check data overflows
  if (d > 31) {
    ++nm;
    d -= 31;
  }
  if (d < 1) {
    --nm;
    d += 31;
  }

  if (Month::dec < (int(m) + nm))
    ++ny;
  if (Month::jan > (int(m) + nm))
    --ny;

  m += nm;
  y += ny;
}

ostream& operator << (ostream& os, const Date& d)
{
  return os << '(' << d.year()
            << ',' << int(d.month())
            << ',' << d.day() << ')';
}

int main()
try {
  Date today {1978, Month::jun, 25}; // a Date variable (a named object)

  Date tomorrow {today};
  tomorrow.add_day(1);

  cout << "Today: " << today << '\n';
  cout << "Tomorrow: " << tomorrow << '\n';

  // Test
  Date test {2010, Month::dec, 31};
  test.add_day(6);   // 2011 Jan 6 
  cout << "6 Jan 2011? " << test << '\n';
  test.add_day(-6);  // 2010 Dec 31
  cout << "31 Dec 2010? " << test << '\n';
  test.add_day(-31);
  cout << "31 Nov 2010? " << test << '\n';
  test.add_day(-62);
  cout << "31 Sep 2010? " << test << '\n';

  test = Date {2010, Month::feb, 5};
  test.add_day(-7);  // 2010 Jan 29
  cout << "29 Jan 2010? " << test << '\n';
  test.add_day(7);   // 2010 Feb 5
  cout << "5 Feb 2010? " << test << '\n';
  test.add_day(31*12*10);
  cout << "5 Feb 2020? " << test << '\n';
  test.add_day(-31*12*10);
  cout << "5 Feb 2010? " << test << '\n';

  // Invalid date
  Date err {2004, Month::dec, -5};

  return 0;
}
catch (exception& e) {
  cerr << e.what() << '\n';
  return 1;
}
catch (Date::Invalid) {
  cerr << "Invalid date!\n";
  return 2;
}
catch (...) {
  cerr << "Unknown exception!\n";
  return 3;
}
