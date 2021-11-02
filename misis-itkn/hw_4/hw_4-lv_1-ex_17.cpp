#include <iostream>

using namespace std;

int main() {
    // Input data
    int rows = 6, columns = 7;
    int input_matrix[rows][columns] =  {{3,3,2,4,1,3,1},
                                        {1,2,4,4,1,4,2},
                                        {4,2,4,2,6,1,9},
                                        {3,6,4,3,2,4,1},
                                        {4,4,2,3,4,3,5},
                                        {2,4,2,6,3,3,7}};

    // Output the input matrix before changing it
    cout << "Input matrix:\n";
    cout << "[";
    for(int row = 0; row < rows; row++) {
        cout << "[";
        for(int column = 0; column < columns; column++) {
            if(column != columns - 1) { cout << input_matrix[row][column] << ","; }
            else { cout << input_matrix[row][column]; }
        }
        if(row != rows - 1) { cout << "],\n "; }
        else { cout << "]"; }
    }
    cout << "]" << endl;

    // Search for the smallest value in each row and swap it with the first value\
    in the same row
    for(int row = 0; row < rows; row++) {
        int min_row_value = input_matrix[row][0], min_row_value_column = -1;
        for(int column = 0; column < columns; column++) {
            if(input_matrix[row][column] < min_row_value) {
                min_row_value = input_matrix[row][column];
                min_row_value_column = column;
            }
        }

        // Swap the first value for the smallest one and vice versa
        if(min_row_value_column != -1) {
            int min_first_value_swap = input_matrix[row][0],
                min_swap_value = input_matrix[row][min_row_value_column];
            input_matrix[row][0] = min_swap_value;
            input_matrix[row][min_row_value_column] = min_first_value_swap;
        }
    }

    // Output the input matrix
    cout << "Output matrix:\n";
    cout << "[";
    for(int row = 0; row < rows; row++) {
        cout << "[";
        for(int column = 0; column < columns; column++) {
            if(column != columns - 1) { cout << input_matrix[row][column] << ","; }
            else { cout << input_matrix[row][column]; }
        }
        if(row != rows - 1) { cout << "],\n "; }
        else { cout << "]"; }
    }
    cout << "]" << endl;

    return(0);
}
