#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI 3.141592653589793238462643383279502884197169399375105820974

string g_end_of_input = "";

double triangleArea(double side_0, double side_1) {
	double p = (side_1 + side_0 * 2) / 2;
	return(pow(p * (p - side_1) * pow(p - side_0, 2), 0.5));
}

double ringArea(double radius_0, double radius_1) {
	return((PI * pow(radius_1, 2)) - (PI * pow(radius_0, 2)));
}

double rectangleArea(double side_0, double side_1) {
	return(side_0 * side_1);
}

int main() {
	string input_value;
	double side_radius_0, side_radius_1;

	while(1) {
		cout << "Return nothing to go back\n";
		cout << "Enter the first side/radius value: "; getline(cin, input_value);
		if(input_value == g_end_of_input) {
			cout << "\nBye!\n";
			break;
		}
		side_radius_0 = stod(input_value);

                cout << "\nEnter the second side/radius value: "; getline(cin, input_value);
                if(input_value == g_end_of_input) {
                        cout << "\nBye!\n";
                        break;
                }
                side_radius_1 = stod(input_value);

		while(1) {
			double area;
                        cout << "rectangle|ring|triangle|\"\": "; getline(cin, input_value);
                        if(input_value == g_end_of_input) {
                                cout << "\nGoing back...\n\n";
                                break;
			} else if(input_value == "rectangle") {
				area = rectangleArea(side_radius_0, side_radius_1);
			} else if(input_value == "ring") {
				area = ringArea(side_radius_0, side_radius_1);
			} else if(input_value == "triangle") {
				area = triangleArea(side_radius_0, side_radius_1);
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
