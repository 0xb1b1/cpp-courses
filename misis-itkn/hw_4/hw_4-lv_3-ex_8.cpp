#include <iostream>

using namespace std;

int main() {
    // Input data
    int rows = 7, columns = 5;
    int input_matrix[rows][columns] =  {{ 7,-4, 7, 4, 6},
                                        { 7,-8,-8, 2, 6},
                                        { 1, 2,-9,-2, 6},
                                        { 3, 1, 4,-7, 2},
                                        {-3, 2,-7,-3,-5},
                                        { 2, 2, 5, 2,-7},
                                        {-9, 8, 2,-6, 1}};
    
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

    // Reorder rows in input_matrix so that those with mostly positive values\
        are on top of the array
    for(int row = 0; row < rows - 1; row++) {
        // Find the current row's amount of positive values
        int positive_values_current_row = 0;
        for(int column = 0; column < columns; column++) {
            if(input_matrix[row][column] > 0) {
                positive_values_current_row++;
            }
        }
        // Find a row below the current one with the largest amount of positive numbers
        int max_of_positive_values_search_rows = 0, max_of_positive_values_search_rows_row;
        for(int row_search = row + 1; row_search < rows; row_search++) {
            int positive_values_search_row = 0;
            for(int column_search = 0; column_search < columns; column_search++) {
                if(input_matrix[row_search][column_search] > 0) {
                    positive_values_search_row++;
                }
            }

            // If current row's amount of positive values is prevalent to the\
                one written to max_of_positive_values_search_rows, write it to\
                max_of_positive_values_search_rows
            if(positive_values_search_row > max_of_positive_values_search_rows) {
                max_of_positive_values_search_rows = positive_values_search_row;
                max_of_positive_values_search_rows_row = row_search;
            }
        }

        // Swap columns if the smallest value in the current row is smaller than\
        the maximum value of the smallest numbers in rows below
        if(positive_values_current_row < max_of_positive_values_search_rows) {
            int swap_current_row[columns];
            for(int swap_column = 0; swap_column < columns; swap_column++) {
                swap_current_row[swap_column] = input_matrix[row][swap_column];
            }
            for(int swap_column = 0; swap_column < columns; swap_column++) {
                input_matrix[row][swap_column] = input_matrix[max_of_positive_values_search_rows_row][swap_column];
            }
            for(int swap_column = 0; swap_column < columns; swap_column++) {
                input_matrix[max_of_positive_values_search_rows_row][swap_column] = swap_current_row[swap_column];
            }
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
