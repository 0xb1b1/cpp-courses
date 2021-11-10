#include <iostream>
#include <algorithm>

using namespace std;

/*int main() {  // Unknown excercise
    int array_size = 4,
        input_array_a[array_size] = {1,2,3,4},
        input_array_b[array_size] = {9,8,7,6},
        array_scalar_sum = 0;

    for(int element = 0; element < array_size; element++) {
        array_scalar_sum += input_array_a[element] * input_array_b[element];
    }    

    cout << "Array A: ";
    for(int element = 0; element < array_size; element++) {
        cout << input_array_a[element] << " ";
    } cout << endl;

    cout << "Array B: ";
    for(int element = 0; element < array_size; element++) {
        cout << input_array_b[element] << " ";
    } cout << endl;

    cout << "Scalar sum: " << array_scalar_sum << endl;

    return(0);
}*/

/*  // Implement the sqrt function using binary search
double sqrt(double input_value){
  // Max and min are used to take into account numbers less than 1
  double low = min(1, input_value), high = max(1, input_value), mid;

  // Update the bounds to be off the target by a factor of 10
  while(100 * low * low < input_value) low *= 10;
  while(100 * high * high > input_value) high *= 0.1;

  for(int i = 0 ; i < 100 ; i++){
      mid = (low+high)/2;
      if(mid*mid == input_value) return mid;
      if(mid*mid > input_value) high = mid;
      else low = mid;
  }
  return mid;
}*/

// Implement the sqrt function (one of the fastest\
    implementations as shown on WikiPedia)
float sqrt(float input_value) {
   long i;
   float x2, y;
   const float threehalves = 1.5F;

   x2 = input_value * 0.5F;
   y = input_value;
   i = * (long*) &y;    // Floating point bit level hacking
   i = 0x5f3759df - (i >> 1);    // Newton's approximation
   y = * (float*) &i;
   y *= (threehalves - (x2 * y * y)); // 1st iteration
   y *= (threehalves - (x2 * y * y)); // 2nd iteration
   y *= (threehalves - (x2 * y * y)); // 3rd iteration

   return(1/y);
}

int main() {  // Unknown excercise
    int array_size = 5,
        input_array[array_size] = {1,2,3,4,5};
    
    // Find input_array's length
    int input_array_sum = 0;
    for(int element = 0; element < array_size; element++) {
        input_array_sum += input_array[element] * input_array[element];
    }

    // Find the array sum for input_array
    double array_sum = sqrt(input_array_sum);

    // Output array_sum
    cout << "Array sum: " << array_sum << endl << input_array_sum;

    return(0);
}