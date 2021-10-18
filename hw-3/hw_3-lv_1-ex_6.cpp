#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	double array_sum = 0.0;
	for(int i = 0; i < 5; i++) {
		string array_element_str;
        	double array_element;
		cout << "Enter array element #" << i + 1 << ": ";
		getline(cin, array_element_str);
		array_element = pow(stod(array_element_str), 2);
		array_sum += pow(array_element, 2);
		cout << endl;
	}
	
	cout << sqrt(array_sum) << endl;

	return(0);
}
