#include <iostream>
 
int main() {
        int path_len;
        std::cin >> path_len;
        int steps = (int)path_len / 5;
        int path_rem = path_len % 5;
        if( path_rem != 0 ) {
                steps++;
        }
 
        std::cout << steps;
 
        return(0);
}
