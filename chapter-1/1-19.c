/*
 * Exercise 1-19. Write a function reverse(s) that reverses the character string
 * s. Use it to write a program that reverses its input a line at a time.
 */
#include <stdio.h>
#define LINE_LEN 1000           /* line buffer length */

main(void) {
  char buf[LINE_LEN];

  int i;
  while (my_getline(buf, LINE_LEN) > 0) {
    my_reverse(buf);
    for (i=0; buf[i] != '\0'; i++) {
      putchar(buf[i]);
    }
    if (buf[i-1] != '\n') {
      putchar('\n');
    }
  }
  return;
}

/* only revese non line feed characters. */
int my_reverse(char s[]) {
  int len;

  /* accquire char array length */
  for (len=0; s[len] != '\0' && s[len] != '\n'; len++);
  int i;
  char c;
  for (i = 0; i < len/2; i++) {
    c = s[i];
    s[i] = s[len-1-i];
    s[len-1-i] = c;
  }

  return;
}

/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
  int c, i;
  for (i=0; (c=getchar())!=EOF && c!='\n'; ++i) {
      s[i] = c;
  }
  if (i < lim-1 && c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
