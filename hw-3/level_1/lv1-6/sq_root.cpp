#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double sqrt(double num) {
    	double lower_bound = 0; 
    	double upper_bound = num;
    	double temp = 0;

	while(fabs(num - (temp * temp)) > 0.0001) {
		temp = (lower_bound + upper_bound)/2;
		if (temp * temp >= num) {
			upper_bound = temp;
		}
		else {
			lower_bound = temp;
		}
	}
	return temp;
}

int main() {
	string input_value_str;
	double input_value;

	while(1) {
		cout << "Number to get the square root of: ";
		getline(cin, input_value_str);
		if(input_value_str == "q") {
			break;
		}
		cout << "Result: " << sqrt(stod(input_value_str)) << endl;
	}

	return(0);
}
