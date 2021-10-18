#include <iostream>

using namespace std;

double g_p = 5454.555;

int main() {
	double input_array[10] = {8.12,-9999,-3.11,65,-43,9324,55,-129,21,-12};
	int input_array_size = (sizeof(input_array) / sizeof(*input_array)); 
	int last_pos_element_index;
	for(int i = 0; i < input_array_size; i++) {
		if(input_array[i] > 0) {
			last_pos_element_index = i;
		}
	}
	double output_array[input_array_size + 1];
	bool p_placed = false;
	for(int i = 0; i < input_array_size + 1; i++) {
		if(i == last_pos_element_index && !p_placed) {
			output_array[i] = input_array[i];
			output_array[i + 1] = g_p;
			p_placed = true;
			i++;
		} else if(!p_placed) {
			output_array[i] = input_array[i];
		} else if(p_placed) {
			output_array[i] = input_array[i - 1];
			cout << "placed element " << i << "after p" << endl;
		}
	}
	
	for(int i = 0; i < input_array_size + 1; i++) {
		cout << output_array[i] << " ";
	}
	cout << endl;

	return(0);
}

