#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector <double> input_vector;
	for(int i = 0; i < 8; i++) {
		string vector_element_str;
		cout << "Enter array element #" << i + 1 << ": ";
		getline(cin, vector_element_str);
		input_vector.push_back(stod(vector_element_str));
		cout << endl;
	}
	
	double last_negative;
	for(int i = 0; i < input_vector.size(); i++) {
		if(input_vector[i] < 0) {
			last_negative = input_vector[i];
		}
	}
	cout << "Last negative element: " << last_negative << endl;

	return(0);
}
