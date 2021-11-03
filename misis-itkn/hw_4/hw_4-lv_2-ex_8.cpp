#include <iostream>

using namespace std;

int main() {
    // Input data
    int rows = 6, columns = 6;
    int input_matrix[rows][columns] =  {{-7,-4, 7, 4,-6, 3},
                                        { 7,-8, 8, 2,-6,-4},
                                        { 1, 2, 9, 2, 6, 9},
                                        {-3, 1, 4,-3,-2,-4},
                                        { 2, 2, 5, 7, 2, 7},
                                        { 2,-8, 2,-6, 1, 2}};
    
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

    // Search for the biggest elements in each incremental pair of rows and swap them
    for(int row_pair = 0; row_pair < rows; row_pair += 2) {
        int biggest_element_temp_row = input_matrix[row_pair][0],
        biggest_element_first_row_column = 0, biggest_element_second_row_column = 0;

        // Search for the biggest element in the first row of a pair
        for(int column = 0; column < columns; column++) {
            if(input_matrix[row_pair][column] > biggest_element_temp_row) {
                biggest_element_temp_row = input_matrix[row_pair][column];
                biggest_element_first_row_column = column;
            }
        }

        // Search for the biggest element in the second row of a pair
        biggest_element_temp_row = input_matrix[row_pair + 1][0];
        for(int column = 0; column < columns; column++) {
            if(input_matrix[row_pair + 1][column] > biggest_element_temp_row) {
                biggest_element_temp_row = input_matrix[row_pair + 1][column];
                biggest_element_second_row_column = column;
            }
        }

        // Swap the pair of values
        int temp_biggest_element_first_row_swap = input_matrix[row_pair][biggest_element_first_row_column];
        input_matrix[row_pair][biggest_element_first_row_column] = input_matrix[row_pair + 1][biggest_element_second_row_column];
        input_matrix[row_pair + 1][biggest_element_second_row_column] = temp_biggest_element_first_row_swap;
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
