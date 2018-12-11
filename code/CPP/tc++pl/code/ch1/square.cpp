#include <iostream>
using namespace std; // make names from std visible without std:: (§2.4.2)

//square a double precision floating-point number
double square(double x) {
    return (x * x);
}

void print_square(double x) {
    cout << "the square of " << x << " is " << square(x) << "\n";
}

int main() {
    //print: the square of 1.234 is 1.52276
    print_square(1.234);
}
