#include <stdio.h>
#include <string.h>

#include "mem.h"

struct combo1 {
  double d;
  char tc[11];
  int i;
} __attribute__ ((packed));

int
main(int argc, char *argv[])
{
  int *i;
  double *d;
  struct combo1 *sc1;

  i = (int *)mem_alloc(sizeof(*i));
  *i = 12345678;
  printf("*i = %d\n", *i);

  d = (double *)mem_alloc(sizeof(*d));
  *d = 12345.678910111213;
  printf("*d = %f\n", *d);

  sc1 = (struct combo1 *)mem_alloc(sizeof(*sc1));
  sc1->d = 54321.131211109876;
  sc1->i = 87654321;
  strncpy(sc1->tc, "dupa12345!", sizeof(((struct combo1 *)0)->tc));
  printf("sc1->d = %f, sc1->tc = %s, sc1->i = %d\n", sc1->d, sc1->tc, sc1->i);

  mem_free(i);

  struct combo1 *sc2;
  sc2 = (struct combo1 *)mem_alloc(sizeof(*sc2));
  sc2->d = 11111.22222;
  sc2->i = 1010101010;
  strncpy(sc2->tc, "pass1234!", sizeof(((struct combo1 *)0)->tc));
  printf("sc2->d = %f, sc2->tc = %s, sc2->i = %d\n", sc2->d, sc2->tc, sc2->i);

  return 0;
}
