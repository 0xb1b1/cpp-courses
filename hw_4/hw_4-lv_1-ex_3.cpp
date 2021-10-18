#include <iostream>

using namespace std;

int main() {
    int input_matrix[4][4] =  {{1,2,3,4},
                    {5,6,7,8},
                    {9,1,2,3},
                    {4,5,6,7}};

    int column_counter = 0, path_sum = 0;
    for(int row = 0; row < 4; row++) {
       path_sum += input_matrix[row][column_counter];
       column_counter++;
    }

    cout << "Path sum: " << path_sum << endl;

    return(0);
}