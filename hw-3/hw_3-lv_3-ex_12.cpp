#include <iostream>
#include <string>   // to get normal-looking output using arrayToString() and for debug purposes

using namespace std;

string arrayToString(double input_array[], int array_size) {
	string string_output = "";
	bool first_element = true;
        int passed_elements = 0;
        string_output += "[";
        for(int i = 0; i < array_size; i++) {
                string_output += to_string(input_array[i]);
                first_element = false;
                passed_elements++;
                if(!first_element && passed_elements != array_size) { string_output += ", "; }
        }
        string_output += "]";
	
	return(string_output);
}

string g_debug_arg = "--debug", g_debug_arg_short = "-d";

int main(int argc, char *argv[]) {
    bool args_present = true, debug_mode = false;
    if(argc == 1) { args_present = false; }
    if(args_present) { if(argv[1] == g_debug_arg || argv[1] == g_debug_arg_short) { debug_mode = true; } }
    // test input_array #1
    double input_array[12] = {5,-6,7,8,9,0,-1,2,3,2,-3,2};
    // test input_array #2
    //double input_array[10] = {1,2,3,8,-6,-5,-4,3,2,1};
    // test input_array #3
    //double input_array[8] = {123.12,-222,41,555.53,352,1,-555.53,123.12};

    int input_array_size = sizeof(input_array) / sizeof(*input_array);

    int negative_numbers_count = 0;
    for(int i = 0; i < input_array_size; i++) {
        if(input_array[i] < 0) {
            negative_numbers_count++;
            if(debug_mode) { cout << "NEGATIVE NUM: " << input_array[i] << endl; }
        }
    }

    int non_negative_numbers_count = input_array_size - negative_numbers_count; 
    if(debug_mode) { cout << "NON-NEGATIVE NUMBERS COUNT: " << non_negative_numbers_count << endl; }
    int non_negative_number_indices[non_negative_numbers_count], non_negative_number_indices_array_current_index = 0;
    for(int i = 0; i < input_array_size; i++) {
        if(input_array[i] >= 0) {
            non_negative_number_indices[non_negative_number_indices_array_current_index] = i;
            if(debug_mode) { cout << "ADDED " << input_array[i] << " TO NON-NEGATIVES AT INDEX " << i << endl; }
            non_negative_number_indices_array_current_index++;
        }
    }

    if(debug_mode) {
        cout << "NON-NEGATIVE NUMBER INDICES: ";
        for(int i = 0; i < non_negative_numbers_count; i++) {
            cout << non_negative_number_indices[i] << " ";
        }
        cout << endl;
    }

    double output_array[non_negative_numbers_count];
    int non_negative_number_indices_current_member = 0;
    for(int i = 0; i < non_negative_numbers_count; i++) {
        output_array[i] = input_array[non_negative_number_indices[non_negative_number_indices_current_member]];
        if(debug_mode) { cout << "ADDED THIS NUMBER TO OUTPUT: " << input_array[non_negative_number_indices[non_negative_number_indices_current_member]] << endl; }
        non_negative_number_indices_current_member++;
    }

    cout << arrayToString(output_array, non_negative_numbers_count) << endl;

    return(0);
}