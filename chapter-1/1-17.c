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
  while((my_readline()) > 0);
}

/* Read a line, then return the number of readed chars. */
int my_readline(){
  char line[LINE_LIMIT], c;
  int i;

  for (i=0; i<LINE_LIMIT && (c=getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }
  if (i == LINE_LIMIT) {
    for (i=0; i <LINE_LIMIT; i++) {
      putchar(line[i]);
    }
    while ((c=getchar()) != EOF && c != '\n') {
      putchar(c);
    }
    if (c == '\n')
      putchar(c);
  }

  return i;
}
