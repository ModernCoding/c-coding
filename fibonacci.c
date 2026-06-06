#include <stdio.h>
#include <time.h>


// prototypes

long long fibonacciLoop (int i);

void fibonacciRecursive (
  const int *max,
  int *i,
  long long *previous1,
  long long *previous2,
  long long *sum
);

long long get_nanoseconds (void);


// main

int main () {

  const int max = 88;

  long long tsFibLoopStart = get_nanoseconds ();
  printf ("%lld\n", fibonacciLoop (max));

  long long tsFibLoopStop = get_nanoseconds ();
  printf ("Loop took %lld ns\n", tsFibLoopStop - tsFibLoopStart);

  int i = 0;
  long long previous1 = 0;
  long long previous2 = 0;
  long long sum = 0;
  long long tsFibRecursiveStart = get_nanoseconds ();

  fibonacciRecursive (&max, &i, &previous1, &previous2, &sum);

  long long tsFibRecursiveStop = get_nanoseconds ();
  
  printf ("%lld\n", sum);
  
  printf (
    "Recursive took %lld ns\n",
    tsFibRecursiveStop - tsFibRecursiveStart
  );
  
  return 0;
}


// functions

long long fibonacciLoop (int i) {

  long long previous1 = 0, previous2 = 0, sum = 0;

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
  long long *previous1,
  long long *previous2,
  long long *sum
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


long long get_nanoseconds (void) {

  struct timespec ts;
  
  // CLOCK_MONOTONIC is preferred for measuring intervals
  clock_gettime (CLOCK_MONOTONIC, &ts);
  
  // Convert seconds to ns and add nanoseconds
  return (long long) ts.tv_sec * 1000000000LL
    + (long long) ts.tv_nsec;
}