#include <stdio.h>
#include <time.h>


// prototypes

unsigned long long int fibonacciLoop (int i);

void fibonacciRecursive (
  const int *max,
  int *i,
  unsigned long long int *previous1,
  unsigned long long int *previous2,
  unsigned long long int *sum
);

unsigned long long int get_nanoseconds (void);


// main

int main () {

  int max = 0;

  printf ("Enter your max: ");
  scanf ("%d", &max);

  getchar ();
    /*
      Consume the newline character left by previous scanf
    */

  while (max > -1) {

    printf ("\n\nPosition nr. %d\n", max);

    unsigned long long int tsFibLoopStart = get_nanoseconds ();
    printf ("%llu\n", fibonacciLoop (max));

    unsigned long long int tsFibLoopStop = get_nanoseconds ();
    
    const unsigned long long int tsFibLoop
      = tsFibLoopStop - tsFibLoopStart;
    
    printf ("Loop took %llu ns\n", tsFibLoop);

    int i = 0;
    unsigned long long int previous1 = 0;
    unsigned long long int previous2 = 0;
    unsigned long long int sum = 0;
    unsigned long long int tsFibRecursiveStart = get_nanoseconds ();

    fibonacciRecursive (&max, &i, &previous1, &previous2, &sum);

    unsigned long long int tsFibRecursiveStop = get_nanoseconds ();
    
    const unsigned long long int tsFibRecursive
      = tsFibRecursiveStop - tsFibRecursiveStart;
    
    printf ("%llu\n", sum);
    printf ("Recursive took %llu ns\n", tsFibRecursive);
    
    if (tsFibRecursive == tsFibLoop) {
      printf ("SAME SPEED!");
    }

    else {

      printf (
        "RECURSIVE is %Lf times %s than LOOP\n",

        tsFibRecursive > tsFibLoop
          ? (long double) tsFibRecursive / (long double) tsFibLoop
          : (long double) tsFibLoop / (long double) tsFibRecursive,

        tsFibRecursive < tsFibLoop ? "faster" : "slower"
      );

    } 

    max--;

  }
  
  return 0;
}


// functions

unsigned long long int fibonacciLoop (int i) {

  unsigned long long int previous1 = 0, previous2 = 0, sum = 0;

  for (int j = 0; j <= i; j++) {
    sum = j == 1 ? 1 : previous1 + previous2;
    previous1 = previous2;
    previous2 = sum;
  }

  return sum;

}


void fibonacciRecursive (
  const int *max,
  int *i,
  unsigned long long int *previous1,
  unsigned long long int *previous2,
  unsigned long long int *sum
) {

  if (*i > *max) {
    return;
  }

  *sum = *i == 1 ? 1 : *previous1 + *previous2;
  *previous1 = *previous2;
  *previous2 = *sum;
  (*i)++;

  return fibonacciRecursive (max, i, previous1, previous2, sum);

}


unsigned long long int get_nanoseconds (void) {

  struct timespec ts;
  
  // CLOCK_MONOTONIC is preferred for measuring intervals
  clock_gettime (CLOCK_MONOTONIC, &ts);
  
  // Convert seconds to ns and add nanoseconds
  return (unsigned long long int) ts.tv_sec * 1000000000LL
    + (unsigned long long int) ts.tv_nsec;
}