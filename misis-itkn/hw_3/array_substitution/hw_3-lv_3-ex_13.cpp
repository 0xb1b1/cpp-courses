#include <iostream>
#include <string>   // to get normal-looking output using arrayToString() and for debug purposes
//#include <algorithm> // for std::find [not used as per rules]
//#include <iterator> // for std::begin, std::end [not used as per rules]

using namespace std;

#define DIVIDER cout << "--------------------\n";

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

int findElement(double input_array[], int array_size, double element) { // find the first occurrence of a given array element; if not found, return -1, otherwise, return its index
    for(int i = 0; i < array_size; i++) {
        if(input_array[i] == element) {
            return(i);
        }
    }
    return(-1);
}

string g_debug_arg = "--debug", g_debug_arg_short = "-d";

int main(int argc, char *argv[]) {
    bool args_present = true, debug_mode = false;
    if(argc == 1) { args_present = false; }
    if(args_present) { if(argv[1] == g_debug_arg || argv[1] == g_debug_arg_short) { debug_mode = true; } }
    if(debug_mode) { cout << "DEBUG MODE ACTIVATED\n"; }

    // test input_array #1
    double input_array[12] = {1.235,2,23,22,63,44,44,63,11,11,11,23.11};

    int input_array_size = sizeof(input_array) / sizeof(*input_array);

    ////////// MOVED FROM THE BOTTOM (BELOW THE COMMENTED OUT CODE)
    double output_array_expanded[input_array_size];
    int output_array_expanded_current_member = 0;

    for(int i = 0; i < input_array_size; i++) {
        if(findElement(output_array_expanded, input_array_size, input_array[i]) == -1) {
            output_array_expanded[output_array_expanded_current_member] = input_array[i];
            output_array_expanded_current_member++;
        }
    }

    // truncate output_array
    int output_array_size = output_array_expanded_current_member;
    double output_array[output_array_size];
    for(int i = 0; i < output_array_size; i++) {
        output_array[i] = output_array_expanded[i];
        if(debug_mode) {
        DIVIDER
        cout << "PLACED " << output_array_expanded[i] << " INTO input_array_duplicate AT INDEX " << i << endl;
        }
        if(debug_mode) { DIVIDER }
    }

    cout << arrayToString(output_array, output_array_size) << endl;
    ////////// END MOVED FROM THE BOTTOM (BELOW THE COMMENTED OUT CODE)

    /*    
    double input_array_duplicate_expanded[input_array_size];
    int input_array_duplicate_expanded_current_member = 0;
    for(int i = 0; i < input_array_size; i++) {
        if(findElement(input_array_duplicate_expanded, input_array_size, input_array[i]) != -1) {
            continue;
        }
        for(int y = i + 1; y < input_array_size; y++) {
            if(debug_mode) { cout << "CHECKING " << input_array[i] << " AGAINST " << input_array[y] << endl; }
            if(input_array[i] == input_array[y]) {
                if(debug_mode) {
                    DIVIDER
                    cout << "THE PAIR SHOWN ABOVE CONTAINS DUPLICATES!\n"
                        << "OUTPUT OF findElement(): " << findElement(input_array_duplicate_expanded, input_array_size, input_array[i]) << endl
                        << "findElement() EQUALS TO -1? " << (findElement(input_array_duplicate_expanded, input_array_size, input_array[i]) == -1)  << endl;
                    }
                if(findElement(input_array_duplicate_expanded, input_array_size, input_array[i]) == -1) {
                    input_array_duplicate_expanded[input_array_duplicate_expanded_current_member] = input_array[i];
                    if(debug_mode) {
                        DIVIDER
                        cout << "ADDED TO DUPLICATE ELEMENTS: " << input_array[i] << endl
                            << "CURRENT MEMBER OF DUP ARRAY: " << input_array_duplicate_expanded_current_member << endl;
                    }
                }
                input_array_duplicate_expanded_current_member++;
                if(debug_mode) { DIVIDER }
                continue;
            }
        }
    }

    if(debug_mode) {
        DIVIDER
        cout << "LOOP FINISHED! DEBUG INFO:\n"
            << "input_array_duplicate_expanded_current_member: "
            << input_array_duplicate_expanded_current_member << endl;
    }

    if(debug_mode) {
        DIVIDER
        cout << "DISPLAYING VALUES OF input_array_duplicate_expanded\n";
        cout << "NOTE: SOME VALUES MAY BE UNPOPULATED; THIS WILL NOT BE HANDLED\n";
        for(int i = 0; i < input_array_size; i++) {
            cout << input_array_duplicate_expanded[i] << " ";
        }
        cout << endl;
    }

    // truncate input_array_duplicate_expanded for (possible) future designs
    int input_array_duplicate_size = input_array_duplicate_expanded_current_member - 1;
    double input_array_duplicate[input_array_duplicate_size];
    for(int i = 0; i < input_array_duplicate_size; i++) {
        input_array_duplicate[i] = input_array_duplicate_expanded[i];
        if(debug_mode) {
        DIVIDER
        cout << "PLACED " << input_array_duplicate_expanded[i] << " INTO input_array_duplicate AT INDEX " << i << endl;
        }
    }

    if(debug_mode) {
        DIVIDER
        cout << "DISPLAYING VALUES OF input_array_duplicate\n";
        for(int i = 0; i < input_array_duplicate_size; i++) {
            cout << input_array_duplicate[i] << " ";
        }
        cout << endl;
    }

    if(debug_mode) {
        DIVIDER
        cout << "TRUNCATING OUTPUT ARRAY\n";
    }
    */  // that was just a flex; i don't want to use pointers below

    return(0);
    }