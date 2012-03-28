/* 
 * Exercise 1-17.  
 *
 * Write a program to print all input lines that are longer than 80 characters.
 */
#include <stdio.h>
#define LINE_LIMIT 5            /* maximum input line length */

int my_readline();

/* print the longest input line */
main()
{
  char line[LINE_LIMIT];
  int i, j;
  char c;

  for (i=0; i<LINE_LIMIT && (c=getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }
  if (i == LINE_LIMIT) {
    for (j=0; j <LINE_LIMIT; j++) {
      putchar(line[j]);
    }
    while ((c=getchar()) != EOF && c != '\n') {
      putchar(c);
    }
    if (c == '\n')
      putchar(c);
  }
}
