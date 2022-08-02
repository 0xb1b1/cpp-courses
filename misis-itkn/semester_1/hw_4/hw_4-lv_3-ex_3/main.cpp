#include <iostream>

using namespace std;

int main() {
    // Input data
    int rows = 4, columns = 4;
    int input_matrix[rows][columns] =  {{7,4,7,4},
                                        {7,8,8,2},
                                        {1,2,9,2},
                                        {3,1,4,3}};
    
    // Output the input matrix before changing it
    cout << "Input matrix:\n";
    cout << "[";
    for(int row = 0; row < rows; row++) {
        cout << "[";
        for(int column = 0; column < columns; column++) {
            if(input_matrix[row][column] > -1) { cout << " "; }
            if(column != columns - 1) { cout << input_matrix[row][column] << ","; }
            else { cout << input_matrix[row][column]; }
        }
        if(row != rows - 1) { cout << "],\n "; }
        else { cout << "]"; }
    } cout << "]" << endl;

    // Create an array that is (rows * 2 - 1) long
    int output_array[rows * 2 - 1];

    // Calculate all top-left diagonal array sums and put them into output_array
    /*int offset = 0;
    for(int row = rows - 1; row >= 0; row--) {
        int sum_0 = 0, sum_1 = 0;
        for(int column = row; column < rows; column++) {    // These get inverted, so "row" and "column" don't make much sense
            sum_0 += input_matrix[row][column];
            sum_1 += input_matrix[column][row];
        }
        output_array[offset] = sum_0;
        output_array[row * 2 - 2 - offset] = sum_1;
        offset++;
    }*/
    for(int row = 0; row < rows; row++) {
        int sumo = 0, sums = 0;
        for(int column = 0; column <= row; column++) {
            sumo += input_matrix[rows - 1 - row + column][column];
            sums += input_matrix[column][rows - 1 - row + column];
        }
        output_array[row] = sumo;
        output_array[(rows * 2 - 1) - row - 1] = sums;
    }

    // Output the output array
    cout << "Output array:\n";
    cout << "[";
    for(int element = 0; element < rows * 2 - 1; element++) {
        if(element != rows * 2 - 2) { cout << output_array[element] << ", "; }
        else { cout << output_array[element]; }
    } cout << "]\n";

    return(0);
}
