#include <iostream>

using namespace std;

#define BIG_DADDY 9999999999999

string arrayToString(double input_array[], int array_size) {
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
	int n = 10;
	double input_array[n] = {-880.12,4.23,-3.11,65,-43,-1.11,55,129,21,12};

	double min_num = BIG_DADDY, max_num = -BIG_DADDY;
	int min_num_index, max_num_index;
	for(int i = 0; i < n; i++) {
		if(input_array[i] > max_num) {
			max_num = input_array[i];
			max_num_index = i;
		}  if(input_array[i] < min_num) {
			min_num = input_array[i];
			min_num_index = i;
		}
	}

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

	double negative_array[negative_elements];
        int negative_elements_passed = 0;

	for(int i = max_num_index + 1; i < min_num_index; i++) {
		if(input_array[i] < 0) 	{
			negative_array[negative_elements_passed] = input_array[i];
			negative_elements_passed++;
		}
	}

	cout << arrayToString(negative_array, negative_elements) << endl;

	return(0);
}
