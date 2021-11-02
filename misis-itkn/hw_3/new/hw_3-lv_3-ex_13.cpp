#include <iostream>

using namespace std;

int main() {
    int input_array_size = 12,
        input_array[input_array_size] = {4,4,4,4,3,2,1,0,9,8,7,8},
        output_array_size = input_array_size;

    // Output the input array before changing it
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    // Create an array containing checked values
    int checked_values[input_array_size], current_checked_value = 0;

    // Exclude repeating elements
    for(int element = 0; element < input_array_size; element++) {
        int lookup_offset = 0, removed_elements_count = 0;
        // Remember whether the current element is in checked_values and thus the following check\
        shouldn't be performed and output_array_size should not be decreased
        bool noted;

        // Check whether the value has already been checked
        for(int check = 0; check < input_array_size; check++) {
            if(input_array[element] == checked_values[check]) {
                noted = true;
            }
        }

        // Delete matching elements from input_array if the value is seen for the first time
        if(!noted) {
            for(int search = element + 1; search < output_array_size; search++) {
                if(input_array[element] == input_array[search - lookup_offset]) {
                    for(int relocation_pos = search - lookup_offset + 1; relocation_pos < input_array_size; relocation_pos++) {
                        input_array[relocation_pos - 1] = input_array[relocation_pos];
                    }
                    lookup_offset++; removed_elements_count++;
                }
            }
        }

        // If the value is seen for the first time, 
        if(!noted) {
            checked_values[current_checked_value] = input_array[element];
            current_checked_value++;
            output_array_size -= removed_elements_count;
        }
    }

    // Output the input array
    cout << "Output array: ";
    for(int element = 0; element < output_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    return(0);
}
