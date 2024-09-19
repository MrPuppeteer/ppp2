#include "std_lib_facilities.h"
#include "9.exercise-05-09.Chrono.h"

namespace Chrono {

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
  // see exercise-10
  return false;
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

// TODOS

Day day_of_week(const Date& d)
{
  return Day::sun;
}
Date next_Sunday(const Date d)
{
  return Date {
    default_date().year(),
    default_date().month(),
    default_date().day()
  };
}

Date next_weekday(const Date& d)
{
  return Date {
    default_date().year(),
    default_date().month(),
    default_date().day()
  };
}

}
