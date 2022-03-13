#include <iostream>

using namespace std;

int main() {
    // Input data
    int rows = 5, columns = 7;
    int input_matrix[rows][columns] =  {{7,-4, 8, 4,-6,3, 6},
                                        {7,-8, 8, 2,-6,4,-6},
                                        {1, 2,-4, 2, 6,9, 2},
                                        {3, 1, 4, 3,-2,4, 3},
                                        {2,-8, 2,-6, 3,4, 7}};
                                                  // ^ Delete this column
    
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

    // Find the smallest value in the second row (in input_matrix) and save its column
    int smallest_abs_second_row_column = 0, smallest_abs_second_row = input_matrix[1][0];
    for(int column = 0; column < columns; column++) {
        if(abs(input_matrix[1][column]) < smallest_abs_second_row) {
            smallest_abs_second_row = abs(input_matrix[1][column]);
            smallest_abs_second_row_column = column;
        }
    }

    // Collapse columns past smallest_abs_second_row_column
    for(int column = smallest_abs_second_row_column + 1; column < columns; column++) {
        for(int row = 0; row < rows; row++) {
            input_matrix[row][column - 1] = input_matrix[row][column];
        }
    }

    /*  // Removed per request
    // Create output_matrix to correspond with the reduced data size of input_array
    // Create output_matrix with its size reduced by [][1]
    int output_matrix[rows][columns];
    // Copy input_array into output_array
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns - 1; column++) {
            output_matrix[row][column] = input_matrix[row][column];
        }
    }*/


    // Output the output matrix
    cout << "Output matrix:\n";
    cout << "[";
    for(int row = 0; row < rows; row++) {
        cout << "[";
        for(int column = 0; column < columns - 1; column++) {
            if(input_matrix[row][column] > -1) { cout << " "; }
            if(column != columns - 2) { cout << input_matrix[row][column] << ","; }
            else { cout << input_matrix[row][column]; }
        }
        if(row != rows - 1) { cout << "],\n "; }
        else { cout << "]"; }
    } cout << "]" << endl;

    return(0);
}
