#include <iostream>

using namespace std;

int main() {
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
}