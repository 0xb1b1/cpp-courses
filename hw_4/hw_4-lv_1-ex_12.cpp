#include <iostream>
//#include <string>   // for string int2DMatrixToString

using namespace std;

#define DIVIDER cout << "--------------------\n";

string g_debug_arg = "--debug", g_debug_arg_short = "-d";

// it errors out "int (*)[(columns + -1)]"
/*string int2DMatrixToString(int input_matrix[][7], int rows, int columns) {   // useless as per error "declaration of ‘input_matrix’ as multidimensional array must have bounds for all dimensions except the first", but imma keep it
    string output_string = "[";
    for(int row = 0; row < rows; row++) {
        output_string += "[";
        for(int column = 0; column < columns; column++) {
            if(column != columns - 1) { output_string += to_string(input_matrix[row][column]) + ","; }
            else { output_string += to_string(input_matrix[row][column]); }
        }
        if(row != rows - 1) { output_string += "],\n"; }
        else { output_string += "]]"; }
    }
    return(output_string);
}*/

int main(int argc, char *argv[]) {
    bool args_present = true, debug_mode = false;
    if(argc == 1) { args_present = false; }
    if(args_present) { if(argv[1] == g_debug_arg || argv[1] == g_debug_arg_short) { debug_mode = true; } }
    if(debug_mode) { cout << "DEBUG MODE ACTIVATED\n"; }

    int rows = 6, columns = 7;
    int input_matrix[rows][columns] =  {{1,3,2,4,1,3,1},
                                        {1,2,4,4,1,4,2},
                                        {1,2,4,2,6,9,2},    // biggest element here, position 5
                                        {3,6,4,3,2,4,3},
                                        {2,4,2,5,2,1,1},
                                        {2,4,2,6,3,4,7}};

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
    if(debug_mode) { DIVIDER cout << "DEBUG: biggest_num: " << biggest_num << "\nLOCATION: [" << biggest_num_location[0] << "," << biggest_num_location[1] << "]" << endl; DIVIDER }

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

    //cout << int2DMatrixToString(output_matrix, (rows - 1), (columns - 1)) << endl;    // see reason for disabling above int main()

    return(0);
}