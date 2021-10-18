#include <iostream>

using namespace std;

int main() {
	double input_array[10] = {8.12,-9999,-3.11,65,-43,9324,55,-129,21,12};

	double min_num = input_array[0], max_num = input_array[0];
	int min_num_index, max_num_index;
	for(int i = 0; i < 10; i++) {
		if(input_array[i] > max_num) {
			max_num = input_array[i];
			max_num_index = i;
		} else if(input_array[i] < min_num) {
			min_num = input_array[i];
			min_num_index = i;
		}
	}

        if(min_num_index > max_num_index) {
                int temp_index = min_num_index;
                min_num_index = max_num_index;
                max_num_index = temp_index;
        }


	double select_elements_sum = 0;
	for(int i = min_num_index + 1; i < max_num_index; i++) {
		select_elements_sum += input_array[i];
	}

	cout << "Result: " << select_elements_sum / (max_num_index - min_num_index - 1) << endl;

	return(0);
}
