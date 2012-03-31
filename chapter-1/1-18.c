/* 
 * Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines.
 */
#include <stdio.h>
#define CHAR_BUF_SIZE 100       /* backtrack character buffer size */

main() {
  char c='\0', buff[CHAR_BUF_SIZE];
  int i, j, k, trail;

  i = j = k = trail = 0;
  while (c != EOF) {
    for (i=0; (c=getchar()) != '\n' && c != EOF; i++) {
      if (c == ' ' || c == '\t') { /* special characters */
        if (trail != 1) {          /* enter trail-mode if not in already */
          trail = 1;
        }
        if (j < CHAR_BUF_SIZE) { /* prevent overflow */
          buff[j++] = c;
        }
      } else {                  /* normal characters */
        if (trail == 1) {       /* exit trail-mode, also print all chars */
          for (k=0; k < j; k++) {
            putchar(buff[k]);
          }
          trail = j = 0;
        }
        putchar(c);
      }
    }
    /* line ends */
    if (c == '\n' && i != j) {  /* skip empty lines */
      putchar(c);
    }
    /* reset trail buffer */
    trail = j = 0;
  }
  /* input ends */
}
