#include <iostream>     // i/o capability
#include <cmath>	// raise to power
using namespace std;    // nothing else is included

double pow(double base, double power) {
        double product = base;
        for(double i = 1; i < power; i++) {
                product *= base;
        }

        return(product);
}

int main() {
	double x; cout << "Enter x: "; cin >> x; cout << endl;
	if(x >= 1.0) { return(1); }
	
	double sum = 1;
	for(int i = 2; 1; i += 2) {
		double x_pow_i = pow(x, i);
		if(x_pow_i < 0.0001) { break; }
		sum += x_pow_i;
	}
	cout << "s=" << sum << endl;

	return(0);
}
