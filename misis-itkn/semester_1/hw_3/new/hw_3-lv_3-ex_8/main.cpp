#include <iostream>

using namespace std;

void swap(int &number_a, int &number_b) {
    int buffer = number_a;
    number_a = number_b;
    number_b = buffer;
}

int main() {
    int input_array_size = 10,
        input_array[input_array_size] = {1,-6,-9,-8,5,0,7,-4,3,-2};
    
    // Output the input array before changing it
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    // Find the smallest element in the following series of negative numbers\
    and swap it with input_array[element]
    for(int element = 0; element < input_array_size; element++) {
        if(input_array[element] >= 0) {
            continue;
        }
        int swap_element, max_value = input_array[element], max_value_index = -1;
        for(int check = element + 1; check < input_array_size; check++) {
            if(input_array[check] >= 0) {
                continue;
            }
            if(input_array[check] > max_value) {
                max_value = input_array[check];
                max_value_index = check;
            }
        }
        if(max_value_index != -1) {
            swap(input_array[element], input_array[max_value_index]);
        }
    }

    // Output the input array
    cout << "Output array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    return(0);
}