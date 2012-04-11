/*
 * Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab.  When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference?
 */
#include <stdio.h>

#define TAB '\t'
#define SPACE ' '
#define LINE_BREAK '\n'
#define TAB_WIDTH 8

main(void)
{
  char c = 0;
  int i, start_i=-1;

  while (c != EOF)
    {
      /* process line */
      for (i=0;; i++)
        {
          c=getchar();
          /* capture spaces */
          if (c == SPACE && start_i < 0)
            start_i = i;
          /* calculate tab stops and output tabs */
          else if (c != SPACE)
            {
              /* enter transform mode */
              if (start_i >= 0)
                {
                  /* see if a tab can be applied */
                  while (start_i + (TAB_WIDTH - start_i % TAB_WIDTH) - 1 < i)
                    {
                      putchar(TAB);
                      start_i += TAB_WIDTH - start_i % TAB_WIDTH;
                    }
                  /* push out remaining spaces */
                  while (start_i++ < i)
                    putchar(SPACE);
                  start_i = -1;
                }
              putchar(c);
              if (c == LINE_BREAK)
                break;
            }
        }
    }
}
