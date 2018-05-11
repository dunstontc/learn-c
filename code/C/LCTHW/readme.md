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
        - [Exercise 5: Memorizing C Operators](#exercise-5-memorizing-c-operators)
            - [Arithmetic Operators](#arithmetic-operators)
            - [Relational Operators](#relational-operators)
            - [Logical Operators](#logical-operators)
            - [Bitwise Operators](#bitwise-operators)
        - [Exercise 6: Memorizing C Syntax](#exercise-6-memorizing-c-syntax)
            - [Keywords](#keywords)

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


### Exercise 8: If, Else-If, Else
