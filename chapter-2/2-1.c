/*
 * Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

main (void)
{
  /* print range statistics from headers */
  printf("prime type size ranges from header:\n");
  printf("  signed char: (%d, %d)\n", SCHAR_MIN, SCHAR_MAX);
  printf("  unsigned char: (%u, %u)\n", CHAR_MIN, CHAR_MAX);
  printf("  signed short int: (%d, %d)\n", SHRT_MIN, SHRT_MAX);
  printf("  unsigned short int: (%u, %u)\n", 0, USHRT_MAX);
  printf("  signed int: (%d, %d)\n", INT_MIN, INT_MAX);
  printf("  unsigned int: (%u, %u)\n", 0, UINT_MAX);
  printf("  signed long int: (%ld, %ld)\n", LONG_MIN, LONG_MAX);
  printf("  unsigned long int: (%lu, %lu)\n", 0, ULONG_MAX);

  /* print range statistics through computing, using progressive proximity
     stepping */
  printf("prime type size ranges through computing:\n");
  /* signed char */
  {
    signed char c, tmp, step, min, max;
    for (tmp = c = 1; (tmp <<= 1) > 0; c <<= 1);
    for (step = c >> 1; (tmp = c + 1) > c; step >>= 1)
      for (; (tmp = c + step) > c; c += step);
    max = c;
    min = max + 1;
    printf("  signed char: (%d, %d)\n", min, max);
  }
  /* unsigned char */
  {
    unsigned char c, tmp, step, min, max;
    for (tmp = c = 1; (tmp <<= 1) > c; c <<= 1);
    for (step = c >> 1; (tmp = c + 1) > c; step >>= 1)
      for (; (tmp = c + step) > c; c += step);
    max = c;
    min = 0;
    printf("  unsigned char: (%u, %u)\n", min, max);
  }
  /* signed short int */
  {
    signed short c, tmp, step, min, max;
    for (tmp = c = 1; (tmp <<= 1) > c; c <<= 1);
    for (step = c >> 1; (tmp = c + 1) > c; step >>= 1)
      for (; (tmp = c + step) > c; c += step);
    max = c;
    min = max + 1;
    printf("  signed short int: (%d, %d)\n", min, max);
  }
  /* unsigned short int */
  {
    unsigned short c, tmp, step, min, max;
    for (tmp = c = 1; (tmp <<= 1) > c; c <<= 1);
    for (step = c >> 1; (tmp = c + 1) > c; step >>= 1)
      for (; (tmp = c + step) > c; c += step);
    max = c;
    min = 0;
    printf("  unsigned short int: (%u, %u)\n", min, max);
  }
  /* signed int */
  {
    signed int c, tmp, step, min, max;
    for (tmp = c = 1; (tmp <<= 1) > c; c <<= 1);
    for (step = c >> 1; (tmp = c + 1) > c; step >>= 1)
      for (; (tmp = c + step) > c; c += step);
    max = c;
    min = max + 1;
    printf("  signed int: (%d, %d)\n", min, max);
  }
  /* unsigned int */
  {
    unsigned int c, tmp, step, min, max;
    for (tmp = c = 1; (tmp <<= 1) > c; c <<= 1);
    for (step = c >> 1; (tmp = c + 1) > c; step >>= 1)
      for (; (tmp = c + step) > c; c += step);
    max = c;
    min = 0;
    printf("  unsigned int: (%u, %u)\n", min, max);
  }
  /* signed long int */
  {
    signed long c, tmp, step, min, max;
    for (tmp = c = 1L; (tmp <<= 1) > c; c <<= 1);
    for (step = c >> 1; (tmp = c + 1L) > c; step >>= 1)
      for (; (tmp = c + step) > c; c += step);
    max = c;
    min = max + 1L;
    printf("  signed long int: (%ld, %ld)\n", min, max);
  }
  /* unsigned long int */
  {
    unsigned long c, tmp, step, min, max;
    for (tmp = c = 1L; (tmp <<= 1) > c; c <<= 1);
    for (step = c >> 1; (tmp = c + 1L) > c; step >>= 1)
      for (; (tmp = c + step) > c; c += step);
    max = c;
    min = 0;
    printf("  unsigned long int: (%lu, %lu)\n", min, max);
  }
  /* float */
  {
    float f, tmp, step, min, max;
    for (tmp = f = 1.0F; (tmp += f) > f && tmp != (1.0/0.0); f = tmp);
    for (step = f/2; step != 0; step /= 2)
      for (; (tmp = f + step) > f && tmp != (1.0/0.0); f = tmp);
    max = f;
    for (tmp = f = -1.0F; (tmp += f) < f && tmp != (-1.0/0.0); f = tmp);
    for (step = f/2; step != 0; step /= 2)
      for (; (tmp = f + step) < f && tmp != (-1.0/0.0); f = tmp);
    min = f;
    printf("  float: (%e, %e)\n", min, max);
  }
  /* double */
  {
    double d, tmp, step, min, max;
    for (tmp = d = 1.0; (tmp += d) > d && tmp != (1.0/0.0); d = tmp);
    for (step = d/2; step != 0; step /= 2)
      for (; (tmp = d + step) > d && tmp != (1.0/0.0); d = tmp);
    max = d;
    for (tmp = d = -1.0; (tmp += d) < d && tmp != (-1.0/0.0); d = tmp);
    for (step = d/2; step != 0; step /= 2)
      for (; (tmp = d + step) < d && tmp != (-1.0/0.0); d = tmp);
    min = d;
    printf("  double: (%e, %e)\n", min, max);
  }
  /* long double */
  {
    long double d, tmp, step, min, max;
    for (tmp = d = 1.0L; (tmp += d) > d && tmp != (1.0/0.0); d = tmp);
    for (step = d/2; step != 0; step /= 2)
      for (; (tmp = d + step) > d && tmp != (1.0/0.0); d = tmp);
    max = d;
    for (tmp = d = -1.0L; (tmp += d) < d && tmp != (-1.0/0.0); d = tmp);
    for (step = d/2; step != 0; step /= 2)
      for (; (tmp = d + step) < d && tmp != (-1.0/0.0); d = tmp);
    min = d;
    printf("  long double: (%Le, %Le)\n", min, max);
  }
}
