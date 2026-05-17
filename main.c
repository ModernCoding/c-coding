#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int main ()
{
  printf ("I like pizza!\n");
  printf ("It's really good!");

  int age = 25;
  printf ("\n\n");
  printf ("I am %d years old.", age);

  long double phi = (1.0L + sqrtl(5.0L)) / 2.0L;
  printf ("\n\n");
  printf ("The value of phi is: %.25Lf", phi);

  long double pi = 4.0L * atanl(1.0L);
  printf ("\n\n");
  printf ("The value of pi is: %.25Lf", pi);

  // long double phi2 = 2.0L * sinl(54.0L * pi / 180.0L);
  // printf ("\n\n");
  // printf ("The value of phi2 is: %.25Lf", phi2);

  char name[] = "Alice";
  printf ("\n\n");
  printf ("My name is %s.", name);

  bool is = 1 + 1 == 2;
  printf ("\n\n");
  printf ("Is 1 + 1 equal to 2? %s", is ? "Yes" : "No");

  bool isTheSame = 1 == "1";
  printf ("\n\n");
  printf ("Same types? %s", isTheSame ? "Yes" : "No");

  return 0;
}
