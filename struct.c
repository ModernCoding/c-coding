#include <stdio.h>
#include <stdbool.h>
#include <string.h>


struct Student {
  char name [50];
  int age;
  float gpa;
  bool isFullTime;
};


void printStudent (struct Student student);


int main () {

  struct Student student1 = { "Spongebob", 30, 2.5, true };
  struct Student student4 = { 0 };

  // strcpy (student4.name, "Sandy");
  strncpy (student4.name, "Sandy", 4);
  student4.age = 27;
  student4.gpa = 4.0;
  student4.isFullTime = true;

  printStudent (student1);

  printf ("%s\n", student1.name);
  printf ("%d\n", student1.age);
  printf ("%.2f\n", student1.gpa);
  printf ("%d\n", student1.isFullTime);

  printf ("%d\n", student1.isFullTime + student4.isFullTime);

  return 0;

}


void printStudent (struct Student student) {

  strcpy (student.name, "Toto");
  student.age = 33;

  printf ("%s\n", student.name);
  printf ("%d\n", student.age);
  printf ("%.2f\n", student.gpa);
  printf ("%d\n", student.isFullTime);

}