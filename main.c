//AGUDELO PAULO GRIAN
//A simple c program
//to implement the use of functions
//and to solve quadratics (quick and dirty version)
#include <math.h>
#include <stdio.h>



int main(void) {
  //function declarationsssss
  double findNegative(double a, double b, double c);
  double findPositive(double a, double b, double c);
  int getDiscriminant(double a, double b, double c);

  //optional problems
  double solveLinear(double b, double c);

  //variable declarationsssss
  double a =0;
  double b =0;
  double c =0;
  int descriminant;

  printf("Please enter the value for A: B: C: separated by a space or enter\n");
  scanf( "%lf %lf %lf", &a, &b, &c );
  
  printf("Value of:: A:%.1lf, B:%.1lf, C:%.1lf\n", a, b,c);

  descriminant = getDiscriminant(a, b, c);

  if( (int)a != 0)
  {
    //check and validate inputs
    switch(descriminant)
    {
      case 1:
              printf("Desc was positive!\n");
              printf("A positive discriminant indicates that the quadratic has two distinct real number solutions\n");

              printf("Minus side::->%.1lf\n", findNegative(a, b, c));
              printf("Plus side::->%.1lf", findPositive(a, b, c));
              break;
      case -1:
              //use a special way to find the solutions over here 
              printf("Desc was negative and has complex solutions\n");
              printf("%.1lf/%.1lf ± √%.1lfi/%.1lf", (b *-1), (2*a) , ( ( (b*b) - (4 * a * c) ) * -1), (a*2));
              break;
      case 0:
              printf("Equation has only one solution\n");
              printf("%.1lf\n", findNegative(a, b, c));            
              break;

    }
    
  }
  else if ( (int) a == 0 && (int) b == 0 && (int) c ==0 )
  {
    printf("Your equation has infinite solutions\n");
  }
  else if ( (int) a == 0 && (int) b == 0 && (int) c != 0)
  {
    printf("Not even stephen hawking can find a solution for this\n");
    printf("No solutions\n");
  }
  else
  {
  
    printf("Error, A is zero. I cabnnot divide by 0\n");
    printf("I'll assume this is linear so I'll pass it to the linear equation solver\n");
    
    printf("Fraction: %.1lf/%.1lf\n Decimal: %.1lf", (c*-1), b, ( (c*-1) / b) );

  }

  return 0;

}
/*========================================*/
//        END OF MAIN FUNCTIOOOOOON!      //
/*========================================*/

int getDiscriminant(double a, double b, double c)
{
  //get the discriminant
  //since you just have to know the value of the discriminant,
  //and not do anything with it, return -1 if negative, 0 if 0 and 1 if postive so we can put this in a sweet switch

  int return_value; //return this value (-1, 0, or 1)
  int descriminant = (b * b) - (4*a *c);
  
  if (descriminant == 0)
  {
    //if desc is 0
    return_value = 0;
  }
  else if (descriminant < 0)
  {
    //if desc is negative
    return_value = -1;
  }
  else
  {
    //else then it's positive 
    return_value = 1;
  }
  return return_value;
}
/*========================================*/
// END OF getDiscriminant FUNCTIOOOOOON!  //
/*========================================*/
double findPositive(double a, double b, double c)
{
  //yucky one liner, might make ms harvey angry ¯\_(ツ)_/¯
  return ( ( (b * -1) + sqrt(( (b*b) - (4 * a * c) )) ) / (2*a) ); 
}

double findNegative(double a, double b, double c)
{
  //yucky one liner, might make ms harvey angry ¯\_(ツ)_/¯
  return ( ( (b * -1) - sqrt( ( (b*b) - (4 * a * c) ) ) ) / (2*a) ); 
}
