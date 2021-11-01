#include <iostream>

using namespace std;

void swap(int &number_a, int &number_b) {
    int buffer = number_a;
    number_a = number_b;
    number_b = buffer;
}
/*
int findMinimalInArray(int *input_array[], int input_array_size) {
    int min_element = *input_array[0];
    for(int element = 0; element < input_array_size; element++) {
        if(min_element > *input_array[element]) {
            min_element = *input_array[element];
        }
    }
    return(min_element);
}

int main() {
    int input_array_size = 10,
        input_array[input_array_size] = {8,1,4,3,2,5,6,7,0,9};

    // Output the input array before changing it
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    for(int element = 0; element < input_array_size; element += 2) {
        int min_past_element = element,
            search_array[int((input_array_size / 2) % 1) - element],
            search_array_current_element = 0;
        for(int composer = 0; composer < input_array_size; composer += 2) {
            search_array[search_array_current_element] = input_array[composer];
            search_array_current_element++;
        }
        cout << "\n\n" << int((input_array_size / 2) % 1) << "\n";for(int i = 0; i < sizeof(search_array) / sizeof(*search_array); i++) {
            cout << search_array[i] << " ";
        }cout << "\n\n\n";
    }

    return(0);
    }*/

int main() {
    int input_array_size = 10,
        input_array[input_array_size] = {8,1,4,3,2,5,6,7,0,9};
    
    // Output the input array before changing it
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    // Find the smallest element in the following series of even (by index) numbers
    for(int element = 0; element < input_array_size; element += 2) {
        int swap_element, min_value = input_array[element], min_value_index = -1;
        for(int check = element + 2; check < input_array_size; check += 2) {
            if(input_array[check] < min_value) {
                min_value = input_array[check];
                min_value_index = check;
            }
        }
        if(min_value_index != -1) {
            swap(input_array[element], input_array[min_value_index]);
        }
    }

    // Output the input array
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    return(0);
}