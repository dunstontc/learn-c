# [Learn C the Hard Way](https://github.com/zedshaw/liblcthw)

<!-- TOC -->

- [[Learn C the Hard Way](https://github.com/zedshaw/liblcthw)](#learn-c-the-hard-wayhttpsgithubcomzedshawliblcthw)
  - [Notes](#notes)
    - [The Core Competencies](#the-core-competencies)
    - [Terms](#terms)
    - [Links](#links)
  - [Exercises](#exercises)
    - [Exercise 1: Dust Off That Compiler](#exercise-1-dust-off-that-compiler)
    - [Exercise 3: Formatted Printing](#exercise-3-formatted-printing)
      - [printf](#printf)
    - [Exercise 4: Debugging](#exercise-4-debugging)
    - [Exercise 5: Memorizing C Operators](#exercise-5-memorizing-c-operators)
      - [Arithmetic Operators](#arithmetic-operators)
      - [Relational Operators](#relational-operators)
      - [Logical Operators](#logical-operators)
      - [Bitwise Operators](#bitwise-operators)
      - [Assignment Operators](#assignment-operators)
      - [Data Operators](#data-operators)
    - [Exercise 6: Memorizing C Syntax](#exercise-6-memorizing-c-syntax)
      - [Keywords](#keywords)
    - [Exercise 7: Variables and Types](#exercise-7-variables-and-types)
    - [Exercise 8: If, Else-If, Else](#exercise-8-if-else-if-else)
    - [Exercise 9: While-Loop and Boolean Expressions](#exercise-9-while-loop-and-boolean-expressions)
    - [Exercise 10: Switch Statements](#exercise-10-switch-statements)
    - [Exercise 11: Arrays and Strings](#exercise-11-arrays-and-strings)
    - [Exercise 12: Sizes and Arrays](#exercise-12-sizes-and-arrays)
    - [Exercise 13: For-Loops and Arrays of Strings](#exercise-13-for-loops-and-arrays-of-strings)
    - [Exercise 14: Writing and Using Functions](#exercise-14-writing-and-using-functions)
    - [Exercise 15: Pointers, Dreaded Pointers](#exercise-15-pointers-dreaded-pointers)
    - [Exercise 16: Structs And Pointers To Them](#exercise-16-structs-and-pointers-to-them)
    - [Exercise 17: Heap and Stack Memory Allocation](#exercise-17-heap-and-stack-memory-allocation)
    - [Exercise 18: Pointers to Functions](#exercise-18-pointers-to-functions)
    - [Exercise 19: Zed’s Awesome Debug Macros](#exercise-19-zeds-awesome-debug-macros)
    - [Exercise 21: Advanced Data Types & Flow Control](#exercise-21-advanced-data-types--flow-control)
    - [Exercise 22: The Stack, Scope, and Globals](#exercise-22-the-stack-scope-and-globals)
    - [Exercise 24: Input, Output, Files](#exercise-24-input-output-files)
    - [Exercise 25: Variable Argument Functions](#exercise-25-variable-argument-functions)
    - [Exercise 27: Creative and Defensive Programming](#exercise-27-creative-and-defensive-programming)
    - [Exercise 31: Common Undefined Behavior](#exercise-31-common-undefined-behavior)
    - [Exercise 32: Double Linked Lists](#exercise-32-double-linked-lists)
    - [Exercise 33: Linked List Algorithms](#exercise-33-linked-list-algorithms)
    - [Exercise 34: Dynamic Array](#exercise-34-dynamic-array)
    - [Exercise 35: Sorting and Searching](#exercise-35-sorting-and-searching)
    - [Exercise 36: Safer Strings](#exercise-36-safer-strings)
    - [Exercise 37: Hashmaps](#exercise-37-hashmaps)
    - [Exercise 38: Hashmap Algorithms](#exercise-38-hashmap-algorithms)
    - [Exercise 39: String Algorithms](#exercise-39-string-algorithms)
    - [Exercise 40: Binary Search Trees](#exercise-40-binary-search-trees)

<!-- /TOC -->

## Notes

### The Core Competencies
- Reading & Writing
- Attention to Detail
- Spotting Differences
- Planning & Debugging

### Terms
- `include`
- header files
- `-Wall`
  - That command line option tells the compiler cc to report all warnings (which, in a sick twist of fate, isn’t actually all the warnings possible)

### Links
- [ex32.c](https://stackoverflow.com/questions/23851098/c-compile-errors-learn-c-the-hard-way-ex-32)


## Exercises

### Exercise 1: Dust Off That Compiler

### Exercise 3: Formatted Printing

#### printf

| Formatter |               Result               |
| :-------- | :--------------------------------- |
| `%c`      | character                          |
| `%d`      | decimal (integer) number (base 10) |
| `%e`      | exponential floating-point number  |
| `%f`      | floating-point number              |
| `%i`      | integer (base 10)                  |
| `%o`      | octal number (base 8)              |
| `%s`      | a string of characters             |
| `%u`      | unsigned decimal (integer) number  |
| `%x`      | number in hexadecimal (base 16)    |
| `%%`      | print a percent sign               |
| `\%`      | print a percent sign               |


### Exercise 4: Debugging
- `gdb` - [GNU Debugger](https://www.gnu.org/software/gdb/)
- `lldb` - [LLVM Debugger](https://lldb.llvm.org/)
- `valgrind` - (`brew install valgrind --HEAD`)

### Exercise 5: Memorizing C Operators

#### Arithmetic Operators
| Operator | Description |
| :------- | :---------- |
| `+`      | Add         |
| `-`      | Subtract    |
| `*`      | Multiply    |
| `/`      | Divide      |
| `%`      | Modulus     |
| `++`     | Increment   |
| `--`     | Decrement   |

#### Relational Operators
| Operator |    Description     |
| :------- | :----------------- |
| `==`     | Equal              |
| `!=`     | Not equal          |
| `>`      | Greater than       |
| `<`      | Less than          |
| `>=`     | Greater than equal |
| `<=`     | Less than equal    |

#### Logical Operators
| Operator |   Description   |
| :------- | :-------------- |
| `&&`     | Logical and     |
| `||`     | Logical or      |
| `!`      | Logical not     |
| `?:`     | Logical ternary |

#### Bitwise Operators
| Operator |       Description       |
| :------- | :---------------------- |
| `&`      | Bitwise and             |
| `|`      | Bitwise or              |
| `^`      | Bitwise xor             |
| `~`      | Bitwise ones compliment |
| `<<`     | Bitwise shift left      |
| `>>`     | Bitwise shift right     |

#### Assignment Operators
| Operator |       Description        |
| :------- | :----------------------- |
| `=`      | Assign equal             |
| `+=`     | Assign plus-equal        |
| `-=`     | Assign minus-equal       |
| `*=`     | Assign multiply-equal    |
| `/=`     | Assign divide-equal      |
| `%=`     | Assign modulus-equal     |
| `<<=`    | Assign shift-left-equal  |
| `>>=`    | Assign shift-right-equal |
| `&=`     | Assign and-equal         |
| `^=`     | Assign xor-equal         |
| `|=`     | Assign or-equal          |

#### Data Operators
|  Operator  |      Description      |
| :--------- | :-------------------- |
| `sizeof()` | Get the size of       |
| `[]`       | Array subscript       |
| `&`        | The address of        |
| `*`        | The value of          |
| `->`       | Structure dereference |
| `.`        | Structure reference   |


### Exercise 6: Memorizing C Syntax

#### Keywords

|  Operator  |                   Description                   |
| :--------- | :---------------------------------------------- |
| auto       | Give a local variable a local lifetime.         |
| break      | Exit out of a compound statement.               |
| case       | A branch in a switch-statement.                 |
| `char`     | Character data type.                            |
| const      | Make a variable unmodifiable.                   |
| continue   | Continue to the top of a loop.                  |
| default    | Default branch in a switch-statement.           |
| do         | Start a do-while loop.                          |
| `double`   | A double floating point data type.              |
| else       | An else branch of an if-statement.              |
| `enum`     | Define a set of int constants.                  |
| extern     | Declare an identifier is defined externally.    |
| `float`    | A floating point data type.                     |
| for        | Start a for-loop.                               |
| goto       | Jump to a label.                                |
| if         | Starts an if-statement.                         |
| `int`      | An integer data type.                           |
| `long`     | A long integer data type.                       |
| register   | Declare a variable be stored in a CPU register. |
| return     | Return from a function.                         |
| `short`    | A short integer data type.                      |
| `signed`   | A signed modifier for integer data types.       |
| sizeof     | Determine the size of data.                     |
| `static`   | Preserve variable value after its scope exits.  |
| `struct`   | Combine variables into a single record.         |
| switch     | Start a switch-statement.                       |
| typedef    | Create a new type.                              |
| `union`    | Start a union-statement.                        |
| `unsigned` | An unsigned modifier for integer data types.    |
| `void`     | Declare a data type empty.                      |
| volatile   | Declare a variable might be modified elsewhere. |
| while      | Start a while-loop.                             |

### Exercise 7: Variables and Types

### Exercise 8: If, Else-If, Else

### Exercise 9: While-Loop and Boolean Expressions

### Exercise 10: Switch Statements
- Vowel Detector

### Exercise 11: Arrays and Strings

### Exercise 12: Sizes and Arrays

### Exercise 13: For-Loops and Arrays of Strings

### Exercise 14: Writing and Using Functions

### Exercise 15: Pointers, Dreaded Pointers

- Explaining Pointers
- Practical Pointer Usage
- The Pointer Lexicon
- Pointers Are Not Arrays

### Exercise 16: Structs And Pointers To Them

### Exercise 17: Heap and Stack Memory Allocation

### Exercise 18: Pointers to Functions

### Exercise 19: Zed’s Awesome Debug Macros

### Exercise 21: Advanced Data Types & Flow Control

### Exercise 22: The Stack, Scope, and Globals

### Exercise 24: Input, Output, Files

### Exercise 25: Variable Argument Functions

### Exercise 27: Creative and Defensive Programming

### Exercise 31: Common Undefined Behavior

### Exercise 32: Double Linked Lists

### Exercise 33: Linked List Algorithms

### Exercise 34: Dynamic Array

### Exercise 35: Sorting and Searching

### Exercise 36: Safer Strings

### Exercise 37: Hashmaps

### Exercise 38: Hashmap Algorithms

### Exercise 39: String Algorithms

### Exercise 40: Binary Search Trees

### Exercise 42: Stacks and Queues

### Exercise 43: A Simple Statistics Engine
