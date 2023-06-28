/* Grammar:
 *
 * Calculation:
 *  Statement
 *  Print
 *  Quit
 *  Calculation Statement
 * Statement:
 *  Declaration
 *  Assignment
 *  Expression
 * Print:
 *  ";"
 * Quit:
 *  "quit"
 * Declaration:
 *  "let" Name "=" Expression
 *  "const" Name "=" Expression
 * Assignment:
 *  Name "=" Expression
 * Expression:
 *  Term
 *  Expression "+" Term
 *  Expression "-" Term
 * Term:
 *  Primary
 *  Term "*" Primary
 *  Term "/" Primary
 *  Term "%" Primary
 * Primary:
 *  Number
 *  "("Expression")"
 *  "-" Primary
 *  "+" Primary
 *  Name
 *  Function"("Arguments")"
 * Function:
 *  "sqrt"
 *  "pow"
 * Arguments:
 *  Expression
 *  Argument","Expression
 * Number:
 *  [floating-point-literal]
 * Name:
 *  [alphabetic-char]
 *  Name[alphabetic-char]
 *  Name[digit-char]
 *  Name"_"
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
	//Token_stream() :full{false}, buffer{0} { }
	Token get();
	void putback(Token t) { buffer.push_back(t); }
	void ignore(char c);
private:
  vector<Token> buffer;
};

// Token kinds
const char let = 'L';
const char constant = 'C';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char sqrtfunc = 's';
const char powfunc = 'p';
// Keywords
const string declkey = "let";
const string constkey = "const";
const string quitkey = "quit";
// Builtin functions
const string sqrtkey = "sqrt";
const string powkey = "pow";

// get literals from the implemented grammar
Token Token_stream::get()
{
  if (!buffer.empty()) {
    Token t = buffer.back();
    buffer.pop_back();
    return t;
  }

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
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
			cin.putback(ch);
      if (s == declkey) return Token{let};
      if (s == constkey) return Token{constant};
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
  while (!buffer.empty() && buffer.back().kind != c)
    buffer.pop_back();

  if (!buffer.empty()) return;

	char ch {' '};
	while (ch != c && ch != '\n')
    ch = cin.get();

  return;
}

class Variable {
public:
	string name;
	double value;
  bool constant;
};

class Symbol_table {
  vector<Variable> var_table;
public:
  double get(string s);
  void set(string s, double d);
  bool is_declared(string s);
  void declare(string s, double d, bool c);
};

double Symbol_table::get(string s)
{
	for (const Variable& v : var_table)
    if (v.name == s) return v.value;
	error("get: undefined name ", s);
}

void Symbol_table::set(string s, double d)
{
	for (Variable& v : var_table)
		if (v.name == s) {
      if (v.constant) error(s, " is a constant");
			v.value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return true;
	return false;
}

void Symbol_table::declare(string s, double d, bool c)
{
  if (is_declared(s)) error(s, "is declared twice");
  var_table.push_back(Variable{s, d, c});
}

Symbol_table symbols;
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
		return symbols.get(t.name);
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

double assignment()
{
  Token t = ts.get();
  string var_name = t.name;
  if (!symbols.is_declared(var_name)) error(var_name, " has not been declared");

  ts.get(); // get rid of the "="
  double d = expression();
  symbols.set(var_name, d);
  return d;
}

double declaration()
{
  // Check if it's a constant declaration or not
  bool is_const = false;
  Token t = ts.get();
  if (t.kind == constant) is_const = true;

  // Check Declaration grammar after "let"/"const"
	Token t2 = ts.get();
	if (t2.kind != name) error("name expected in declaration");
	string var_name = t2.name;
	if (symbols.is_declared(var_name)) error(var_name, " declared twice");

	Token t3 = ts.get();
	if (t3.kind != '=') error("= missing in declaration of ", var_name);
	
  double d = expression();
	symbols.declare(var_name, d, is_const);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
  case constant:
		return declaration();
  case name:
  {
    Token t2 = ts.get();
    ts.putback(t2);
    ts.putback(t);
    if (t2.kind == '=') {
      return assignment();
    }
    return expression();
  }
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
  // Predefined variables and constants
  symbols.declare("k", 1000, false);
  symbols.declare("pi", 3.14159265359, true);
  symbols.declare("e", 2.71828182846, true);
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
