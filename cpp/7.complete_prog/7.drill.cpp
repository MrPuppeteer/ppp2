
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

/*
* Grammar:
*
* Calculation:
*   Statement
*   Print
*   Quit
*   Calculation Statement
* Statement:
*   Declaration
*   Expression
* Print:
*   ";"
* Quit:
*   "exit"
* Declaration:
*   let Name "=" Expression
* let:
*   "#"
* Expression:
*   Term
*   Expression "+" Term
*   Expression "-" Term
* Term:
*   Primary
*   Term "*" Primary
*   Term "/" Primary
*   Term "%" Primary
* Primary:
*   Number
*   "(" Expression ")"
*   "-" Primary
*   "+" Primary
*   Name
*   Function"("Arguments")"
* Function:
*   "sqrt"
*   "pow"
* Arguments:
*   Expression
*   Argument","Expression
* Number:
*   [floating-point-literal]
* Name:
*   [alphabetic-char]
*   Name[alphabetic-char]
*   Name[digit-char]
*
*/

#include "std_lib_facilities.h"

// Token are initialized depending on the needs of each kind
class Token {
public:
	char kind;
	double value;
	string name;

	Token(char ch) :kind{ch} { }
	Token(char ch, double val) :kind{ch}, value{val} { }
  Token(char ch, string n) :kind{ch}, name{n} { }
};

class Token_stream {
public:
	Token_stream() :full{false}, buffer{0} { }
	Token get();
	void putback(Token t) { buffer = t; full = true; }
	void ignore(char c);
private:
  bool full;
	Token buffer;
};

// Token kinds
const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char sqrtfunc = 's';
const char powfunc = 'p';
// Keywords
const string quitkey = "exit";
// Builtin functions
const string sqrtkey = "sqrt";
const string powkey = "pow";

// get literals from the implemented grammar
Token Token_stream::get()
{
	if (full) { full = false; return buffer; }

	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=': // symbol literals
  case ',': // separator for function argument
  case let:
		return Token{ch};
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': // numeric literals
	{ 
    cin.putback(ch);
	  double val;
	  cin >> val;
	  return Token{number, val};
	}
	default: // get string keywords, for declaration, quit, or variable names.
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == quitkey) return Token{quit};
      if (s == sqrtkey) return Token{sqrtfunc};
      if (s == powkey) return Token{powfunc};
			return Token{name, s};
		}
		error("Bad token");
	}
}

// clear input until c or newline is found
void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}

	full = false;

	char ch {' '};
	while (ch != c && ch != '\n')
    ch = cin.get();

  return;
}

class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;

double get_value(string s)
{
	for (const Variable& v : var_table)
    if (v.name == s) return v.value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (Variable& v : var_table)
		if (v.name == s) {
			v.value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return true;
	return false;
}

Token_stream ts;

double expression();

// Evaluates function of kind c. The next input must be "("Expression")".
double eval_func(char c)
{
  vector<double> args;  // store function arguments

  Token t = ts.get();
  if (t.kind != '(') error("'(' expected after function");
  
  switch (c) {
  case sqrtfunc:
    args.push_back(expression());
    break;
  case powfunc:
    args.push_back(expression());
    t = ts.get();
    if (t.kind != ',') error("Bad number of function arguments");
    args.push_back(expression());
    break;
  }

  t = ts.get();
  if (t.kind != ')') error("Bad number of function arguments");

  // Implement evaluation & restrictions
  switch (c) {
  case sqrtfunc:
    if (args[0] < 0) error("sqrt() is undefined for negative numbers");
    return sqrt(args[0]);
  case powfunc:
    return pow(args[0], narrow_cast<int>(args[1]));
  default:
    error("Function not implemented");
  }
}

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
    double d = expression();
	  t = ts.get();
	  if (t.kind != ')') error("')' expected");
    return d;
	}
	case '-': // negative numbers
		return - primary();
  case '+': // positive numbers
    return primary();
	case number:
		return t.value;
	case name: // get variable value from table
		return get_value(t.name);
  case sqrtfunc:
  case powfunc:
    return eval_func(t.kind);
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{
      double d = primary();
		  if (d == 0) error("divide by zero");
		  left /= d;
		  break;
		}
    case '%':
    {
      double d = primary();
      if (d == 0) error("divide by zero");
      left = fmod(left, d);
      break;
    }
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration()
{
  // Check Declaration grammar after "let"
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;
	if (is_declared(var_name)) error(var_name, " declared twice");

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);
	
  double d = expression();
	var_table.push_back(Variable{var_name, d});
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print); // discard input until a print command or newline is found
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true)
  try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get(); // remove print commands
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << '\n';
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
		clean_up_mess();  // discard remaining input and prompt user again
	}
}

int main()

try {
  var_table.push_back(Variable{"k", 1000});
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	return 2;
}
