#include <iostream>

using namespace std;

#define DIVIDER cout << "--------------------\n";

string g_debug_arg = "--debug", g_debug_arg_short = "-d";

int main(int argc, char *argv[]) {
	// Add debugging capabilities
    bool args_present = true, debug_mode = false;
    if(argc == 1) { args_present = false; }
    if(args_present) { if(argv[1] == g_debug_arg || argv[1] == g_debug_arg_short) { debug_mode = true; } }

	int input_array_size = 10;
	int input_array[10] = {44, 12, 32, 4, -2, -43, 17, 52, 12, 33};
	int p = 69;

	// Calculate the sum of input_array elements
	int array_elements_sum = 0;
	for(int i = 0; i < input_array_size; i++) {
		array_elements_sum += input_array[i];
	}

	// Calculate the array median
	double array_median = array_elements_sum / double(input_array_size);

	// Find an array element that is the closest to the array's median
	double minimal_difference = abs(array_median - double(input_array[0]));
	int closest_to_median_index;
	for(int i = 0; i < input_array_size; i++) {
		if(abs(array_median - input_array[i]) < minimal_difference) {
			closest_to_median_index = i;
			minimal_difference = abs(array_median - input_array[i]);
		}
	}

	// Create the output_array and put p into it, next to closest_to_median 
	double output_array[input_array_size + 1];
	bool p_placed = false;
	for(int i = 0; i < input_array_size + 1; i++) {
		if(i == closest_to_median_index + 1 && !p_placed) {
			output_array[i] = p;
			p_placed = true;
		continue;
		}
		if(p_placed) {
			output_array[i] = input_array[i - 1];
		}
		else {
			output_array[i] = input_array[i];
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

	// Output additional information if debug mode is on
	if(debug_mode) { DIVIDER cout << "Additional information (debug):\n";
		cout << "Median: " << array_median << endl;
		cout << "Closest to median index: " << closest_to_median_index << endl;
		cout << "Sum: " << array_elements_sum << endl;
	}

	return(0);
}
