#include <iostream>
#include <string>
#include <vector>

using namespace std;

string vectorToString(vector <string> input_vector) {
	string string_output = "";
	bool first_element = true;
	int vector_size = input_vector.size();
        int passed_elements = 0;
        string_output += "[";
        for(int i = 0; i < vector_size; i++) {
                string_output += input_vector[i];
                first_element = false;
                passed_elements++;
                if(!first_element && passed_elements != vector_size) { string_output += ", "; }
        }
        string_output += "]";
	
	return(string_output);
}

int main() {
	vector <string> input_vector;
	for(int i = 0; i < 10; i++) {
		string vector_element;
		cout << "Enter array element #" << i + 1 << ": ";
		getline(cin, vector_element);
		input_vector.push_back(vector_element);
		cout << endl;
	}
	
	vector <string> even_output_vector, odd_output_vector;
	for(int i = 0; i < input_vector.size(); i++) {
		if((i + 1) % 2 == 0) {
			even_output_vector.push_back(input_vector[i]);
		} else {
			odd_output_vector.push_back(input_vector[i]);
		}
	}

	cout << "Even positions: " << vectorToString(even_output_vector) << endl;
	cout << "Odd positions: " << vectorToString(odd_output_vector) << endl;
		
	return(0);
}
