#include <stdio.h>
#include <stdbool.h>
#include <string.h>


typedef struct {
  char model [25];
  int year;
  int price;
} Car;


void printCar (Car cars [], int max, int i);


int main () {

  Car cars [] = {
      { "Mustang", 2025, 32000 },
      { "Corvette", 2026, 68000 },
      { "Challenger", 2024, 29000 }
    };

  printCar (cars, sizeof (cars) / sizeof (cars [ 0 ]), 0);
  return 0;

}


void printCar (Car cars [], int max, int i) {

  if (i >= max) { return; }

  printf (
    "%s %d $%d\n",
    cars [ i ].model,
    cars [ i ].year,
    cars [ i ].price
  );

  return printCar (cars, max, ++i);

}