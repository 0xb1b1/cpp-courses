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
	
	string p_str, q_str;
	double p, q;
	cout << "Enter P: "; getline(cin, p_str); p = stod(p_str);
	cout << "\nEnter Q: "; getline(cin, q_str); cout << endl; q = stod(q_str);

	int array_elements_pq = 0;
	for(int i = 0; i < (sizeof(input_array)/sizeof(*input_array)); i++) {
		if(input_array[i] > p && input_array[i] < q) {
			array_elements_pq++;
		}
	}

	cout << array_elements_pq << endl;

	return(0);
}
