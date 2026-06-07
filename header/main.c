#include <stdio.h>
#include "coord.h"


int main () {
  struct Coordinate c = new_coord (3, 33, 43);
  printf ("x = %d\n", c.x);
  printf ("y = %d\n", c.y);
  printf ("z = %d\n", c.z);
  return 0;
}