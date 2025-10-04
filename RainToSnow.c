// Name        : Aaron Mellema
// Username    : ammellem
// Description : print the snowfall and amnount of the husky statue covered by said snow given two inputs
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
  //makes sure correct number of arguments are present
  if( argc < 3 ) {
    printf("Usage: RainToSnow <inches of rain> <Fahrenheit temperature>\n");
    return 0;
  }
  if( atoi(argv[1]) < 0 ) {
    printf("ERROR: Amount of rain must be non-negative!\n");
    return 0;
  }

  //convert arguments into variables
  double snow = atof(argv[1]);
  double temp = atof(argv[2]);

  //set the motified value of snow
  if (temp >= 32) { snow = snow * 0; }
  else if (temp >= 27) { snow *= 10; }
  else if (temp >= 20) { snow *= 15; }
  else if (temp >= 15) { snow *= 20; }
  else if (temp >= 10) { snow *= 30; }
  else if (temp >= 0) { snow *= 40; }
  else if (temp >= -20) { snow *= 50; }
  else { snow *= 100; }

  //first print
  printf("%.1f inches of rain at %.1fF would result in %.1f inches of snow.\n", atof(argv[1]), temp, snow);

  //calc and print husky statue
  double percent = 100 * (snow / 108);
  if( snow >= 108 ) { printf("This would cover all of the Husky statue!\n"); }
  else { printf("This would cover about %.0f%% of the Husky statue!\n", percent); }
  return 0;  
}
