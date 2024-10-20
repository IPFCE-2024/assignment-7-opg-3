#pragma once

double taylor_sine(double x, int n)
{
  double sum = x;
  double fact = 1;
  int sign = -1;
  // implement your function
for (int i = 3; i <= n; i += 2)
{
  fact = fact * i * (i-1);
  sum = sum + sign *pow(x,i)/fact;
  sign = sign * -1; 
}
  return sum;
}

