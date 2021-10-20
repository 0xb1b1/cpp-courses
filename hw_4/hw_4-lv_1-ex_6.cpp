#include <iostream>
#include <string>   // to create a 1d array, not necessary

using namespace std;

int main() {
    int rows = 4, columns = 7;
    int input_matrix[4][7] =   {{1,2,3,4,5,6,7},
                                {8,9,0,1,2,3,4},
                                {5,6,7,8,9,0,1},
                                {2,3,4,5,6,7,8}};
    string min_num_coords[4]; // doesn't work
    //fill(*input_matrix, *input_matrix + rows*columns, 0); // for later: init an empty matrix
    
    int column_counter = 0, path_sum = 0, min_num_coords_current_member = 0;
    for(int row = 0; row < 4; row++) {
        int min_num = input_matrix[row][0];
        string min_num_index = to_string(row) + "," + to_string(0);  // moved for convenience
        for(int column = 1; column < 7; column++) {
            if(input_matrix[row][column] < min_num) {
                min_num = input_matrix[row][column];
                min_num_index = to_string(row) + "," + to_string(column);
            }
       }
       min_num_coords[min_num_coords_current_member] = min_num_index;
       min_num_coords_current_member++;
    }

    for(int i = 0; i < 4; i++) {
        cout << min_num_coords[i] << " ";
    }
    cout << endl;

    return(0);
}