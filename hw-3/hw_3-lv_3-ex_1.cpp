#include <iostream>

using namespace std;

int main() {
	int max_num_indices[8], counter = 0;
	double max_num = -9999999;
	double input_array[8] = {123.12,222,41,555.53,352,1,555.53,123.12};
	
	for(int i = 0; i < 10; i++) {
		if(input_array[i] > max_num) {
			counter = 0;
			max_num = input_array[i];
			max_num_indices[counter] = i;
			counter++;
		} else if(input_array[i] == max_num) {
			max_num_indices[counter] = i;
                        counter++;
		}
	}
	cout << "Max number: " << max_num << endl << "Indices: ";
	for(int i = 0; i < counter; i++) {
		cout << max_num_indices[i] << " ";
	}
	cout << endl;

	return(0);
}
	
