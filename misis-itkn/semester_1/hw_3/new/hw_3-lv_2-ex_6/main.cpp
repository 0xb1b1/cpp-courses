#include <iostream>

using namespace std;

#define DIVIDER cout << "--------------------\n";

string g_debug_arg = "--debug", g_debug_arg_short = "-d";

int main(int argc, char *argv[]) {
	// Add debugging capabilities
    bool args_present = true, debug_mode = false;
    if(argc == 1) { args_present = false; }
    if(args_present) { if(argv[1] == g_debug_arg || argv[1] == g_debug_arg_short) { debug_mode = true; } }

	int input_array_size = 11;
	int input_array[input_array_size] = {44, 12, 32, 4, -2, -43, 17, 52, 12, 33, 0};
	int p = 69;

	// Output the input array before changing it
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

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

	// Move elements located after closest_to_median_index one element to the right
    for(int element = input_array_size - 1; element > closest_to_median_index + 1; element--) {
        input_array[element] = input_array[element - 1];
    }

	// Put p after closest_to_median_index
	input_array[closest_to_median_index + 1] = p;

	// Output the input array
	cout << "Output array: ";
	for(int element = 0; element < input_array_size; element++) {
		cout << input_array[element] << " ";
	} cout << endl;

	// Output additional information if debug mode is on
	if(debug_mode) { DIVIDER cout << "Additional information (debug):\n";
		cout << "Median: " << array_median << endl;
		cout << "Closest to median index: " << closest_to_median_index << endl;
		cout << "Sum: " << array_elements_sum << endl;
	}

	return(0);
}
