#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main () {

  srand (time (NULL));

  int min = 1;
  int max = 1000;
  int random = (rand () % (max - min + 1)) + min;

  int guess = 0;
  char chances[] = "chances";


  for (int i = 10; i > -1; --i) {

    if (i < 1) {
      printf ("You lost; the number was %d\n", random);
      break;
    }

    if (i < 2) {
      chances [ strlen (chances) - 1 ] = '\0';
    }

    printf (
      "Guess number between %d and %d; %d %s remaining:",
      min,
      max,
      i,
      chances
    );

    scanf (i < 10 ? " %d" : "%d", &guess);

    if (guess == random) {
      printf ("You won!");
      break;
    }

    printf ("It is %s!\n", guess < random ? "bigger" : "smaller");

  }


  return 0;

}