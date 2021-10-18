#include <iostream>	// i/o capability
#include <string>

using namespace std;	// nothing else is included

int main() {
	string dot_x_string, dot_y_string;
	int tx1 = -1, ty1 = 0;
	int tx2 = 1, ty2 = 0;
	int tx3 = 0, ty3 = 1;
	cout << "Enter x: "; getline(cin, dot_x_string);
	cout << "\nEnter y: "; getline(cin, dot_y_string); cout << endl;
	// convert strings to integers
	int dot_x = stoi(dot_x_string), dot_y = stoi(dot_y_string);

	if(((dot_x - tx1) * (ty1 - ty2) - (dot_y - ty1) * (tx1 - tx2) >= 0) && ((dot_x - tx2) * (ty2 - ty3) - (dot_y - ty2) * (tx2 - tx3) >= 0) && ((dot_x - tx3) * (ty3 - ty1) - (dot_y - ty3) * (tx3 - tx1) >= 0)) {
		cout << "This point on the graph lies within the specified triangle!\n";
	} else {
		cout << "bonk\n";
	}
	return(0);
}
