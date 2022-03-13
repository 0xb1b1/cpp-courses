#include <iostream>

int main() {
    int n;
    long long a[1010];
    std::cin >> n;
    
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        if(a[i] % 2 == 0) { a[i] = a[i] - 1; }
    }

    for(int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;

    return(0);
}
