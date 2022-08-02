#include <iostream>

using namespace std;

int main() {
    // Input data
    int rows = 5, columns = 7;
    int input_matrix[rows][columns] =  {{7,-4, 8, 4,-6,3, 6},
                                        {7,-8, 1, 2,-6,4,-6},
                                        {0, 2,-4, 2, 6,0, 2},
                                        {3, 1, 4, 3,-2,0, 3},
                                        {2,-8, 2,-6, 3,4, 7}};
    
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

    // Find all rows with zeroes in them and move the next ones over them;\
        note how many times that was done to create output_array
    int zero_encounters_counter = 0;
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            if(input_matrix[row - zero_encounters_counter][column] == 0) {
                for(int override_row = (row - zero_encounters_counter); override_row < rows - 1; override_row++) {
                    for(int override_column = 0; override_column < columns; override_column++) {
                        input_matrix[override_row][override_column] = input_matrix[override_row + 1][override_column];
                    }
                }
                zero_encounters_counter++;
                break;  // To prevent the loop from counting multiple zeroes in one row
            }
        }
    }

    /*  // Removed per request
    // Create output_matrix to correspond with the reduced data size of input_array
    // Create output_matrix with its size reduced by [zero_encounters_counter][]
    int output_matrix[rows - zero_encounters_counter][columns];
    // Copy input_array into output_array
    for(int row = 0; row < rows - zero_encounters_counter; row++) {
        for(int column = 0; column < columns; column++) {
            output_matrix[row][column] = input_matrix[row][column];
        }
    }*/

    // Output the output matrix
    cout << "Output matrix:\n";
    cout << "[";
    for(int row = 0; row < rows - zero_encounters_counter; row++) {
        cout << "[";
        for(int column = 0; column < columns; column++) {
            if(input_matrix[row][column] > -1) { cout << " "; }
            if(column != columns - 1) { cout << input_matrix[row][column] << ","; }
            else { cout << input_matrix[row][column]; }
        }
        if(row != rows - 1 - zero_encounters_counter) { cout << "],\n "; }
        else { cout << "]"; }
    } cout << "]" << endl;

    return(0);
}
