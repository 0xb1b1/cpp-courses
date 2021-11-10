#include <iostream>

using namespace std;

int main() {
    int input_array_b_size = 6;
    int input_array_a_size = 9 + input_array_b_size,
        input_array_a[input_array_a_size] = {[0] = 1,[1] = 2,[2] = 3,[3] = 4,[4] = 5,[5] = 6,[6] = 7,[7] = 8,[8] = 9},
        input_array_b[input_array_b_size] = {11,22,33,44,55,66},
        interrupt_element = 4;

    // Output input array A before changing it
	cout << "Input array A: ";
	for(int element = 0; element < input_array_a_size; element++) {
		cout << input_array_a[element] << " ";
	} cout << endl;

    // Output input array B
	cout << "Input array B: ";
	for(int element = 0; element < input_array_b_size; element++) {
            cout << input_array_b[element] << " ";
    } cout << endl;
    
	// Move elements located after interrupt_element one element to the right
    for(int repeater = 0; repeater < input_array_b_size; repeater++) {
    for(int element = input_array_a_size - 1; element > interrupt_element + 1; element--) {
        input_array_a[element] = input_array_a[element - 1];
    }
    }

    // Add input_array_b after interrupt_element in input_array
    for(int element = 0; element < input_array_b_size; element++) {
        input_array_a[element + interrupt_element + 1] = input_array_b[element];
    }

    // Output input array A before changing it
	cout << "Input array A: ";
	for(int element = 0; element < input_array_a_size; element++) {
		cout << input_array_a[element] << " ";
	} cout << endl;

    return(0);
}