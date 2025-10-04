// Name        : Aaron Mellema
// Username    : ammellem
// Description : Print the snowfall information of a given month
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  //check that arguemnts are formatted properly
  if (argc < 3)
    {
        printf("Usage: SnowGraph <month1> <amount1> [<month2> <amount2>] ...\n");
        return 0;
    }
    int i = 2;
    while( i < argc ) {
      if( atof(argv[i]) < 0 ) {
	printf("ERROR: All amounts must be non-negative!\n");
	return 0;
      }
      i += 2;
    }

    //calcualte average, min, and max
    int j = 2;
    int minL = 2;
    int maxL = 2;
    double min = atof(argv[j]);
    double max = atof(argv[j]);
    double total = 0;
    double t;

    //loop until we run out of arguments
    while( j < argc ) {
      t = (double)atof(argv[j]);
      if( t < min ) { //check if t is the new min
	min = t;
	minL = j;
      }
      if( t > max ) { //check if t is the new max
	max = t;
	maxL = j;
      }

      //add t value to total
      total += t;

      //move to next segment []
      j += 2;
    }

    //print total and average, average eq total/#entries[], using int truncating we can remove any extras on the end
    printf("total snow %.2f, average snow %.2f\n", total, total / ( (argc - 1) / 2 ) );

    //print the graph
    j = 2;
    while( j < argc ) {
      //print month
      printf("%10s: ", argv[j-1]);
      //print stars
      int stars = (int)(atof(argv[j]) + 0.5);
      for( int k = 0; k < stars; k++ ) {
	printf("*");
      }
      //print snowfall
      printf(" %.1f", atof(argv[j]));

      //print min and max
      if( j == minL ) { printf(" min"); }
      if( j == maxL ) { printf(" max"); }

      //print linefeed
      printf("\n");
      //increment j
      j += 2;
    }
    
    return 0; 
}
