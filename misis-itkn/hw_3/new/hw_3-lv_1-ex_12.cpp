#include <iostream>

using namespace std;

int main() {
    int array_size = 8,
        input_array[array_size] = {-1,-2,-3,4,-5,6,7,8},
        last_negative_index;

    for(int element = 0; element < array_size; element++) {
        if(input_array[element] < 0) {
            last_negative_index = element;
        }
    }

    // Output the input array
    cout << "Input array: ";
    for(int element = 0; element < array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;
    
    // Output the result
    cout << "The last negative element is on position " << last_negative_index + 1
        << " and its value is " << input_array[last_negative_index] << endl;

    return(0);
}