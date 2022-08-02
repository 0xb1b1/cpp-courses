#include <iostream>

using namespace std;

#define DIVIDER cout << "--------------------\n";

string g_debug_arg = "--debug", g_debug_arg_short = "-d";

int main(int argc, char *argv[]) {
    // Add debug mode
    bool args_present = true, debug_mode = false;
    if(argc == 1) { args_present = false; }
    if(args_present) { if(argv[1] == g_debug_arg || argv[1] == g_debug_arg_short) { debug_mode = true; } }
    if(debug_mode) { cout << "DEBUG MODE ACTIVATED\n"; }

    // Input data
    int rows = 6, columns = 7;
    int input_matrix[rows][columns] =  {{1,3,2,4,1,3,1},
                                        {1,2,4,4,1,4,2},
                                        {1,2,4,2,6,9,2},    // The biggest element here, position 5; delete this row
                                        {3,6,4,3,2,4,3},
                                        {2,4,2,5,2,1,1},
                                        {2,4,2,6,3,4,7}};
                                                // ^ Delete this column

    // Find the biggest value in input_matrix and save its coords
    int biggest_num_location[2] = {0,0}, biggest_num = input_matrix[0][0];
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            if(input_matrix[row][column] > biggest_num) {
                biggest_num = input_matrix[row][column];
                biggest_num_location[0] = row;
                biggest_num_location[1] = column;
            }
        }
    }

    // Output debug information
    if(debug_mode) { DIVIDER cout << "DEBUG: biggest_num: " << biggest_num << "\nLOCATION: [" << biggest_num_location[0] << "," << biggest_num_location[1] << "]" << endl; DIVIDER }

    // Create the output matrix and put modified data from input_matrix into it
    int output_matrix[rows - 1][columns - 1];
    int output_matrix_current_row = 0, output_matrix_current_column = 0;
    for(int row = 0; row < rows; row++) {
        if(row == biggest_num_location[0]) { continue; }
        for(int column = 0; column < columns; column++) {
            if(column == biggest_num_location[1]) { continue; }
                output_matrix[output_matrix_current_row][output_matrix_current_column] = input_matrix[row][column];
                output_matrix_current_column++;
        }
        output_matrix_current_row++;
        output_matrix_current_column = 0;
    }

    // Output the input matrix
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

    // Output the output matrix
    cout << "Output matrix:\n";
    cout << "[";
    for(int row = 0; row < rows - 1; row++) {
        cout << "[";
        for(int column = 0; column < columns - 1; column++) {
            if(column != columns - 2) { cout << output_matrix[row][column] << ","; }
            else { cout << output_matrix[row][column]; }
        }
        if(row != rows - 2) { cout << "],\n "; }
        else { cout << "]"; }
    }
    cout << "]" << endl;

    return(0);
}
