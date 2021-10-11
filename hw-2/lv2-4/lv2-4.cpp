#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double g_radius_0, g_radius_1, g_px, g_py;
string g_radius_0_string, g_radius_1_string;
string g_end_of_input = "";
string g_debug_toggle = "debug";

int g_fit_counter, g_bfit_counter;

string g_input;

bool fitsInsideCircle(double px, double py) {
		//if(pow(px - g_radius_0, 2) + pow(py - g_radius_1, 2) <= pow(rad, 2)) {
		double distance = pow(pow(px, 2) + pow(py, 2), 0.5);
		if(distance >= g_radius_0 && distance <= g_radius_1) {
			return(true);
		} else { return(false); }
}

int main() {
	cout << "radius_0: "; getline(cin, g_radius_0_string);
	g_radius_0 = stod(g_radius_0_string);
	cout << "\nradius_1: "; getline(cin, g_radius_1_string);
	g_radius_1 = stod(g_radius_1_string);
	do {
		cout << "\n\nEnter point coords (separated by Return): ";
		getline(cin, g_input);
		if(g_input == g_end_of_input) { cout << "\nFinished. Proceeding to debug log.\n"; break; }
		g_px = stod(g_input);
		getline(cin, g_input);
		g_py = stod(g_input);

		if(fitsInsideCircle(g_px, g_py)) {
			cout << "\nThe point is within the circle\n";
			g_fit_counter++;
		} else {
			cout << "\nThe point is _NOT_ within the circle\n";
                        g_bfit_counter++;
		}
	} while(1);

	cout << "DEBUG: \n" <<
		"fit: " << g_fit_counter <<
		"\nnfit: " << g_bfit_counter <<
		endl;
	return(0);
}



