#include "std_lib_facilities.h"

int main() {
  // compute area:
  int length = 20;          // a  literal integer (used to initialize a variable)
  int width = 40;
  int area = length*width;  // a  multiplication

  // compute perimeter:
  // we can use parentheses to group expressions
  int perimeter = (length+width)*2;     // add then multiply
  // without parentheses (clumsy):
  // int perimeter = length*2+width*2;
  // we might even have made this mistake:
  // int perimeter = length+width*2;
  
  // overuse of parentheses decrease readability
  // (a*b)+(c/d)
  // ugly code slows down reading and comprehension

  // don't write absurdly complicated expressions
  // a*b+c/d*(e-f/g)/h+7 // too complicated
  // and always try to choose meaningful names
}
