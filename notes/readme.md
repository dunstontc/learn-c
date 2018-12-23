# Notes

# Types


## Primitive Types
- `int` 
  - Integer; a whole number.
- `double` 
  - A double-precision floating point value.
- `char` 
  - A single character.
- `void` 
  - Valueless special purpose type. 
- `float` 
  - Floating point value; ie a number with a fractional part.
- `short`
- `long`
- `long long`



## Misc

```c++
// When executing a program from the IDE, the console window blinks and then closes immediately.
#include "iostream"
#include "limits"
// #include "pch.h" // For Windows (maybe)

std::cin.clear(); // reset any error flags
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
std::cin.get(); // get one more char from the user
```

