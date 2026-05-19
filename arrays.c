#include <stdio.h>


typedef char Initials [ 3 ];

enum Trolleybus {
  LAXOU = 3,
  PULNOY = 33,
  SEICHAMPS = 43
};


int main () {

  int numbers [] = { 4, 19 };

  printf("%d\n", numbers [ 0 ]);
  printf("%d\n", numbers [ 1 ]);

  // sizeof === in bytes

  printf ("%ld\n", sizeof (numbers));
  printf ("%ld\n", sizeof (numbers [ 0 ]));

  char fruits [] [ 10 ] = { "Apple", "Banana", "Coconut" };

  printf ("%ld\n", sizeof (fruits));
  printf ("%ld\n", sizeof (fruits [ 0 ]));

  Initials me = "MB\0";
  printf("%s\n", me);

  enum Trolleybus line = LAXOU;
  printf("%s\n", line);


  return 0;

}