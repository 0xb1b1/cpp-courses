#include <iostream>
#include <cmath>	// i don't want to write a function for sin(frac) and cos(frac)
#include <iomanip>

using namespace std;

// definitions for constants
#define SUM_PARENT_LIM 0.0001
#define A_BORDER 0.1
#define B_BORDER 1
#define X_STEP 0.1	// 10 steps for x in one pass
#define EULERS_NUM 2.71828182845904523536028747135266249775724709369995	// constant

double notationPassSum(double x) {
	int i = 0;
	double factorial = 1;
	double pass_sum = cos(x * i) / factorial;	// first pass equals to 1
	double result_sum = 0;
	while(-SUM_PARENT_LIM >= pass_sum || pass_sum >= SUM_PARENT_LIM) {
		// maintenance
		result_sum += pass_sum;	// update global sum with previous pass
		i++;	// summation iterator++
		
		// fun
		factorial *= i;
		pass_sum = pass_sum = cos(x * i) / factorial;
	}
	return(result_sum);
}

int main() {
	for(double a = A_BORDER; a <= B_BORDER + 0.0001; a += X_STEP) {
		double pass_sum = notationPassSum(a), fx = pow(EULERS_NUM, cos(a)) * cos(sin(a));
		cout << "sum\t\tf(x)\t\tdiff\n";
		cout <<
			fixed << setprecision(10) << endl <<
			pass_sum << "\t" <<
			fx << "\t" <<
			pass_sum - fx << "\n\n";
	}
	return(0);
}
