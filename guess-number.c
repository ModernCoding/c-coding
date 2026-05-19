#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// prototypes 

void input (int min, int max, int random, int i);


// main

int main () {

  srand (time (NULL));

  int min = 1;
  int max = 1000;
  int random = (rand () % (max - min + 1)) + min;

  input (min, max, random, 10);
  return 0;

}


// functions

void input (int min, int max, int random, int i) {

  if (i < 1) {
    printf ("You lost; the number was %d\n", random);
    return;
  }


  printf (
    "Guess number between %d and %d; %d %s remaining: ",
    min,
    max,
    i,
    i < 2 ? "chance" : "chances"
  );


  int guess = 0;

  scanf (i < 10 ? " %d" : "%d", &guess);

  if (guess == random) {
    printf ("You won!\n");
    return;
  }

  printf ("It is %s!\n\n", guess < random ? "bigger" : "smaller");
  return input (min, max, random, --i);

}