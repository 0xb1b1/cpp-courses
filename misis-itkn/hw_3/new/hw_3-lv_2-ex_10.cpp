#include <iostream>

using namespace std;

int main() {
    int input_array_size = 10,
        input_array[input_array_size] = {-12,23,33,4,-2,5,0,1,0,12};

    // Output the input array before changing it
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    // Find the biggest number in input_array to use as pos_min_num
    int pos_min_num = input_array[0];
    for(int element = 0; element < input_array_size; element++) {
        if(input_array[element] > pos_min_num) {
            pos_min_num = input_array[element];
        }
    }

    // Find the smallest number in input_array
    int pos_min_num_index;
    for(int element = 0; element < input_array_size; element++) {
            if(input_array[element] < pos_min_num && input_array[element] > 0) {
                    pos_min_num = input_array[element];
                    pos_min_num_index = element;
            }
    } cout << "min element: " << pos_min_num << " at pos " << pos_min_num_index << endl;

    // Remove the smallest number in input_array
    for(int relocation_pos = pos_min_num_index + 1; relocation_pos < input_array_size; relocation_pos++) {
        cout << relocation_pos << "REPLACED " << input_array[relocation_pos - 1] << " WITH " << input_array[relocation_pos] << endl;
        input_array[relocation_pos - 1] = input_array[relocation_pos];
    }

    // Output the input array
    cout << "Input array: ";
    for(int element = 0; element < input_array_size - 1; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

	return(0);
}
