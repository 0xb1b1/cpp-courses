#include <iostream>

using namespace std;

int main() {
    // Input data
    int rows = 5, columns = 5;
    int input_matrix[rows][columns] =  {{7,-4, 8, 4,-6},
                                        {7,-8, 8, 2,-6},
                                        {1, 2,-4, 2, 6},
                                        {3, 1, 4, 3,-2},
                                        {2,-8, 2,-6, 1}};
    
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

    // Calculate borders for for-loop
    int starting_row = rows / 2;
    /*if(rows % 2 == 0) { starting_row = rows / 2; }
    else { starting_row = rows / 2 + 1; }*/

    for(int row = starting_row; row < rows; row++) {
        for(int column = 0; column <= row; column++) {
            input_matrix[row][column] = 1;
        }
    }
    
    cout << starting_row << endl;

    // Fill the bottom

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
