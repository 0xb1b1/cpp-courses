#include <iostream>

using namespace std;

int main() {
    int input_array_size = 8,max_num_indices[8], occurrences_counter = 0,
        input_array[8] = {2,4,8,7,2,4,8,3};
	
    // Find the biggest number among all elements of input_array\
    and note its occurrences
    int max_num = input_array[0];
	for(int i = 0; i < input_array_size; i++) {
		if(input_array[i] > max_num) {
			occurrences_counter = 0;
			max_num = input_array[i];
			max_num_indices[occurrences_counter] = i;
			occurrences_counter++;
		} else if(input_array[i] == max_num) {
			max_num_indices[occurrences_counter] = i;
                        occurrences_counter++;
		}
	}

    // Output the input array
    cout << "Input array: ";
    for(int element = 0; element < input_array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    // Output necessary information regarding the answer
    cout << "Max number: " << max_num << endl << "Indices: ";

	// Output the max_num_indices array
	cout << "Output array: ";
	for(int element = 0; element < occurrences_counter; element++) {
		cout << max_num_indices[element] << " ";
	} cout << endl;

	return(0);
}
