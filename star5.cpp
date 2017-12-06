/*
37  36  35  34  33  32 31
38  17  16  15  14  13 30
39  18   5   4   3  12 29
40  19   6   1   2  11 28
41  20   7   8   9  10 27
42  21  22  23  24  25 26
43  44  45  46  47  48 49


*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int input = 361527;
  
  // Last element in each spiral is a square of an odd number (== spiral size): 1, 9, 25, 49
  int i = 1;
  for (; i <= sqrt(input); i+=2) {
    if (i*i >= input) {
      break;
    }
  }

  // Find the corners which border the input (on the same spiral)
  int upper_corner = i*i;
  int steps_input_2_closer_corner = 0;
  for (int x = 0; x < 4; ++x) {
    int lower_corner = upper_corner-(i-1);
    
    if (input < (lower_corner)) {
      upper_corner = lower_corner;
    }
    else {
      steps_input_2_closer_corner = 
        min((input-lower_corner),((upper_corner-input)));
      break;
    }
  }
  
  // On each spiral, the corners are (i-1) steps away from the center (== 1)
  int steps_from_input_to_1 = (i-1) - steps_input_2_closer_corner;
  
  cout << steps_from_input_to_1 << endl;
  
}