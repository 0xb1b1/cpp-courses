#include <iostream>

using namespace std;

int main() {
	int input_array_size = 11,
        input_array[input_array_size] = {44, 12, 32, 4, -2, -43, 17, 52, -12, -33, 0},
        p = 69;
	
    // Output the input array before changing it
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    // Find the last positive element of input_array
    int last_pos_element_index;
    for(int element = 0; element < input_array_size; element++) {
        if(input_array[element] > 0) {
            last_pos_element_index = element;
        }
    }

	// Move elements located after last_pos_element_index one element to the right
    for(int element = input_array_size - 1; element > last_pos_element_index + 1; element--) {
        input_array[element] = input_array[element - 1];
    }

	input_array[last_pos_element_index + 1] = p;

	// Output the input array
	cout << "Output array: ";
	for(int element = 0; element < input_array_size; element++) {
		cout << input_array[element] << " ";
	} cout << endl;

	return(0);
}
