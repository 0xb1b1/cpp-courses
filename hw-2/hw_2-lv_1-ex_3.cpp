// Для заданных a и b получить с = max(a, b), если а > 0 или с = min(a, b), если а <= 0

#include <iostream>	// i/o capability
#include <string>

using namespace std;	// nothing else is included

int main() {
	string a_s, b_s, ans_str = "Your answer: ";
	double a, b;
	cout << "Enter a: "; getline(cin, a_s); cout << "\nEnter b: "; getline(cin, b_s); cout << endl;
	a = stod(a_s); b = stod(b_s);
	if(a > 0.0) {
		if(b >= a) { cout << ans_str << b_s << endl; return(0); } else {
			cout << ans_str << a_s << endl; return(0);}
	} else {
		if(b >= a) { cout << ans_str << a_s << endl; return(0); } else {
                        cout << ans_str << b_s << endl; return(0);}
	}
	return(1);
}
