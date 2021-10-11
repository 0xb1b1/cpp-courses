#include <iostream>

using namespace std;

int main() {
	double input_array_a[20] = {8.12,-99.12,-3.11,650.31,-43.33,9324.5,55.2,-129.2452,21.24,12.1};
	double input_array_b[10] = {4,63,73,456,874,34,463,346,212,443};
	int interrupt_element = 2;
	int input_array_a_size = sizeof(input_array_a) / sizeof(*input_array_a);
	int input_array_b_size = sizeof(input_array_b) / sizeof(*input_array_b);

	cout << "Array a: ";
	for(int i = 0; i < input_array_a_size; i++) {
		cout << input_array_a[i] << " ";
	}
	cout << "\nArray b: ";
	for(int i = 0; i < input_array_b_size; i++) {
                cout << input_array_b[i] << " ";
        }
	cout << endl;

	/*
	double output_array[input_array_a_size + input_array_b_size];
	for(int i = 0; i < interrupt_element; i++) {
		output_array[i] = input_array_a[i];
	}
	for(int i = interrupt_element; i < interrupt_element + input_array_b_size; i++) {
		output_array[i] = input_array_b[i - interrupt_element];
	}
	for(int i = interrupt_element; i < input_array_a_size; i++) {
		output_array[i + input_array_b_size - interrupt_element + 2] = input_array_a[i];
	}
	*/

	double buffer_variable;
	while(

	for(int i = 0; i < input_array_a_size + input_array_b_size; i++) {
		cout << output_array[i] << " ";
	}
	cout << endl;

	return(0);
}


