#include <iostream>
#include <algorithm>
#include <iterator>

int main(int argc, char* argv[]) {
    // print all command line arguments
    std::cout << "name of program: " << argv[0] << std::endl ;

    if(argc > 1) {
        std::cout << "there are " << argc-1 << " (more) arguments, they are:\n" ;

        std::copy(
            argv+1,
            argv+argc,
            std::ostream_iterator<const char*>(std::cout, "\n")
        );
    }
}
