#include "std_lib_facilities.h"

class Token
{
public:
  char kind;     // what kind of token
  double value;  // for numbers: a value
  Token(char ch) // make a Token from a char
      : kind(ch), value(0)
  {
  }
  Token(char ch, double val) // make a Token from a char and a double
      : kind(ch), value(val)
  {
  }
};

class Token_stream
{
public:
  Token_stream();        // make it reads from cin
  Token get();           // get a Token
  void putback(Token t); // put a Token back
private:
  bool full;    // is there a Token in the buffer?
  Token buffer; // where we store a 'putback' Token
};

Token_stream::Token_stream()
    : full(false), buffer(0) // no Token in buffer
{
}

void Token_stream::putback(Token t)
{
  if (full)
    error("putback() into a a full buffer");
  buffer = t;  // copy t to buffer
  full = true; // buffer is now full
}

Token Token_stream::get()
{
  if (full)
  {
    full = false;
    return buffer;
  }
  char ch;
  cin >> ch;

  switch (ch)
  {
  case ';': // for "print"
  case 'q': // for "quit"
  case '(':
  case ')':
  case '+':
  case '-':
  case '*':
  case '/':
  case '{':
  case '}':
    return Token{ch}; // let each character represent itself
  case '.':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  {
    cin.putback(ch);
    double val;
    cin >> val;
    return Token{'8', val};
  }
  default:
    throw runtime_error("Bad Token");
  }
}

Token_stream ts; // provides get() and putback()

double expression(); // declaration so that primary() can call expression()

double primary() // deal with numbers and parentheses
{
  Token t = ts.get();
  switch (t.kind)
  {
  case '(': // handle '(' expression ')'
  {
    double d = expression();
    t = ts.get();
    if (t.kind != ')')
      throw runtime_error("')' expected");
    return d;
  }
  case '{': // handle '{' expression '}'
  {
    double d = expression();
    t = ts.get();
    if (t.kind != '}')
      throw runtime_error("'}' expected");
    return d;
  }
  case '8':         // we use '8' to represent a number
    return t.value; // return the number's value
  default:
    throw runtime_error("primary expected");
  }
}

double term() // deal with * and /
{
  double left = primary();
  Token t = ts.get(); // get the next token

  while (true)
  {
    switch (t.kind)
    {
    case '*':
      left *= primary();
      t = ts.get();
      break;
    case '/':
    {
      double d = primary();
      if (d == 0)
        throw runtime_error("divide by zero");
      left /= d;
      t = ts.get();
      break;
    }
    default:
      ts.putback(t);
      return left;
    }
  }
}

double expression() // deal with + and -
{
  double left = term(); // read and evaluate a Term

  Token t = ts.get(); // get the next token

  while (true)
  {
    switch (t.kind)
    {
    case '+':
      left += term(); // evaluate Term and add
      t = ts.get();
      break;
    case '-':
      left -= term(); // evaluate Term and subtract
      t = ts.get();
      break;
    default:
      ts.putback(t); // finally: no more + or -: return the answer
      return left;
    }
  }
}

int main() // main loop and deal with errors
try
{
  double val = 0;
  cout << "Welcome to our simple calculator.\n"
       << "Please enter expressions using floating-point numbers.\n"
       << "Currently +, -, *, /, (), and {} are supported.\n"
       << "Insert ; to evaluate the expression. Enter q to exit.\n";
  while (cin)
  {
    Token t = ts.get();

    if (t.kind == 'q')
      break;
    if (t.kind == ';')
      cout << "=" << val << '\n';
    else
    {
      ts.putback(t);
      val = expression();
    }
  }
  keep_window_open();
  return 0;
}
catch (exception &e)
{
  cerr << e.what() << '\n';
  keep_window_open();
  return 1;
}
catch (...)
{
  cerr << "Oops: unknown exception!\n";
  keep_window_open();
  return 2;
}
