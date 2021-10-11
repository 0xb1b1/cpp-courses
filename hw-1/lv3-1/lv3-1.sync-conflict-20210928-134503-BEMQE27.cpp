#include <iostream>
#include <cmath>	// i don't want to write a function for sin(frac) and cos(frac)
#include <iomanip>

using namespace std;

// definitions for constants
#define SUM_PARENT_LIM 0.0001
#define A_BORDER 0.1
#define B_BORDER 1
#define X_STEP 0.1	// 10 steps for x in one pass

double notationPassSum(double x) {
	double pass_sum = 0;
	double result_sum = 1;	// first pass equals to 1
	int i = 0;	// defined in lv3-1, sum_child
	int inverse = 1;	// defined in lv3-1, (-1)^(i)
	double factorial = 1;	// defined in lv3-1, (2 * i)!; in first pass it equals to 1 (0! = 1)
	while(-SUM_PARENT_LIM >= pass_sum || pass_sum >= SUM_PARENT_LIM) {
		// maintenance
		result_sum += pass_sum;	// update global sum with previous pass
		i++;	// summation iterator++
		
		// fun
		inverse *= -1;
		/*	explanation for (double)factorial:
			because 
		*/
		factorial *= (i * 2) * ((i * 2) - 1);
		double x_pow = pow(x, 2 * i);
		pass_sum = inverse * (x_pow / factorial);
	cout << x_pow << endl;}
	return(result_sum);
}

int main() {
	for(double x = A_BORDER; x <= B_BORDER; x += X_STEP) {
		double pass_sum = notationPassSum(x), cos_x = cos(x);
		cout << "sum\t\tcos(a)\t\tdiff\n";
		cout <<
			fixed << setprecision(10) << endl <<
			pass_sum << "\t" <<
			cos_x << "\t" <<
			pass_sum - cos_x << "\n\n";
	}
	return(0);
}
