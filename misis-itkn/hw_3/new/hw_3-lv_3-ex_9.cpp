#include <iostream>

using namespace std;

int main() {
    int input_array_size = 10,
        input_array[input_array_size] = {1,2,3,4,6,5,4,3,4,1};

	// Calculate the longest increasing sequence
    int current_increasing_sequence = 1, longest_sequence = 0;
    for(int element = 0; element < input_array_size - 1; element++) {
        if(input_array[element] < input_array[element + 1]) {
            current_increasing_sequence++;
        }
        else {
            if(longest_sequence < current_increasing_sequence) {
                longest_sequence = current_increasing_sequence;
            }
            current_increasing_sequence = 1;
        }
    }

	// Calculate the longest decreasing sequence
    int current_decreasing_sequence = 1;
    for(int element = 0; element < input_array_size - 1; element++) {
        if(input_array[element] > input_array[element + 1]) {
            current_decreasing_sequence++;
        }
        else {
            current_decreasing_sequence = 1;
        }

        if(longest_sequence < current_decreasing_sequence) {
            longest_sequence = current_decreasing_sequence;
        }
    }

    // Output the input array
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    // Output essential information
    cout << "Longest increasing/decreasing sequence: " << longest_sequence << endl;

	return(0);
    