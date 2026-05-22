#include <stdio.h>
#include <stdbool.h>


struct Student {
  char name [50];
  int age;
  float gpa;
  bool isFullTime;
};


int main () {

  struct Student student1 = { "Spongebob", 30, 2.5, true };

  printf ("%s\n", student1.name);
  printf ("%d\n", student1.age);
  printf ("%.2f\n", student1.gpa);
  printf ("%d\n", student1.isFullTime);

  return 0;

}