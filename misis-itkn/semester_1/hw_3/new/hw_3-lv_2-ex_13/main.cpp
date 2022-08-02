#include <iostream>

using namespace std;

int main() {
    int input_array_size = 10,
        input_array[input_array_size] = {12,6,-3,32,-3232,12,99999,9990909,-22,-69};

    // Output the input array before changing it
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    // Find the biggest even element in input_array
    int biggest_evenindex_index = input_array[0];
    for(int element = 0; element < input_array_size; element += 2) {
        if(input_array[element] > biggest_evenindex_index) {
            biggest_evenindex_index = element;
        }
    }

    // Change element at biggest_evenindex_index in input_array to its index
    input_array[biggest_evenindex_index] = biggest_evenindex_index;

    // Output the input array
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    return(0);
    }