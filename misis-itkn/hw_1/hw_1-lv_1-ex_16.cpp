#include <iostream>	// i/o capability

using namespace std;	// nothing else is included

int main() {
	// a typical chess board has 8**2 tiles on it
	
	uint64_t seed_sum = 1, current_seed_amount = 2;
	for(int current_tile = 0; current_tile < (8 * 8); current_tile++) {
		seed_sum += current_seed_amount;
		//cout << current_seed_amount << endl;
		current_seed_amount *= 2;
	}
	
	int wheat_seeds_weight_metric = seed_sum / 15;
	cout << "Seeds: " << seed_sum << endl;
	cout << "Cumulative weight: " << wheat_seeds_weight_metric << "g" << endl;

	return(0);
}
