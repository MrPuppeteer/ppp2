#include "std_lib_facilities.h"
#include "9.exercise-05-09.Chrono.h"
#include "9.exercise-05-09.Lib.h"

namespace Lib {

ostream& operator << (ostream& os, Genre genre) {
  switch (genre) {
    case Genre::fiction:
      os << "Fiction";
      break;
    case Genre::nonfiction:
      os << "Non Fiction";
      break;
    case Genre::periodical:
      os << "Periodical";
      break;
    case Genre::biography:
      os << "Biography";
      break;
    case Genre::children:
      os << "Children";
      break;
    default:
      os << "Unknown Genre";
      break;
  }
  return os;
}
Book::Book(string isbn_i, string title_i, string author_i,
           Chrono::Date copyright_i, Genre genre_i)
  : isbn {isbn_i}, title {title_i}, author {author_i}, copyright {copyright_i},
    genre {genre_i}, is_checked_out {false}
{
  if (!is_isbn(isbn_i)) throw Invalid_ISBN{};
}

bool is_isbn(const string& isbn)
{
  int hypen {0};
  bool n {false};

  for (size_t i = 0; i < isbn.size(); ++i) {
    char c {isbn[i]};

    if (hypen < 3) {
      if (!isdigit(c)) {
        if (c == '-' && n) {
          ++hypen;
          n = false;
        }
        else {
          return false;
        }
      } else {
        n = true;
      }
    } else {
      if (i != (isbn.size() - 1)) return false;
      return (isdigit(c) || isalpha(c));
    }
  }
  return false;
}

bool operator == (const Book& a, const Book& b)
{
  return (a.get_isbn() == b.get_isbn());
}

bool operator != (const Book& a, const Book& b)
{
  return !(a == b);
}

ostream& operator << (ostream& os, const Book& book)
{
  os << book.get_title() << '\n'
     << "  Author: " << book.get_author() << '\n'
     << "  Genre: " << book.get_genre() << '\n'
     << "  ISBN: " << book.get_isbn() << '\n'
     << "  Copyright date: " << book.get_copyright() << '\n'
     << "  Checked: " << (book.checked_out() ? "OUT\n" : "IN\n");

  return os;
}

Patron::Patron(string name_i, string card_number_i):
  name {name_i}, card_number {card_number_i}, fees {0}
{
}

void Patron::set_fees(double fees_i)
{
  if (fees_i < 0)
    error("Negative fees");
  fees = fees_i;
}

bool owes_fees(const Patron& patron)
{
  return (patron.get_fees() != 0);
}

ostream& operator << (ostream& os, const Patron& patron)
{
  os << "User's name: " << patron.get_name() << '\n'
     << "Card Number: " << patron.get_card_number() << '\n'
     << "Fees owed: " << patron.get_fees() << '\n';

  return os;
}

bool operator == (const Patron& a, const Patron& b)
{
  return (a.get_card_number() == b.get_card_number());
}

bool operator != (const Patron& a, const Patron& b)
{
  return !(a == b);
}

void Library::add_book(Book book)
{
  if (is_book(book))
    throw Repeated_Book{};
  books.push_back(book);
}

void Library::add_patron(Patron patron)
{
  if (is_patron(patron))
    throw Repeated_Patron{};
  patrons.push_back(patron);
}

void Library::check_out(Book book, Patron patron, Chrono::Date date)
{
  Book& lib_book = get_book(book);
  Patron& lib_patron = get_patron(patron);
  if (lib_book.checked_out())
    throw Checked_Out_Book{};
  if (owes_fees(lib_patron))
    throw Patron_Owes_Fees{};
  
  transactions.push_back(Transaction{book, patron, date});
  lib_book.check_out();
  lib_patron.set_fees(10.0);
}

vector<string> Library::with_fees() const
{
  vector<string> names;
  
  for (Patron patron : patrons)
    if (owes_fees(patron))
      names.push_back(patron.get_name());

  return names;
}

void Library::print_books(ostream& os) const
{
  for (Book book : books)
    os << book;
}

void Library::print_patrons(ostream& os) const
{
  for (Patron patron : patrons)
    os << patron;
}

void Library::print_transactions(ostream& os) const
{
  for (Transaction transaction : transactions)
    os << transaction;
}

bool Library::is_book(const Book& book) const
{
  for (Book lib_book : books)
    if (lib_book == book)
      return true;
  return false;
}

Book& Library::get_book(const Book& book)
{
  for (Book& lib_book : books)
    if (lib_book == book)
      return lib_book;
  throw Invalid_Book{};
}

bool Library::is_patron(const Patron& patron) const
{
  for (Patron lib_patron : patrons)
    if (lib_patron == patron)
      return true;
  return false;
}

Patron& Library::get_patron(const Patron& patron)
{
  for (Patron& lib_patron : patrons)
    if (lib_patron == patron)
      return lib_patron;
  throw Invalid_Patron{};
}

// Transaction operators
ostream& operator<<(ostream& os, const Library::Transaction& transaction)
{
    os << transaction.patron.get_name() << " toke "
       << transaction.book.get_title() << " (ISBN: "
       << transaction.book.get_isbn() << ") on "
       << transaction.date << '\n';

    return os;
}
}
