#include <stdio.h>
#include <string.h>

int main() {

  int age = 0;
  float gpa = 0.0f;
  char grade = '\0';
  char name[30] = "";

  printf("Enter your age: ");
  scanf("%d", &age);

  printf("Enter your GPA: ");
  scanf("%f", &gpa);

  printf("Enter your grade: ");
  scanf(" %c", &grade);

  getchar(); // Consume the newline character left by previous scanf
  printf("Enter your name: ");
  fgets(name, sizeof(name), stdin);

  // Remove the newline character from the name string
  // name[strcspn(name, "\n")] = '\0';
  name[strlen(name) - 1] = '\0';

  printf("%s\n", name);
  printf("%d\n", age);
  printf("%f\n", gpa);
  printf("%c\n", grade);

  return 0;
}
