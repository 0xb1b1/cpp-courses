#include <iostream>

using namespace std;

/*void swap(int &number_a, int &number_b) {
    int buffer = number_a;
    number_a = number_b;
    number_b = buffer;
}*/ // Avoiding the swap function per instructions

int main() {
    int input_array_size = 10,
        input_array[input_array_size] = {8,1,4,3,2,5,6,7,0,9};
    
    // Output the input array before changing it
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    // Find the smallest element in the following series of even (by index) numbers\
    and swap it with input_array[element]
    for(int element = 0; element < input_array_size; element += 2) {
        int min_value = input_array[element];
        for(int check = element + 2; check < input_array_size; check += 2) {
            if(input_array[check] < min_value) {
                min_value = input_array[check];
                int swap_min_value = input_array[check];
                input_array[check] = input_array[element];
                input_array[element] = swap_min_value;
            }
        }
    }

    // Output the input array
    cout << "Output array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    return(0);
}
