#include <iostream>

using namespace std;

int main() {
    int array_size = 10,
        input_array[array_size] = {1,2,3,4,5,6,7,8,9,1},
        p = 3, q = 7; //, p_pos = -1, q_pos = -1;

    /*for(int element = 0; element < array_size; element++) {
        if(p_pos == -1 && input_array[element] == p) {
            p_pos = element;
        }
        if(q_pos == -1 && input_array[element] == q) {
            q_pos = element;
        }
    }*/

    int clenched = 0; // = q_pos - p_pos - 1;
    for(int element = 0; element < array_size; element++) {
        if(p < input_array[element] && input_array[element] < q) {
            clenched++;
        }
    }

    cout << "Input array: ";
    for(int element = 0; element < array_size; element++) {
        cout << input_array[element] << " ";
    } cout << endl;

    cout << "Number of elements trapped between "
        << p << " and " << q << ": " << clenched << ".\n";

    return(0);
}
