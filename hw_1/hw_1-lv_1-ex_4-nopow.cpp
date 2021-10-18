#include <iostream>	// i/o capability
#include <cmath>	// std::cos (variable class double)

using namespace std;	// nothing else is included

int main() {
	int x; cout << "Enter x: "; cin >> x; cout << endl;	// get x

	int sum = cos(x);
	for(int i = 1; i < 9; i++) {
		int power = x;
		for(int current_power = 0; current_power < i; current_power++) {
			power *= x;
		}
		sum += cos(x * (i + 1)) / power;
	}

	cout << sum << endl;
	return(0);	// gotta do it
}
