#include <stdio.h>

#include "mem.h"

int
main(int argc, char *argv[])
{
  int *i;

  i = (int *)mem_alloc(sizeof(*i));

  *i = 12345678;
  printf("*i = %d\n", *i);

  return 0;
}
