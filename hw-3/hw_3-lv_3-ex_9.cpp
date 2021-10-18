#include <iostream>

using namespace std;

int main() {
    // test input_array #1
    //double input_array[12] = {5,6,7,8,9,0,1,2,3,2,3,2};
    // test input_array #2
    double input_array[10] = {1,2,3,8,6,5,4,3,2,1};
    // test input_array #3
    //double input_array[8] = {123.12,222,41,555.53,352,1,555.53,123.12};

    int input_array_size = sizeof(input_array) / sizeof(*input_array);

    int longest_streak = 1;
    bool increasing = true;

    // searching for the biggest increasing streak
    int streak = 1;
    for(int i = 0; i < input_array_size; i++) {
        if(input_array[i] < input_array[i + 1]) {
            streak++;
        } else {
            if(streak > longest_streak) {
                longest_streak = streak;
            }
            streak = 1;
        }
        if(streak > longest_streak) {
                longest_streak = streak;
            }
    }
    // searching for the biggest decreasing streak
    streak = 1;
    for(int i = 0; i < input_array_size; i++) {
        if(input_array[i] > input_array[i + 1]) {
            streak++;
        } else {
            if(streak > longest_streak) {
                longest_streak = streak;
                increasing = false;
            }
            streak = 1;
        }
        if(streak > longest_streak) {
                longest_streak = streak;
                increasing = false;
            }
    }

    cout << "The longest";
    if(increasing) { cout << " increasing "; } else { cout << " decreasing "; }
    cout << "string is " << longest_streak << " numbers long." << endl;

    return(0);
}