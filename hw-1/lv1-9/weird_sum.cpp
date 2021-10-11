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
	int sum = 0;
	for(int i = 1; i < 7; i++) {
		sum += pow(-1, i) * pow(5, i) / i;
	}
	cout << sum << endl;

	return(0);
}
