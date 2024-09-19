#include "std_lib_facilities.h"
#include "9.exercise-05-09.Chrono.h"
#include "9.exercise-05-09.Lib.h"

using Lib::Book;
using Lib::Genre;
using Lib::Patron;
using Lib::Library;

void add_book(Library& lib, Book book)
{
  try {
    lib.add_book(book);
  }
  catch(Lib::Repeated_Book& e) {
    cerr << "Repeated Book \"" << book.get_title()
         << "\" with ISBN " << book.get_isbn() <<" !!!\n";
    }
}

void init_books(Library& lib)
{
  add_book(lib, Book{"04-6502-656-7",
                     "Gödel, Escher, Bach: An Eternal Golden Braid",
                     "Douglas Richard Hofstadter", 
                     Chrono::Date{1999, Chrono::Month::feb, 5},
                     Genre::nonfiction});
    
  add_book(lib, Book{"07-5640-474-6",
                     "The Name of the Wind",
                     "Patrick Rothfuss",
                     Chrono::Date{2008, Chrono::Month::apr, 1},
                     Genre::fiction});
    
  add_book(lib, Book{"17-8370-423-3",
                     "The Colour Monster",
                     "Anna Llenas",
                     Chrono::Date{2016, Chrono::Month::mar, 1},
                     Genre::children});

  add_book(lib, Book{"16-0010-483-5",
                     "Lock and Key, Vol 2: Head Games", 
                     "Joe Hill and Gabriel Rodriguez",
                     Chrono::Date{2009, Chrono::Month::sep, 29},
                     Genre::periodical});

  add_book(lib, Book{"03-4552-612-0",
                     "Jim Henson: The Biography",
                     "Brian Jay Jones",
                     Chrono::Date{2016, Chrono::Month::may, 10},
                     Genre::biography});
  // Error, repeated ISBN
  add_book(lib, Book{"03-4552-612-0",
                     "Jim Henson: The Biography",
                     "Brian Jay Jones",
                     Chrono::Date{2016, Chrono::Month::may, 10},
                     Genre::biography});
}

void add_patron(Library& lib, Patron patron)
{
  try {
    lib.add_patron(patron);
  }
  catch(Lib::Repeated_Patron& e) {
    cerr << "Repeated patron " << patron.get_name() << " with card number " 
         << patron.get_card_number() << " !!!\n";
    }
}

void init_patrons(Library& lib)
{
  add_patron(lib, Patron{"John Doe", "0000001"});
  add_patron(lib, Patron{"Peter Pan", "000032"});
  add_patron(lib, Patron{"Bobby Fisher", "000053"});
  add_patron(lib, Patron{"Max Rockatansky", "000104"});
  add_patron(lib, Patron{"Ivan Drago", "000156"});
  // Error, repeated card number
  add_patron(lib, Patron{"Bobby Fisher", "000053"});
}

void check_out(Library& lib, Book book, Patron patron, Chrono::Date date)
{
  try {
    lib.check_out(book, patron, date);
  }
  catch (Lib::Invalid_Patron& e) {
    cerr << "There is no patron " << patron.get_name() << " with card number "
         << patron.get_card_number() << " !!!\n";
  }
  catch (Lib::Invalid_Book& e) {
    cerr << "There is no book \"" << book.get_title() << "\" with ISBN "
         << book.get_isbn() << " !!!\n";
  }
  catch (Lib::Checked_Out_Book& e) {
    cerr << "Book \"" << book.get_title() << "\" with ISBN "
         << book.get_isbn() << " is already checked out !!!\n";
  }
  catch (Lib::Patron_Owes_Fees& e) {
    cerr << "Patron " << patron.get_name() << " with card number "
         << patron.get_card_number() << " owes fees !!!\n";
  }
}

void test_check_out(Library& lib)
{
  Book b1 {"16-0010-483-5",
           "Lock and Key, Vol 2: Head Games", 
           "Joe Hill and Gabriel Rodriguez",
           Chrono::Date{2009, Chrono::Month::sep, 29},
           Genre::periodical};

  Book b2 {"03-4552-612-0",
           "Jim Henson: The Biography",
           "Brian Jay Jones",
           Chrono::Date{2016, Chrono::Month::may, 10},
           Genre::biography};

  Book b3 {"17-8370-423-3",
           "The Colour Monster",
           "Anna Llenas",
           Chrono::Date{2016, Chrono::Month::mar, 1},
           Genre::children};

  Book b4 {"00-0000-000-0",
           "Fictional Book",
           "Fictional Author",
           Chrono::Date{2000, Chrono::Month::jan, 1},
           Genre::fiction};

  Patron p1 {"Peter Pan", "000032"};
  Patron p2 {"Bobby Fisher", "000053"};
  Patron p3 {"Max Rockatansky", "000104"};
  Patron p4 {"Invisible Man", "000000"};

  cout << '\n';
  // Test legitimate check outs
  cout << "Test legitimate check outs:\n";
  check_out(lib, b1, p1, Chrono::Date{2017, Chrono::Month::may, 24});
  check_out(lib, b2, p2, Chrono::Date{2017, Chrono::Month::may, 24});
  cout << "\nTRANSACTIONS ====\n\n";
  lib.print_transactions(cout);

  // Invalid Book
  cout << "\nTest invalid book:\n";
  check_out(lib, b4, p3, Chrono::Date{2017, Chrono::Month::may, 24});
  // Invalid Patron
  cout << "\nTest invalid patron:\n";
  check_out(lib, b3, p4, Chrono::Date{2017, Chrono::Month::may, 24});
  // Book already checked out
  cout << "\nTest book checked out:\n";
  check_out(lib, b2, p3, Chrono::Date{2017, Chrono::Month::may, 24});
  // Patron owes fees
  cout << "\nTest patron owes fees:\n";
  check_out(lib, b3, p2, Chrono::Date{2017, Chrono::Month::may, 24});

  // New legitimate check out
  cout << "\nNew legitimate check out:\n";
  check_out(lib, b3, p3, Chrono::Date{2017, Chrono::Month::may, 24});
  cout << "\nTRANSACTIONS ====\n\n";
  lib.print_transactions(cout);

  // Debtors
  cout << "\nLIBRARY DEBTORS ====\n\n";
  for (string name : lib.with_fees())
      cout << name << '\n';
}

int main()
try
{
    Library lib;

    init_books(lib);
    init_patrons(lib);
    
    cout << "\nLIBRARY BOOKS ===\n\n";
    lib.print_books(cout);
    cout << "\nLIBRARY PATRONS ===\n\n";
    lib.print_patrons(cout);

    test_check_out(lib);

    return 0;
}
catch(Chrono::Date::Invalid& e) {
  cerr << "Invalid date!\n";
  return 1;
}
catch(exception& e) {
  cerr << e.what() << '\n';
  return 2;
}
catch(...) {
  cerr << "Unknown exception!\n";
  return 3;
}
