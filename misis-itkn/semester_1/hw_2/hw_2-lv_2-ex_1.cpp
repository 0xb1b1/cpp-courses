#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;	// nothing else is included

int main() {
	int female_h, male_h;
	string female_h_string, male_h_string, temp;
	vector <int> female_hv;
	vector <int> male_hv;
	double heights_sum;

	cout << "Enter female student heights (separated by spaces): "; getline(cin, female_h_string);
	cout << "\nEnter male student heights (separated by spaces): "; getline(cin, male_h_string);
	cout << endl;
	
	stringstream female_stream(female_h_string);
	stringstream male_stream(male_h_string);

	while(female_stream >> temp) { female_hv.push_back(stoi(temp)); }
	while(male_stream >> temp) { male_hv.push_back(stoi(temp)); }

	for(int i = 0; i < female_hv.size(); i++) {
		heights_sum += (double)female_hv[i];
	}
	cout << "Average female height is " << (heights_sum / female_hv.size()) << " cm.\n";

	heights_sum = 0;

	for(int i = 0; i < male_hv.size(); i++) {
                heights_sum += (double)male_hv[i];
        }
        cout << "Average male height is " << (heights_sum / male_hv.size()) << " cm.\n";
	return(0);
}
