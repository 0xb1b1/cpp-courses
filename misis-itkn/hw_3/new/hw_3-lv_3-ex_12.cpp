#include <iostream>

using namespace std;

int main() {
    int array_size = 10,
        input_array[array_size] = {-1,-2,-3,0,-5,6,-7,8,9,-1},
        positive_elements = array_size, lookup_offset = 0;

    // Output the input array before changing it
    cout << "Input array: ";
    for(int element = 0; element < array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    // Exclude negative elements
    for(int element = 0; element < array_size; element++) {
        if(input_array[element - lookup_offset] < 0) {
            positive_elements--;
            for(int relocation_pos = element - lookup_offset + 1; relocation_pos < array_size; relocation_pos++) {
                input_array[relocation_pos - 1] = input_array[relocation_pos];
            }
            lookup_offset++;
        }
    }

    // Output the input array
    cout << "Output array: ";
    for(int element = 0; element < positive_elements; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    return(0);
}
