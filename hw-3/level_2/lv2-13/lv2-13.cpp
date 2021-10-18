#include <iostream>

using namespace std;

int main() {
        double input_array[10] = {8.12,-9999,-3.11,650,-43,9324,55,-129,21,12};
        int input_array_size = (sizeof(input_array) / sizeof(*input_array));
        int biggest_even_element_index;
	double biggest_even_element = input_array[0];
        for(int i = 0; i < input_array_size; i += 2) {
		if(input_array[i] > biggest_even_element) {
                        biggest_even_element_index = i;
			biggest_even_element = input_array[i];
		}
	}
	
	cout << "Changing " << biggest_even_element << " to " << biggest_even_element_index << endl;
	input_array[biggest_even_element_index] = biggest_even_element_index;

	for(int i = 0; i < input_array_size; i++) {
		cout << input_array[i] << " ";
	}
	cout << endl;

	return(0);
}
