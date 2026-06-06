#include <stdio.h>
#include <time.h>


// prototypes

int fibonacciLoop (int i);
void fibonacciRecursive (int i, int *previous, int *sum);

long long get_milliseconds (void);


// main

int main () {

  printf ("%d\n", fibonacciLoop (0));
  printf ("%d\n", fibonacciLoop (1));
  printf ("%d\n", fibonacciLoop (2));
  printf ("%d\n", fibonacciLoop (3));
  printf ("%d\n", fibonacciLoop (4));
  printf ("%d\n", fibonacciLoop (5));

  int previous = 1;
  int sum = 0;

  fibonacciRecursive (0, &previous, &sum);
  printf ("%d\n", sum);

  previous = 1;
  sum = 0;

  fibonacciRecursive (1, &previous, &sum);
  printf ("%d\n", sum);

  previous = 1;
  sum = 0;

  fibonacciRecursive (2, &previous, &sum);
  printf ("%d\n", sum);

  previous = 1;
  sum = 0;

  fibonacciRecursive (3, &previous, &sum);
  printf ("%d\n", sum);

  previous = 1;
  sum = 0;

  fibonacciRecursive (4, &previous, &sum);
  printf ("%d\n", sum);

  previous = 1;
  sum = 0;

  fibonacciRecursive (5, &previous, &sum);
  printf ("%d\n", sum);

  
  return 0;
}


// functions

int fibonacciLoop (int i) {

  int buffer = 0, previous = 1, sum = 0;

  for (int j = i; j > 0; j--) {
    buffer = sum;
    sum += previous;
    previous = j < i ? buffer : sum;
  }

  return sum;

}


void fibonacciRecursive (int i, int *previous, int *sum) {

  int buffer = 0;

  if (i < 1) {
    return;
  }

  buffer = *sum;
  *sum += *previous;
  *previous = buffer > 0 ? buffer : *sum;

  return fibonacciRecursive (--i, previous, sum);

}


long long get_milliseconds (void) {

  struct timespec ts;
  
  // CLOCK_MONOTONIC is preferred for measuring intervals
  clock_gettime (CLOCK_MONOTONIC, &ts);
  
  // Convert seconds to ms and add nanoseconds converted to ms
  return (long long) ts.tv_sec * 1000
    + (long long) ts.tv_nsec / 1000000;
}