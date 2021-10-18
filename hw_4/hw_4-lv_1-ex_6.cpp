#include <iostream>
#include <string>   // to create a 1d array

using namespace std;

int main() {
    int input_matrix[4][7] =   {{1,2,3,4,5,6,7},
                                {8,9,0,1,2,3,4},
                                {5,6,7,8,9,0,1},
                                {2,3,4,5,6,7,8}};
    string min_num_coords[4];

    int column_counter = 0, path_sum = 0;
    for(int row = 0; row < 4; row++) {
        int min_num = input_matrix[row][0];
        string min_num_index;  // moved for convenience
        for(int column = 1; column < 7; column++) {
            if(input_matrix[row][column] < min_num) {
                min_num = input_matrix[row][column];
                min_num_index = to_string(row) + "," + to_string(column);
            }
            min_num_coords[column] = min_num_index;
       }
    }

    /*for(int i = 0; i < 4; i++) {
        cout << min_num_coords[i] << " ";
    }
    cout << endl;*/

    return(0);
}