#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//wallis function definition and declaration
float wallis_pi(int limit)
{
  float square, number; 
  float pi = 1.0;
  int i;
  for(i = 0; i <= limit; i++)
  {
   
    square = i * i;
    number = 4 * square;
    pi = pi * number / (number - 1);
  }
  return pi * 2;
}

int main(void)
{
  float pi;
  for (int i=0; i<5; i++)
  {
    pi = wallis_pi(i);
    //function call
    if (!(fabs(pi - M_PI) > 0.15))
    {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) 
  {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) 
    {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}

