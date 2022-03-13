#include <iostream>
 
int main() {
  int input;
  std::cin >> input;
  int guess = input + 1;
  while( guess > 0 ) {
    int th = guess / 1000, hu = (guess / 100) % 10, doz = (guess / 10) % 10, un = guess % 10;
    if( (th != hu) && (th != doz) && (th != un) && (hu != doz) && (hu != un) && (doz != un) ) {
      std::cout << guess << std::endl;
      break;
    } else {
      guess += 1;
    }
  }
}
