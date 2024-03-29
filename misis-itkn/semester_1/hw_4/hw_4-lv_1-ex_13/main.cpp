#include <iostream>

using namespace std;

#define DIVIDER cout << "--------------------\n";

string g_debug_arg = "--debug", g_debug_arg_short = "-d";

int main() {
    // Input data
    int rows = 5, columns = 5, column_to_swap = 3;
    int input_matrix[rows][columns] =  {{1,2,3,4,5},
                                        {1,7,4,1,3},
                                        {1,9,1,1,4},    // biggest element here, position 1
                                        {2,2,3,5,3},
                                        {2,2,4,1,1}};
                                            // ^ swap this column with the one containing the biggest element in it

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

    // Search for the biggest number in the top-left diagonal array
    int biggest_num_location, biggest_num = input_matrix[0][0];
    for(int row = 0; row < rows; row++) {
        if(input_matrix[row][row] > biggest_num) {
            biggest_num = input_matrix[row][row];
            biggest_num_location = row;
        }
    }

    // Copy the 3rd column to swap_column
    int swap_column[rows], swap_column_current_member = 0;
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            if(column == column_to_swap) {
                swap_column[swap_column_current_member] = input_matrix[row][column];
                swap_column_current_member++;
            }
        }
    }

    // Copy the column with the biggest member to the 3rd column
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            if(column == biggest_num_location) {
                input_matrix[row][column_to_swap] = input_matrix[row][column];
            }
        }
    }

    // Copy swap_column into the place of the column with the biggest member
    swap_column_current_member = 0;
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            if(column == biggest_num_location) {
                input_matrix[row][column] = swap_column[swap_column_current_member];
                swap_column_current_member++;
            }
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
