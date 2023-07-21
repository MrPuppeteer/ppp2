#include "std_lib_facilities.h"
#include "9.exercise-11.Chrono.h"

namespace Chrono {

Day operator + (const Day& d, int n)
{
  int r = int(d) + n;
  r %= 7;
  return Day(r);
}

Day& operator += (Day& d, int n)
{
  d = d + n;
  return d;
}

ostream& operator << (ostream& os, const Day& d)
{
  switch (d) {
    case Day::sun: os << "sun"; break;
    case Day::mon: os << "mon"; break;
    case Day::tue: os << "tue"; break;
    case Day::wed: os << "wed"; break;
    case Day::thu: os << "thu"; break;
    case Day::fri: os << "fri"; break;
    case Day::sat: os << "sat"; break;
    default: error("invalid day");
  }

  return os;
}

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

Month& operator ++ (Month& m)
{
  m = m + 1;
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

int month_days(Month m, bool leap)
{
  switch (m) {
    case Month::feb: 
      if (leap) return 29;
      return 28;
    case Month::jan:
    case Month::mar:
    case Month::may:
    case Month::jul:
    case Month::aug:
    case Month::oct:
    case Month::dec:
      return 31;
    case Month::apr:
    case Month::jun:
    case Month::sep:
    case Month::nov:
      return 30;
    default:
      error("invalid month");
      return -1;
  }
}

Date::Date(int yy, Month mm, int dd)
    :y{yy}, m{mm}, d{dd}
{
  if (!is_date(yy, mm, dd)) throw Invalid{};
}

const Date& default_date()
{
  static Date dd {2001, Month::jan, 1};
  return dd;
}

Date::Date():
  y {default_date().year()},
  m {default_date().month()},
  d {default_date().day()}
{
}

void Date::add_day(int n)
{
  if (n < 0)
    error("only positives increments allowed.");

  int ny {365};
  if (leapyear(y))
    ++ny;
  
  while (n >= ny) {
    ++y;
    n -= ny;
    if (leapyear(y))
      ny = 365;
    else
      ny = 366;
  }

  int nm {month_days(m, leapyear(y))};
  while (n >= nm) {
    ++m;
    n -= nm;
    nm = month_days(m, leapyear(y));
    if (m == Month::jan)
      ++y;
  }

  d = (d + n) % month_days(m, leapyear(y));
  if (d == 0)
    d = month_days(m, leapyear(y));
  if (d <= n)
    ++m;
}

void Date::add_month(int n)
{
  int nm = n % 12;
  int ny = n / 12;

  if (Month::dec < (int(m) + nm))
    ++ny;
  if (Month::jan > (int(m) + nm))
    --ny;
  m += nm;
  y += ny;
}

void Date::add_year(int n)
{
  if (m == Month::feb && d == 29 && !leapyear(y + n)) {
    m = Month::mar;
    d = 1;
  }
  y += n;
}

bool is_date(int y, Month m, int d)
{
  if (y < epoch_year) return false;
  if (d < 1) return false;

  if (m < Month::jan || m > Month::dec)
    return false;

  int days_in_month = 31;

  switch (m) {
    case Month::feb:
      days_in_month = (leapyear(y)) ? 29 : 28;
      break;
    case Month::apr:
    case Month::jun:
    case Month::sep:
    case Month::nov:
      days_in_month = 30;
      break;
    default:
      break;
  }

  return days_in_month >= d;
}

bool leapyear(int y)
{
  return ((y % 4 == 0) && !(y % 100 == 0) || (y % 400 == 0));
}

bool operator == (const Date& a, const Date& b)
{
  return a.year() == b.year()
      && a.month() == b.month()
      && a.day() == b.day();
}
bool operator != (const Date& a, const Date& b)
{
  return !(a == b);
}

bool operator < (const Date& a, const Date& b)
{
  if (a.year() != b.year()) return (a.year() < b.year());
  if (a.month() != b.month()) return (a.month() < b.month());
  return (a.day() < b.day());
}

bool operator <= (const Date& a, const Date& b)
{
  return ((a < b) || (a == b));
}

ostream& operator << (ostream& os, const Date& d)
{
  return os << '(' << d.year()
            << ',' << int(d.month())
            << ',' << d.day() << ')';
}

istream& operator >> (istream& is, Date& dd)
{
  int y, m, d;
  char ch1, ch2, ch3, ch4;
  is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
  if (!is) return is;
  if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
    is.clear(ios_base::failbit);
    return is;
  }

  dd = Date {y, Month(m), d};
  return is;
}

Day day_of_week(const Date& d)
{
  int y {d.year()};
  Day dow {epoch_dow};

  for (int i = epoch_year; i < y; ++i) {
    if (leapyear(i))
      dow += 366;
    else
      dow += 365;
  }

  Month m {d.month()};
  for(Month i = Month::jan; i < m; ++i) {
    dow += month_days(i, leapyear(y));
  }

  dow += (d.day() - 1);

  return dow;
}
Date next_Sunday(const Date d)
{
  Day dow {day_of_week(d)};
  Date r {d};
  r.add_day(7 - int(dow));
  return r;
}

Date next_workday(const Date& d)
{
  Day dow {day_of_week(d)};
  Date r {d};

  r.add_day(1);
  if (dow == Day::sat)
    r.add_day(1);
  if (dow == Day::fri)
    r.add_day(2);
  return r;
}

int week_of_year(const Date& d)
{
  Date wd {Date(d.year(), Month::jan, 1)};
  int week {1};

  wd = next_Sunday(wd);
  while (wd <= d) {
    wd = next_Sunday(wd);
    ++week;
  }

  return week;
}

}
