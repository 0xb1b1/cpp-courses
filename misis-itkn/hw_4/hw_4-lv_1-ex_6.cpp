#include <iostream>

using namespace std;

int main() {
    // Input data
    int rows = 4, columns = 7;
    int input_matrix[rows][columns] =  {{4,2,3,4,5,6,1},
                                        {8,9,0,1,2,3,4},
                                        {5,6,7,8,9,0,1},
                                        {2,3,4,5,6,7,8}};
    
    // Create output array containing coords for the smallest numbers
    int min_num_coords[4];
    
    // Find the smallest number in each row and write it to min_num_coords
    for(int row = 0; row < 4; row++) {
        int min_num = input_matrix[row][0],
            min_num_index = 0;
        for(int column = 1; column < 7; column++) {
            if(input_matrix[row][column] < min_num) {
                min_num = input_matrix[row][column];
                min_num_index = column; cout << "WRITTEN " << column << " TO min_num_index" << endl;
            }
        }
        min_num_coords[row] = min_num_index; cout << "WRT " << min_num_index << endl;
        cout << "row: " << row << endl;
    }

    // Output min_num_coords
    cout << "[";
    for(int element = 0; element < rows; element++) {
        if(element != rows - 1) { cout << min_num_coords[element] << ", ";}
        else { cout << min_num_coords[element]; }
    } cout << "]" << endl;

    return(0);
}