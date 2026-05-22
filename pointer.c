#include <stdio.h>


void birthday (int *age) {
  printf ("%p\n", age);
  printf ("%d\n", *age);
  (*age)++;
}


int main () {
  
  int age = 25;
  int *pAge = &age;

  printf ("%p\n", &age);
  printf ("%p\n", pAge);
  printf ("%p\n", &pAge);

  birthday (pAge);
  printf ("%d\n", age);

  birthday (&age);
  printf ("%d\n", age);

  return 0;

}