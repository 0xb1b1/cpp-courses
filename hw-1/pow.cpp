#include <iostream>

using namespace std;

int64_t pow(int64_t base, int64_t power) {
	int64_t product = base;
	for(int64_t i = 1; i < power; i++) {
		product *= base;
	}

	return(product);
}

int main() {
	cout << pow(6, 3) << endl;
	return(0);
}
