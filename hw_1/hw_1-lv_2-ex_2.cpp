#include <iostream>     // i/o capability

using namespace std;    // nothing else is included

int main() {
	int g_n = 1, g_p = 1;
	for(g_n; g_p * g_n < 30000; g_n += 3) { g_p *= g_n; }
	cout << g_n << endl;

	return(0);
}
