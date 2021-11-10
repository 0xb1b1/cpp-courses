#include <iostream>

using namespace std;

int main() {
    // Input data
    int rows = 6, columns = 7;
    int input_matrix[rows][columns] =  {{-7,-4, 7, 4,-6, 3,-1},
                                        { 7,-8, 8, 2,-6,-4, 5},
                                        { 1, 2, 9, 2, 6, 9,-9},
                                        {-3, 1, 4,-3,-2,-4, 0},
                                        { 2, 2, 5, 7, 2, 7, 2},
                                        { 2,-8, 2,-6, 1, 2,-4}};
    
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

    // Arrange elements of every row in reverse order
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < column / 2 + 2; column++) {
            int swap_first_element = input_matrix[row][column];
            input_matrix[row][column] = input_matrix[row][columns - column - 1];
            input_matrix[row][columns - column - 1] = swap_first_element;
        }
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
