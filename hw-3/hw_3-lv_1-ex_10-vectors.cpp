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
	
	string p_str, q_str;
	double p, q;
	cout << "Enter P: "; getline(cin, p_str); p = stod(p_str);
	cout << "\nEnter Q: "; getline(cin, q_str); cout << endl; q = stod(q_str);

	int vector_elements_pq = 0;
	for(int i = 0; i < input_vector.size(); i++) {
		if(input_vector[i] > p && input_vector[i] < q) {
			vector_elements_pq++;
		}
	}

	cout << vector_elements_pq << endl;

	return(0);
}
