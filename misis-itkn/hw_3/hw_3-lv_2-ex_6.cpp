#include <iostream>

using namespace std;

double g_input_array[10] = {43, 12, 32, 4, -2, -43, 17, 52, 12, 33};
double g_p = 69;

int main() {
	int array_size = sizeof(g_input_array) / sizeof(*g_input_array);
	double array_elements_sum = 0;
	for(int i = 0; i < array_size; i++) {
		array_elements_sum += g_input_array[i];
	}
	double array_median = array_elements_sum / array_size;
	double minimal_difference = abs(array_median - g_input_array[0]);
	int closest_to_median_index;
	for(int i = 0; i < array_size; i++) {
		if(abs(array_median - g_input_array[i]) < minimal_difference) {
			closest_to_median_index = i;
			minimal_difference = abs(array_median - g_input_array[i]);
		}
	}

	double output_array[11];
	bool p_placed = false;
	for(int i = 0; i < array_size + 1; i++) {
		if(i == closest_to_median_index + 1 && !p_placed) {
			output_array[i] = g_p;
			p_placed = true;
		continue;
		}
		if(p_placed) {
			output_array[i] = g_input_array[i - 1];
		}
		else {
			output_array[i] = g_input_array[i];
		}
	}

	for(int i = 0; i < 11; i++) {
		cout << output_array[i] << " ";
	}
	
	cout << "\nMedian: " << array_median << endl;
	cout << "Closest to median index: " << closest_to_median_index << endl;
	cout << "Sum: " << array_elements_sum << endl;
	return(0);
}


