#include "std_lib_facilities.h"

int main()
{
  // int if = 7; // error: if is a keyword
  // int string = 7;  // this will lead to trouble

  // choose meaningful names
  // int mtbf;
  // int TLA;
  // int myw;
  // int NBV;

  // short names are meaningful when used conventionally
  int x;  // local variable or a parameter
  int i;  // loop index

  // these are probably ok
  int partial_sum;
  int element_count;
  int stable_partition;

  // these are probably too long
  // int the_number_of_elements;
  // int remaining_free_slots_in_symbol_table;

  // style: use underscore to separate words in an identifier
  // int element_count;
  // rather than
  // int elementCount;
  // int ElementCount;
  // never use names with all capital letters
  // int ALL_CAPITAL_LETTERS;
  // conventionally reserved for macros

  // use initial capital letter for user-defined types
  // Square s;
  // Graph g;
  // minimize confusion between udt and standard types

  // avoid easy to mistype, misread, or confuse
  // int Name, names, nameS;
  // int foo, f00;
  // int fl, f1, fI, fi;
}
