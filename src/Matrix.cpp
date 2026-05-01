#include "Matrix.hpp"

#ifdef DEBUG_MATRIX
#include <iostream>
using std::cout, std::cin, std::endl;

// Print helper
template <typename... Args>
void print(Args... args) {
    ((cout << args << " "), ...);
    cout << endl;
}

#endif


#ifdef DEBUG_MATRIX
int main() {
    print("=== MATRIX MODULE DEBUG ===\n");

    

    return 0;
}
#endif