#include <iostream>	// i/o capability

using namespace std;	// nothing else is included

int main() {
	int g_amoeba_count = 10;

	for(int hour = 3; hour < 25; hour += 3) {
		g_amoeba_count *= 2;
		cout << "After " << hour << " hours there will be " << g_amoeba_count << " amoebas." << endl;
	}
	return(0);
}
