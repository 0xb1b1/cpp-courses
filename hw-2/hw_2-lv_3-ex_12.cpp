#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI 3.141592653589793238462643383279502884197169399375105820974

string g_end_of_input = "";

double triangleArea(double side) {
	return(pow(3, 0.5) / 4 * pow(side, 2));
}

double circleArea(double radius) {
	return(PI * pow(radius, 2));
}

double squareArea(double side) {
	return(pow(side, 2));
}

int main() {
	string input_value;
	double side_radius;

	while(1) {
		cout << "Return nothing to go back\n";
		cout << "Enter side/radius value: "; getline(cin, input_value);
		if(input_value == g_end_of_input) {
			cout << "\nBye!\n";
			break;
		}
		side_radius = stod(input_value);
		while(1) {
			double area;
			cout << "square|circle|triangle|\"\": "; getline(cin, input_value);
			if(input_value == g_end_of_input) {
                        	cout << "\nGoing back...\n\n";
                        	break;
			} else if(input_value == "square") {
				area = squareArea(side_radius);
			} else if(input_value == "circle") {
				area = circleArea(side_radius);
			} else if(input_value == "triangle") {
				area = triangleArea(side_radius);
			} else {
				cout << "\nCommand not found. Try again!\n";
				continue;
			}

			cout << fixed << setprecision(8) <<
				"Area: " << area << endl;
		}
	}
	return(0);
}
