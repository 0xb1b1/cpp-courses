#include <iostream>	// i/o capability

using namespace std;	// nothing else is included

int main() {
	cout.precision(3);

	int exec_cycles;
	cout << "Execution cycle count: "; cin >> exec_cycles; cout << endl;

	double sum = 1.0 + 2/1;
	int numerator_sum = 3, denominator_sum = 2;
	int previous_numerator = 2, previous_denominator = 1;
	int _previous_numerator = 1, _previous_denominator = 1;
	
	//cout << "DEBUG: sum=" << sum << endl;
	
	int exec_cycles_current = 2, numerator_sum_old, denominator_sum_old;
	while(exec_cycles_current <= exec_cycles) {
		
		//cout << "DEBUG: CYCLE " << exec_cycles_current << "\ncurrent values:\nnumerator_sum=" << numerator_sum
		//	<< "\ndenominator_sum=" << denominator_sum << "\n\n";
		sum += numerator_sum / (double)denominator_sum;
		
		numerator_sum_old = numerator_sum;
		denominator_sum_old = numerator_sum;

		numerator_sum -= _previous_numerator;
		denominator_sum -= _previous_denominator;
		
		_previous_numerator = previous_numerator;
		_previous_denominator = previous_denominator;

		previous_numerator = numerator_sum;
		previous_denominator = denominator_sum;

		numerator_sum += numerator_sum_old; denominator_sum += denominator_sum_old;
		
		exec_cycles_current++;
	}

	cout << sum << endl;

	return(0);
}
