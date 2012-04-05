/* 
 * Exercise 1-20. Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns.  Should n be a variable or a symbolic
 * parameter?
*/
#include <stdio.h>
#define TABSTOP 4               /* set tab stop to 4 characters */

main () {
}

detab () {
  char c = 0;
  int i;

  while (c != EOF) {
    for (i=0; (c=getchar()) != '\n'; i++) {
      
    }
  }
}
