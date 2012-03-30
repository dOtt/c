/* 
 * Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines.
 */
#include <stdio.h>
#define CHAR_BUF 100            /* backtrack character buffer size */

main() {
  char c, char buff[CHAR_BUF];
  int i, j;
  int bp=-1, trail;

  while ((c=getchar()) != EOF) {
    for (i=0; i != '\n'; i++) {
      if (trail == 1) {
        buff[j++] = c;
      }
      if ((c == ' ' || c == '\t') && bp == -1) {
        bp = i;
      }
