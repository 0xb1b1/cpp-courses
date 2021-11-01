#include <iostream>

using namespace std;

int main() {
	int input_array_size = 10,
        input_array[10] = {44, 12, 32, 4, -2, -43, 17, 52, -12, -33},
        p = 69;

    // Find the last positive element of input_array
    int last_pos_element_index;
    for(int element = 0; element < input_array_size; element++) {
        if(input_array[element] > 0) {
            last_pos_element_index = element;
        }
    }

	// Create the output_array and put p next to the last positive element
	double output_array[input_array_size + 1];
	bool p_placed = false;
	for(int element = 0; element < input_array_size + 1; element++) {
		if(element == last_pos_element_index + 1 && !p_placed) {
			output_array[element] = p;
			p_placed = true;
		continue;
		}
		if(p_placed) {
			output_array[element] = input_array[element - 1];
		}
		else {
			output_array[element] = input_array[element];
		}
	}

    // Output the input array
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

	// Output the output array
	cout << "Output array: ";
	for(int element = 0; element < input_array_size + 1; element++) {
		cout << output_array[element] << " ";
	} cout << endl;

	return(0);
}
