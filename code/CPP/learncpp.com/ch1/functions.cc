#include "iostream"

// void means the function does not return a value to the caller
void returnNothing() {
    std::cout << "Hi" << std::endl;
    // This function does not return a value so no return statement is needed
}

int main() {
    returnNothing(); // okay: function returnNothing() is called, no value is returned

    // std::cout << returnNothing(); // error: this line will not compile.  You'll need to comment it out to continue.

    return 0;
}
