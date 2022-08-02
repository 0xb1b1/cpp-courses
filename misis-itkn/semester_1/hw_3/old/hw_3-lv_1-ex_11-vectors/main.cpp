#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector <double> input_vector;
	for(int i = 0; i < 10; i++) {
		string vector_element_str;
		cout << "Enter array element #" << i + 1 << ": ";
		getline(cin, vector_element_str);
		input_vector.push_back(stod(vector_element_str));
		cout << endl;
	}
	
	bool first_element = true;
	
	int positive_elements = 0;
	for(int i = 0; i < input_vector.size(); i++) {	// i can't be bothered to write something more efficient, it's three in the morning
                if(input_vector[i] > 0) {
                	positive_elements++;
		}
        }

	int passed_elements = 0;
	cout << "[";
	for(int i = 0; i < input_vector.size(); i++) {
		if(input_vector[i] > 0) {
			cout << input_vector[i];
			first_element = false;
			passed_elements++;
			if(!first_element && passed_elements != positive_elements) { cout << ", "; }
		}
	}
	cout << "]" << endl;

	return(0);
}
