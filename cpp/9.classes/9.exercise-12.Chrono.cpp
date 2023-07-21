#include "std_lib_facilities.h"
#include "9.exercise-12.Chrono.h"

namespace Chrono {

Day operator + (const Day& d, int n)
{
  int r {int(d) + n};
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
  int r {int(m) + n};
  r %= int(Month::dec);

  if (r == 0)
    return Month::dec;
  return Month(r);
}

Month& operator ++ (Month& m)
{
  m = m + 1;
  return m;
}

int month_days(Month m, int y)
{
  switch (m) {
    case Month::feb: 
      if (leapyear(y)) return 29;
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
{
  if (!is_date(yy, mm, dd)) throw Invalid{};
  days_since_epoch = Chrono::get_days_since_epoch(yy, mm, dd);
}

Date::Date(long int days) : days_since_epoch {days}
{
  if (days_since_epoch < 0) throw Invalid{};
}

Date::Date():days_since_epoch {0} { };

int Date::day() const
{
  return days_since_epoch - Chrono::get_days_since_epoch(year(), month(), 1)
         + 1;
}

Month Date::month() const
{
  int y {year()};
  long int remaining_days {
    days_since_epoch - Chrono::get_days_since_epoch(year(), Month::jan, 1)
  };

  Month m {Month::jan};
  while (remaining_days >= Chrono::month_days(m, y)) {
    remaining_days -= Chrono::month_days(m, y);
    ++m;
  }

  return m;
}

int Date::year() const
{
  long int y {days_since_epoch / 365};
  long int remaining_days {days_since_epoch - (y*365)};
  if ((remaining_days - n_leaps(epoch_year + y)) < 0)
    --y;
  return (epoch_year + y);
}

long int Date::get_days_since_epoch() const
{
  return days_since_epoch;
}

void Date::add_day(int n)
{
  if (n < 0)
    error("only positives increments allowed.");

  days_since_epoch += n;
}

void Date::add_month(int n)
{
  if (n < 0)
    error("only positives increments allowed.");

  int y {year()};
  Month m {month()};
  bool last {month_days(m, y) == day()};

  for (int i = 0; i < n; ++i) {
    days_since_epoch += month_days(m, y);
    ++m;
    if (m == Month::jan)
      ++y;
  }

  if (last && (day() < 4))
    days_since_epoch -= day();
}

void Date::add_year(int n)
{
  add_month(n*12);
}

bool is_date(int y, Month m, int d)
{
  if (y < epoch_year) return false;
  if (d < 1) return false;

  if (m < Month::jan || m > Month::dec)
    return false;

  int month_days {31};

  switch (m) {
    case Month::feb:
      month_days = (leapyear(y)) ? 29 : 28;
      break;
    case Month::apr:
    case Month::jun:
    case Month::sep:
    case Month::nov:
      month_days = 30;
      break;
    default:
      break;
  }

  return month_days >= d;
}

bool leapyear(int y)
{
  return ((y % 4 == 0) && !(y % 100 == 0) || (y % 400 == 0));
}

int n_leaps(int y)
{
  if (y < epoch_year)
    throw Date::Invalid{};

  int n {0};
  for (int i = epoch_year; i < y; ++i)
    if (leapyear(i)) ++n;
  return n;
}

long int get_days_since_epoch(int y, Month m, int d)
{
  if (!is_date(y, m, d))
    throw Date::Invalid{};

  int days_since_epoch {0};

  days_since_epoch += (y - epoch_year) * 365 + n_leaps(y);
  for (Month i = Month::jan; i < m; ++i)
    days_since_epoch += month_days(i, y);

  return (days_since_epoch + d - 1);
}

bool operator == (const Date& a, const Date& b)
{
  return a.get_days_since_epoch() == b.get_days_since_epoch();
}
bool operator != (const Date& a, const Date& b)
{
  return !(a == b);
}

bool operator <= (const Date& a, const Date& b)
{
  return a.get_days_since_epoch() <= b.get_days_since_epoch();
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
  return epoch_dow + (d.get_days_since_epoch() % 7);
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
