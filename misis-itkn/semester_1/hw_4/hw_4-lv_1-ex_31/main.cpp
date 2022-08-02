#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Input data
    int rows = 5, columns = 8;
    int input_matrix[rows][columns] =  {{7,-4, 8, 4,-6,3, 6, 0},
                                        {7,-8, 8, 2,-6,4,-6, 0},
                                        {1, 2,-4, 2, 6,9, 2, 0},
                                        {3, 1, 4, 3,-2,4, 3, 0},
                                        {2,-8, 2,-6, 1,4, 7, 0}};
                                         // ^ Smallest value
    vector <int> input_vector = {6,9,6,9,6};
    
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

    // Find the smallest value in the fifth row (in input_matrix) and save its column
    int smallest_value_fifth_row_column = 0, smallest_value_fifth_row = input_matrix[4][0];
    for(int column = 0; column < columns - 1; column++) {
        if(input_matrix[4][column] < smallest_value_fifth_row) {
            smallest_value_fifth_row = input_matrix[4][column];
            smallest_value_fifth_row_column = column;
        }
    }

    // Move columns after the one declared in smallest_value_fifth_row_column
    for(int column = columns - 1; column > smallest_value_fifth_row_column; column--) {
        for(int row = 0; row < rows; row++) {
            input_matrix[row][column] = input_matrix[row][column - 1];
        }
    }

    // Insert input_vector into the space in input_matrix freed by the previous operation
    for(int row = 0; row < input_vector.size(); row++) {
        input_matrix[row][smallest_value_fifth_row_column + 1] = input_vector[row];
    }

    // Output the input matrix
    cout << "Output matrix:\n";
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

    return(0);
}
