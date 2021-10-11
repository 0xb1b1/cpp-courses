#include <iostream>	// i/o capability
#include <cmath>	// std::cos (variable class double)

using namespace std;	// nothing else is included

int64_t pow(int64_t base, int64_t power) {
        int64_t product = base;
        for(int64_t i = 1; i < power; i++) {
                product *= base;
        }

        return(product);
}

int main() {
	int x; cout << "Enter x: "; cin >> x; cout << endl;	// get x

	int sum = cos(x);
	for(int i = 1; i < 9; i++) {
		sum += cos(x * (i + 1)) / pow(x, i);
	}

	cout << sum << endl;
	return(0);	// gotta do it
}
