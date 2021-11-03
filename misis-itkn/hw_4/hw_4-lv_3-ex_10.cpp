#include <iostream>

using namespace std;

int main() {
    // Input data
    int rows = 6, columns = 7;
    int input_matrix[rows][columns] =  {{3,3,2,4,1,3,1},
                                        {1,2,4,4,1,4,2},
                                        {4,2,4,2,6,1,9},
                                        {3,6,4,3,2,4,1},
                                        {4,4,2,3,4,3,5},
                                        {2,4,2,6,3,3,7}};

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

    // Sort rows with even indices in descending order, with odd ones - in ascending order
    for(int row = 0; row < rows; row++) {
        if(row % 2 == 0) {
            for(int column = 0; column < columns; column++) {
                int biggest_value_to_swap = input_matrix[row][column],
                    biggest_value_to_swap_column = column;
                for(int column_search = column + 1; column_search < columns; column_search++) {
                    if(input_matrix[row][column_search] > biggest_value_to_swap) {
                        biggest_value_to_swap = input_matrix[row][column_search];
                        biggest_value_to_swap_column = column_search;
                    }
                }
                // Swap current item with the one at biggest_value_to_swap_column
                int swap_value = input_matrix[row][column];
                input_matrix[row][column] = input_matrix[row][biggest_value_to_swap_column];
                input_matrix[row][biggest_value_to_swap_column] = swap_value;
            }
        }
        else {
            for(int column = 0; column < columns; column++) {
                int smallest_value_to_swap = input_matrix[row][column],
                    smallest_value_to_swap_column = column;
                for(int column_search = column + 1; column_search < columns; column_search++) {
                    if(input_matrix[row][column_search] < smallest_value_to_swap) {
                        smallest_value_to_swap = input_matrix[row][column_search];
                        smallest_value_to_swap_column = column_search;
                    }
                }
                // Swap current item with the one at smallest_value_to_swap_column
                int swap_value = input_matrix[row][column];
                input_matrix[row][column] = input_matrix[row][smallest_value_to_swap_column];
                input_matrix[row][smallest_value_to_swap_column] = swap_value;
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
