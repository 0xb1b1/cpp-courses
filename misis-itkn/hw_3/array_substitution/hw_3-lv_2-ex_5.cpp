#include <iostream>

using namespace std;

string arrayToString(int input_array[], int array_size) {
	string string_output = "";
	bool first_element = true;
        int passed_elements = 0;
        string_output += "[";
        for(int i = 0; i < array_size; i++) {
                string_output += to_string(input_array[i]);
                first_element = false;
                passed_elements++;
                if(!first_element && passed_elements != array_size) { string_output += ", "; }
        }
        string_output += "]";
	
	return(string_output);
}

int main() {
	int array_size = 10;
	int input_array[array_size] = {6,8,-1,5,4,-2,-5,-10,2,5};

	int min_num = input_array[0], max_num = input_array[0];
	int min_num_index, max_num_index;
	for(int i = 0; i < array_size; i++) {
		if(input_array[i] > max_num) {
			max_num = input_array[i];
			max_num_index = i;cout << "max set at " << max_num_index << " num " << input_array[i] << endl;
		}
		if(input_array[i] < min_num) {
			min_num = input_array[i];
			min_num_index = i;cout << "min set at " << min_num_index << " num " << input_array[i] << endl;
		}
	} cout << "MIN index: " << min_num_index << " MAX index: " << max_num_index << endl;

	cout << min_num << ' ' << max_num;

	// Swap min_num_index and max_num_index if the first one 
	if(max_num_index > min_num_index) {
		int temp_index = min_num_index;
		min_num_index = max_num_index;
		max_num_index = temp_index;
	}

	int negative_elements = 0;
        for(int i = max_num_index + 1; i < min_num_index + 1; i++) {
                if(input_array[i] < 0) {
                        negative_elements++;
                }
        }
	negative_elements--;

	int negative_array[negative_elements];
        int negative_elements_passed = 0;

	for(int i = max_num_index + 1; i < min_num_index; i++) {
		if(input_array[i] < 0) 	{
			negative_array[negative_elements_passed] = input_array[i];
			negative_elements_passed++;
		}
	} cout << endl;

	cout << arrayToString(negative_array, negative_elements) << endl;

	return(0);
}
