#include <iostream>

using namespace std;

int main() {
    int array_size = 10,
        input_array[array_size] = {-1,-2,-3,4,-5,6,-7,8,9,-1},
        positive_elements = array_size, lookup_offset = 0;

    // Create two arrays, for even-indexed numbers and odd-indexed numbers
	int even_output_array[5], odd_output_array[5],
	    even_count = 0, odd_count = 0, output_array_size = 5;
	for(int element = 0; element < array_size; element += 2) {
        // Add even elements to even_output_array
		even_output_array[even_count] = input_array[element];
		even_count++;

        // Add odd elements to odd_output_array
        if(element != array_size) {
		    odd_output_array[odd_count] = input_array[element + 1];
            odd_count++;
		}
	}

    // Output the input array before changing it
    cout << "Input array: ";
    for(int element = 0; element < array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    // Output the first output array (even)
    cout << "Output array 1 (even indices): ";
    for(int element = 0; element < output_array_size; element++) {
        cout << even_output_array[element] << " ";
    } cout << endl;

    // Output the second output array (odd)
    cout << "Output array 1 (odd indices): ";
    for(int element = 0; element < output_array_size; element++) {
        cout << odd_output_array[element] << " ";
    } cout << endl;

    return(0);
}
