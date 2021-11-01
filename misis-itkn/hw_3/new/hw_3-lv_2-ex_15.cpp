#include <iostream>

using namespace std;

int main() {
    int input_array_a_size = 9, input_array_b_size = 6,
        input_array_a[input_array_a_size] = {1,2,3,4,5,6,7,8,9},
        input_array_b[input_array_b_size] = {11,22,33,44,55,66},
        interrupt_element = 4;

    // Output input array A
	cout << "Input array A: ";
	for(int element = 0; element < input_array_a_size; element++) {
		cout << input_array_a[element] << " ";
	} cout << endl;

    // Output input array B
	cout << "Input array B: ";
	for(int element = 0; element < input_array_b_size; element++) {
            cout << input_array_b[element] << " ";
    } cout << endl;

    // Since there is no way to inflate arrays in C++,\
    it will be necessary to create a new one
    int output_array_size = input_array_a_size + input_array_b_size,
        output_array[output_array_size];

    // As per homework requirements, it is necessary\
    to move elements in an array; moving elements from input_array_a\
    to output_array
    for(int element = 0; element < input_array_a_size; element++) {
        output_array[element] = input_array_a[element];
    }

    // Make some space for input_array_b in output_array by moving\
    its elements, starting with (interrupt_element + 1), by input_array_b_size
    for(int offset = 0; offset < input_array_b_size; offset++) {
        for(int element = input_array_a_size + offset - 1; element > interrupt_element + offset - 1; element--) {
            output_array[element + 1] = output_array[element];
        }
    }

    // Add input_array_b after interrupt_element in output_array
    for(int element = 0; element < input_array_b_size; element++) {
        output_array[element + interrupt_element] = input_array_b[element];
    }


	// Output the output array
	cout << "Output array: ";
	for(int element = 0; element < output_array_size; element++) {
		cout << output_array[element] << " ";
	} cout << endl;

	return(0);
}


