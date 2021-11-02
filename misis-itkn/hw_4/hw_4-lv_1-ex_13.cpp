#include <iostream>

using namespace std;

#define DIVIDER cout << "--------------------\n";

string g_debug_arg = "--debug", g_debug_arg_short = "-d";

int main(int argc, char *argv[]) {
    bool args_present = true, debug_mode = false;
    if(argc == 1) { args_present = false; }
    if(args_present) { if(argv[1] == g_debug_arg || argv[1] == g_debug_arg_short) { debug_mode = true; } }
    if(args_present && !debug_mode) { cout << "Usage: -d/--debug - Information for debugging purposes (optional)\nTerminated\n"; return(-1); }
    if(debug_mode) { cout << "DEBUG MODE ACTIVATED\n"; }

    int rows = 5, columns = 5, column_to_swap = 3;
    int input_matrix[rows][columns] =  {{1,2,3,4,5},
                                        {1,5,4,1,3},
                                        {1,9,1,1,4},    // biggest element here, position 1
                                        {2,2,3,7,3},
                                        {2,2,4,1,1}};
                                            // ^ swap this column with the one containing the biggest element in it

    // Search for the biggest number in the top-left diagonal array
    int biggest_num_location[2] = {0,0}, biggest_num = input_matrix[0][0],
        search_current_column = 0;
    for(int row = 0; row < rows; row++) {
        if(input_matrix[row][search_current_column] > biggest_num) {
            biggest_num = input_matrix[row][search_current_column];
            biggest_num_location[0] = row;
            biggest_num_location[1] = search_current_column;
        }
        search_current_column++;
    }

    if(debug_mode) { DIVIDER cout << "DEBUG: biggest_num: " << biggest_num << "\nLOCATION: [" << biggest_num_location[0] << "," << biggest_num_location[1] << "]" << endl; DIVIDER }

    // copy the 3rd column to swap_third_column
    int swap_column[rows], swap_column_current_member = 0;
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            if(column == column_to_swap) {
                swap_column[swap_column_current_member] = input_matrix[row][column];
                swap_column_current_member++;
            }
        }
    }

    // copy the column with the biggest member to the 3rd column
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            if(column == biggest_num_location[1]) {
                input_matrix[row][column_to_swap] = input_matrix[row][column];
            }
        }
    }

    // copy swap_column into the place of the column with the biggest member
    swap_column_current_member = 0;
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            if(column == biggest_num_location[1]) {
                input_matrix[row][column] = swap_column[swap_column_current_member];
                swap_column_current_member++;
            }
        }
    }

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