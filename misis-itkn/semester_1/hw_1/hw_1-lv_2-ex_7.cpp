#include <iostream>     // i/o capability

using namespace std;    // nothing else is included

int main() {
	double km_current = 10, km_sum = 10;
	int current_day = 1;
	bool conditions_satisfied = 0;
	
	double km_in_seven_days = NULL;
	int day_achieved_100km_total = NULL, cday_more_than_20km_per_day = NULL;
	while(!conditions_satisfied) {
		current_day += 1;
		km_current *= 1.1;
		km_sum += km_current;
		if(cday_more_than_20km_per_day == NULL && km_current > 20) { cday_more_than_20km_per_day = current_day; }
		if(current_day == 7) { km_in_seven_days = km_sum; }
		if(day_achieved_100km_total == NULL && km_sum >= 100) { day_achieved_100km_total = current_day; }
		if(km_in_seven_days != NULL && day_achieved_100km_total != NULL && cday_more_than_20km_per_day != NULL) { conditions_satisfied = 1; }
	}
	cout << "1. " << km_in_seven_days << endl;
	cout << "2. " << day_achieved_100km_total << endl;
	cout << "3. " << cday_more_than_20km_per_day << endl;

	return(0);
}
