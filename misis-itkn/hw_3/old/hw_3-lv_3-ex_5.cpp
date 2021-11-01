#include <iostream>

using namespace std;

void swapDoubles(double *var_a, double *var_b) {
	double buffer = *var_b;
	*var_b = *var_a;
	*var_a = buffer;
}

int main() {
	double input_array[8] = {123.12,222,41,555.53,352,1,555.53,123.12};
	int input_array_size = sizeof(input_array) / sizeof(*input_array);
	for(int i = 0; i < input_array_size; i += 2) {
		double next_min_num = 999999;
		int next_min_num_index;
		bool next_min_num_found = false;
		for(int d = i; d < input_array_size; d += 2) {
			if(input_array[d] <= next_min_num) {
				next_min_num = input_array[d];
				next_min_num_index = d;
				next_min_num_found = true;
			}
		}
		if(next_min_num_found) {
			swapDoubles(&input_array[i], &input_array[next_min_num_index]);
		}
	}

	for(int i = 0; i < input_array_size; i++) {
		cout << input_array[i] << " ";
	}
	cout << endl;

	return(0);
}

