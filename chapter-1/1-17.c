/* 
 * Exercise 1-17.  
 *
 * Write a program to print all input lines that are longer than 80 characters.
 */
#include <stdio.h>
#define LINE_LIMIT              /* maximum input line length */

int my_readline();

/* print the longest input line */
main()
{
  char line[LINE_LIMIT];

  while ((len = my_readline()) > 0) {
  }
}

int my_readline(char line[]) {
  for (int i=0; i < LINE_LIMIT && (c=getchar())!=EOF && c!='\n'; i++)
    
  if (i < LINE_LIMIT) {
    return i;
  }
  
}
    

  int len;                      /*current line length */
  int max;                      /*maximum length seen so far */
  char line[MAXLINE];           /* current input line */
  char longest[MAXLINE];        /* longest line saved here */

  max = 0;
  while ((len = my_getline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)                  /* there was a line */
    printf("longest line[%d chars]: %s", max, longest);
  return 0;
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
  s[lim-1] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
