#include <iostream>
 
int main() {
        int weight;
        std::cin >> weight;
        if( weight > 3 && weight % 2 == 0 ) {
                std::cout << "YES";
        } else {
                std::cout << "NO";
        }
 
        return(0);
}
