#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {

  double principal = 0.0;
  double rate = 0.0;
  int years = 0;
  int timesCompounded = 0;
  double total = 0.0;

  /*
    Compound interest formula:
    A = P(1 + r/n)^(nt)
    where:
    A = the future value of the investment/loan, including interest
    P = the principal investment amount (the initial deposit or loan amount)
    r = the annual interest rate (decimal)
    n = the number of times that interest is compounded per year
    t = the number of years the money is invested or borrowed for
  */

  printf("Enter the principal (P): ");
  scanf("%lf", &principal);
  getchar(); // Consume the newline character left by previous scanf

  printf("Enter the annual interest rate (r) in percentage: ");
  scanf("%lf", &rate);
  getchar(); // Consume the newline character left by previous scanf
  rate /= 100.0; // Convert percentage to decimal

  printf("Enter the number of years (t): ");
  scanf("%d", &years);
  getchar(); // Consume the newline character left by previous scanf

  printf("Enter the number of times interest is compounded per year (n): ");
  scanf("%d", &timesCompounded);
  getchar(); // Consume the newline character left by previous scanf

  // Calculate compound interest
  total = principal * pow(1 + rate / timesCompounded, timesCompounded * years);

  printf("The future value of the investment is: %.2f\n", total);

  return 0;

}
