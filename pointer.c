#include <stdio.h>


void birthday (int *age) {
  printf ("function\n");
  printf ("age == %p\n", age);
  printf ("*age == %d\n", *age);
  (*age)++;
}


int main () {
  
  int age = 25;
  int *pAge = &age;

  printf ("&age == %p\n", &age);
  printf ("pAge == %p\n", pAge);
  printf ("*pAge == %d\n", *pAge);
  printf ("&pAge == %p\n", &pAge);

  birthday (pAge);
  printf ("%d\n", age);

  birthday (&age);
  printf ("%d\n", age);

  return 0;

}