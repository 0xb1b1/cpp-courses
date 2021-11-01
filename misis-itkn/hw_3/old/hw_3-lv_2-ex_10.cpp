#include <iostream>

using namespace std;

int main() {
        double input_array[10] = {-8.12,-9999,-3.11,1,-43,9324,55,-129,21,12};

        double pos_min_num = input_array[0];
        int pos_min_num_index;
        for(int i = 0; i < 10; i++) {
                if(input_array[i] < pos_min_num && input_array[i] > 0) {
                        pos_min_num = input_array[i];
                        pos_min_num_index = i;
                }
        }

	double output_array[9];
	bool pos_min_deleted = false;
	for(int i = 0; i < 10; i++) {
		if(!pos_min_deleted && i != pos_min_num_index) {
			output_array[i] = input_array[i];
		} else if(pos_min_deleted && i != pos_min_num_index) {
			output_array[i - 1] = input_array[i];
		} else if(!pos_min_deleted && i == pos_min_num_index) {
			pos_min_deleted = true;
		}

	}

	for(int i = 0; i < 9; i++) {
		cout << output_array[i] << " ";
	}
	cout << endl;

	return(0);
}
