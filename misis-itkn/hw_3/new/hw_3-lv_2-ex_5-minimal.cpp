#include <iostream>

using namespace std;

int main() {
	int array_size = 10,
        input_array[array_size] = {6,8,-1,5,-4,-2,-5,-10,2,5};

	int min_num = input_array[0], max_num = input_array[0],
        min_num_index, max_num_index;

	for(int i = 0; i < array_size; i++) {
		if(input_array[i] > max_num) {
			max_num = input_array[i];
			max_num_index = i;
		}
		if(input_array[i] < min_num) {
			min_num = input_array[i];
			min_num_index = i;
		}
	}

	// Swap min_num_index and max_num_index if the first one 
	if(max_num_index > min_num_index) {
		int temp_index = min_num_index;
		min_num_index = max_num_index;
		max_num_index = temp_index;
	}

	// Count negative elements in scope
	int negative_elements = 0;
    for(int element = max_num_index + 1; element < min_num_index; element++) {
        if(input_array[element] < 0) {
            negative_elements++;
        }
    }

    // Add negative elements in scope to the appropriate array
	int negative_array[negative_elements], negative_elements_passed = 0;
	for(int i = max_num_index + 1; i < min_num_index; i++) {
		if(input_array[i] < 0) 	{
			negative_array[negative_elements_passed] = input_array[i];
			negative_elements_passed++;
		}
	} cout << endl;

    // Output the input array
    cout << "Input array: ";
    for(int element = 0; element < array_size; element++) {
        if(element == min_num_index || element == max_num_index) {
            cout << "~" << input_array[element] << "~ ";
        } else {
            cout << input_array[element] << " ";
        }
    } cout << endl;

    // Output negative elements in scope
    cout << "Negative elements in scope: ";
	for(int element = 0; element < sizeof(negative_array) / sizeof(*negative_array); element++) {
        cout << negative_array[element] << " ";
    } cout << endl;

	return(0);
}
