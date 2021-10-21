#include <iostream>
#include <string>

using namespace std;

int main() {
	double input_array[10];
	for(int i = 0; i < 10; i++) {
		string array_element_str;
		cout << "Enter array element #" << i + 1 << ": ";
		getline(cin, array_element_str);
		input_array[i] = stod(array_element_str);
		cout << endl;
	}
	
	bool first_element = true;
	
	int positive_elements = 0;
	for(int i = 0; i < sizeof(input_array)/sizeof(*input_array); i++) {	// i can't be bothered to write something more efficient, it's three in the morning
                if(input_array[i] > 0) {
                	positive_elements++;
		}
        }

	int passed_elements = 0;
	cout << "[";
	for(int i = 0; i < sizeof(input_array)/sizeof(*input_array); i++) {
		if(input_array[i] > 0) {
			cout << input_array[i];
			first_element = false;
			passed_elements++;
			if(!first_element && passed_elements != positive_elements) { cout << ", "; }
		}
	}
	cout << "]" << endl;

	return(0);
}
