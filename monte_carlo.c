#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>



float frandom() 
{
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

float mc_pi(int points)
{
  int i;
  int number=0;
  float a=0.0; //coordinates for using the function frandom
  float b=0.0;
  float r; //radius of the circle
  float pivalue;
  for (i = 0; i <= points; i++)
  {
    a = frandom();
    b = frandom();
    r = sqrt ((a * a) + (b * b)); // using straight line equation to find the distance between points (a,b) and (0,0)
    if(r < 1)
    {
      number = number + 1;
    }
  }
    
    pivalue = (float)(4 * number) / points;
      return pivalue;
}




int main(void)
{
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) 
  {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05)
  {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++)
  {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4))
    {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}






