#include <iostream>
#include <string>

using namespace std;

string arrayToString(string input_array[], int array_size) {
	string string_output = "";
	bool first_element = true;
        int passed_elements = 0;
        string_output += "[";
        for(int i = 0; i < array_size; i++) {
                string_output += input_array[i];
                first_element = false;
                passed_elements++;
                if(!first_element && passed_elements != array_size) { string_output += ", "; }
        }
        string_output += "]";
	
	return(string_output);
}

int main() {
	string input_array[10];
	for(int i = 0; i < 10; i++) {
		string array_element;
		cout << "Enter array element #" << i + 1 << ": ";
		getline(cin, array_element);
		input_array[i] = array_element;
		cout << endl;
	}
	
	string even_output_array[5], odd_output_array[5];
	int even_count = 0, odd_count = 0;
	for(int i = 0; i < (sizeof(input_array)/sizeof(*input_array)); i++) {
		if((i + 1) % 2 == 0) {
			even_output_array[even_count] = input_array[i];
			even_count++;
		} else {
			odd_output_array[odd_count] = input_array[i];
                        odd_count++;
		}
	}


	cout << "Even positions: " << arrayToString(even_output_array, 5) << endl;
	cout << "Odd positions: " << arrayToString(odd_output_array, 5) << endl;
		
	return(0);
}
