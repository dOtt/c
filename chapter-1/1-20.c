/* 
 * Exercise 1-20. Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns.  Should n be a variable or a symbolic
 * parameter?
*/
#include <stdio.h>
#define TAB '\t'
#define SPACE ' '
#define LINE_BREAK '\n'
#define TABSTOP 8               /* set tab stop to 4 characters */

main () {
  char c = 0;
  int i, tab_i;

  while (c != EOF) {
    for (i=0; (c=getchar()) != LINE_BREAK;) {
      if (c == TAB) {
        tab_i = i % TABSTOP;
        while (tab_i++ < TABSTOP) {
          putchar(SPACE);
          ++i;
        }
      } else {
        putchar(c);
        ++i;
      }
    }
    if (c == LINE_BREAK) {
      putchar(c);
    }
  }
}
