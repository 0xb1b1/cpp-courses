#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string g_end_of_input = "";

int main() {
	int student_counter = 0, idiots = 0;
	double medians_sum = 0;
	string input_string, temp;

	do {
		int mark;

		cout << "Enter marks of student " << student_counter << ": ";
		getline(cin, input_string); 
		if(input_string == g_end_of_input) {
		cout << "\nTerminating input\n";
		break;
		}
		
		int student_marks[4];
		int current_mark = 0;
		bool invalid_input = false, idiot = false;
	
		stringstream input_stream(input_string);
		while(input_stream >> temp && !invalid_input) {
			try { mark = stoi(temp); }
			catch(invalid_argument& e) {
				cout << "Try again. Looping back...\n";
				invalid_input = true;
			}
			if(invalid_input) { continue; }
			student_marks[current_mark] = stoi(temp);
			current_mark++;
		}
		if(current_mark != 4) {
			cout << "Illegal amount of marks! Looping back...\n";
			continue;
		} if(invalid_input) { continue; }
		int student_marks_sum = 0;
		for(const int &current_mark : student_marks) {
			if(current_mark == 2) {
				idiot = true;
			}
			student_marks_sum += current_mark;
		}
		if(idiot) {
			idiots++;
		}
		medians_sum += (double)student_marks_sum / 4;
		student_counter++;
	} while(1);

	cout << fixed << setprecision(4) <<
		"Students counter: " << student_counter <<
		"\nIdiots: " << idiots <<
		"\nMedian: " << medians_sum / student_counter <<
		endl;
	return(0);
}
