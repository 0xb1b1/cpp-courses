#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int insideCircle(double radius_1, double radius_2, double dx, double dy) {
	if((dx * dx + dy * dy >= radius_1 * radius_1) && (dx * dx + dy * dy <= radius_2 * radius_2)) { return(1); }
	else { return(0); }
}

int main() {
	string input_rad, input_coords, temp;
	double radius_1, radius_2;
	vector <double> dot_coords;

	cout << "Inner and outer radiuses for the circle (separated by space): "; getline(cin, input_rad);
	//cout << "\nCoords for dots (format: x1 y1 x2 y2...): "; getline(cin, input_coords);
	
	stringstream rad_stream(input_rad);
	stringstream coords_stream(input_coords);
	
	int i = 0;
	while(rad_stream >> temp) {
		if(i == false) {
			radius_1 = stod(temp);
		} else {
			radius_2 = stod(temp);
		}
		i++;
	}

	while(coords_stream >> temp) {
		dot_coords.push_back(stod(temp));
	}

//	for(int i = 0; i < dot_coords.size(); i += 2) {
//		if(insideCircle(radius_1, radius_2, dot_coords[i], dot_coords[i + 1])) {
//			cout << "\nPoint (" << dot_coords[i] << ";" << dot_coords[i + 1] << ") is inside the circle";
//		} else {	
//			cout << "\nPoint (" << dot_coords[i] << ";" << dot_coords[i + 1] << ") is _NOT_ inside the circle\n";
//		}
//	}
	while 
	return(0);
}
