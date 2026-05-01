#include <iostream>
#include <string>
#include "Rational.hpp"

using namespace std;

void p(string content, bool new_line = true) {
    if (new_line) cout << content << endl;
    else cout << content;
}

int main() {
    p("=== RATIONAL TEST ===");
    Rational myrat = Rational(3, 5);
    Rational myrat2 = Rational("2/5");
    Rational myrat3 = myrat + myrat2;
    Rational myrat4 = myrat3 / 2;
    Rational myrat5 = Rational(4) / Rational("2/5");
    cout << "myrat3: " << myrat3.toString() << endl;
    cout << "myrat4: " << myrat4.toString() << endl;
    cout << "myrat5: " << myrat5.toString() << endl;
    return 0;
}