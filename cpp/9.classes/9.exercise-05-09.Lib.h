#include "std_lib_facilities.h"
#include "9.exercise-05-09.Chrono.h"

#ifndef LIBRARY_H
#define LIBRARY_H

namespace Lib {

class Invalid_ISBN {};
class Invalid_Book {};
class Repeated_Book {};
class Invalid_Patron {};
class Repeated_Patron {};
class Patron_Owes_Fees {};
class Checked_Out_Book {};

enum class Genre {
  fiction, nonfiction, periodical, biography, children
};

ostream& operator << (ostream& os, Genre genre);

class Book {
public:
  Book(string isbn_i, string title_i, string author_i, Chrono::Date copyright_i,
       Genre genre_i);
  void check_out() { is_checked_out = true; }
  void check_in() { is_checked_out = false; }

  const string& get_isbn() const { return isbn; }
  const string& get_title() const { return title; }
  const string& get_author() const { return author; }
  const Chrono::Date& get_copyright() const { return copyright; }
  const Genre& get_genre() const { return genre; }
  const bool checked_out() const { return is_checked_out; }
private:
  string isbn, title, author;
  Chrono::Date copyright;
  Genre genre;
  bool is_checked_out;
};

bool is_isbn(const string& isbn);

bool operator == (const Book& a, const Book& b);
bool operator != (const Book& a, const Book& b);
ostream& operator << (ostream& os, const Book& book);

class Patron {
public:
  Patron(string name_i, string card_number_i);

  void set_fees(double fees_i);

  const string& get_name() const { return name; }
  const string& get_card_number() const { return card_number; }
  const double get_fees() const { return fees; }
private:
  string name;
  string card_number;
  double fees;
};

bool owes_fees(const Patron& patron);

ostream& operator << (ostream& os, const Patron& patron);
bool operator == (const Patron& a, const Patron& b);
bool operator != (const Patron& a, const Patron& b);

class Library {
public:
  struct Transaction {
    Book book;
    Patron patron;
    Chrono::Date date;
  };

  void add_book(Book book);
  void add_patron(Patron patron);
  void check_out(Book book, Patron patron, Chrono::Date date);

  vector<string> with_fees() const;
  void print_books(ostream& os) const;
  void print_patrons(ostream& os) const;
  void print_transactions(ostream& os) const;
private:
  bool is_book(const Book& book) const;
  Book& get_book(const Book& book);
  bool is_patron(const Patron& patron) const;
  Patron& get_patron(const Patron& patron);

  vector<Book> books;
  vector<Patron> patrons;
  vector<Transaction> transactions;
};

ostream& operator << (ostream& os, const Library::Transaction& transaction);

}

#endif
