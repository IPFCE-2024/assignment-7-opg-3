#include "taylor_sine.h"
#include <math.h>
#include <stdio.h>

//sin(x) = x - (x^3/3!) + (x^5/5!) - (x^7/7!) + ....(x^n/n!)

int main()
{
  int n;
  double x, sine;

  printf("value of n:");
  scanf("%d", &n);
  printf("Value of x:");
  scanf("%lf", &x);

//kalder funktionen
sine = taylor_sine(x, n);
printf("sin(%.2f) = %.6f\n", x, sine);//vores funktion slutter ved n

//ANSI C sin funktion
printf("sin(x) = %f\n", sin(x)); //Deres funktion fortsætter uendeligt
//meget mere præcis ved højere tal som f.eks. x = 90

return 0;
}

