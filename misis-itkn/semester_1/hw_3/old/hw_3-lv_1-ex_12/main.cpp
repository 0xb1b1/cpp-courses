#include <iostream>
#include <string>

using namespace std;

int main() {
	double input_array[8];
	for(int i = 0; i < 8; i++) {
		string array_element_str;
		cout << "Enter array element #" << i + 1 << ": ";
		getline(cin, array_element_str);
		input_array[i] = stod(array_element_str);
		cout << endl;
	}
	
	double last_negative;
	for(int i = 0; i < sizeof(input_array) / sizeof(*input_array); i++) {
		if(input_array[i] < 0) {
			last_negative = input_array[i];
		}
	}
	cout << "Last negative element: " << last_negative << endl;

	return(0);
}
