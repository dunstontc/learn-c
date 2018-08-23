# CHAPTER 1: A Tutorial Introduction

Let us begin with a quick introduction to C. Our aim is to show the essential elements of the language in real programs, but without getting bogged down in details, rules, and exceptions. At this point, we are not trying to be complete or even precise (save that the examples are meant to be correct). We want to get you as quickly as possible to the point where you can write useful programs, and to do that we have to concentrate on the basics: variables and constants, arithmetic, control flow, functions, and the rudiments of input and output. We are intentionally leaving out of this chapter features of C that are important for writing bigger programs. These include pointers, structures, most of C's rich set of operators, several control-flow statements, and the standard library.  
This approach has its drawbacks. Most notable is that the complete story on any particular language feature is not found here, and the tutorial, by being brief, may also be misleading. And because the examples do not use the full power of C, they are not as concise and elegant as they might be. We have tried to minimize these effects, but be warned. Another drawback is that later chapters will necessarily repeat some of this chapter. We hope that the repetition will help you more than it annoys.  
In any case, experienced programmers should be able to extrapolate from the material in this chapter 'to their own programming needs. Beginners should supplement it by writing small, similar programs of their own. Both groups can use it as a framework on which to hang the more detailed descriptions that begin in Chapter 2.  


## 1.1 Getting Started
The only way to learn a new programming language is by writing programs in it. The first program to write is the same for all languages:
- Print the words *"hello, world"*

This is the big hurdle; to leap over it you have to be able to create the program text somewhere, compile it successfully, load it, run it, and find out where your output went. With these mechanical details mastered, everything else is comparatively easy.
```c
#include <stdio.h>

int main()
{
  printf("hello world\n");
}
```

Just how to run this program depends on the system you are using. As a specific example, on the UNIX operating system you must create the program in a file whose name ends in `".c"`, such as `hello.c`, then compile it with the command
```
  $ cc hello.c
```

If you haven't botched anything, such as omitting a character or misspelling something,the compilation will proceed silently, and make an executable file called `a.out.` If you run `a.out` by typing the command  
```
  $ a.out
```
it will print  
```
hello, world
```
On other systems, the rules will be different; check with a local expert.  

Now for some explanations about the program itself. A C program, whatever its size, consists of *functions* and *variables*. A function contains *statements* that specify the computing operations to be done, and *variables* store values used during the computation. C functions are like the subroutines and functions of Fortran or the procedures and functions of Pascal. Our example is a function named `main`. Normally you are at liberty to give functions whatever names you like, but `"main"` is special; your program begins executing at the beginning of `main`. This means that every program must have a `main` somewhere.
`main` will usually call other functions to help perform its job, some that you wrote, and others from libraries that are provided for you. The first line of the program,
```c
  #include <stdio.h>
```
tells the compiler to include information about the standard input/output library; this line appears at the beginning of many C source files. The standard library is described in Chapter 7 and Appendix B.

One method of communicating data between functions is for the calling function to provide a list of values, called `arguments`, to the function it calls. The parentheses after the function name surround the argument list. In this example, `main` is defined to be a function that expects no arguments, which is indicated by the empty list `()`.  

The statements of a function are enclosed in braces `{}`.The function main contains only one statement:
```c
  printf("hello world\n");
```

A function is called by naming it, followed by a parenthesized list of arguments, so this calls the function `printf` with the argument `"hello, world\n"`. `printf` is a library function that prints output, in this case the string of characters between the quotes.  
A sequence of characters in double quotes, like `"hello,world\n"`, is called a *character string* or *string constant*. For the moment our only use of character strings will be as arguments for `printf` and other functions.
The sequence `\n` in the string is C notation for the *newline character*, which when printed advances the output to the left margin on the next line. If you leave out the `\n` (a worthwhile experiment), you will find that there is no line advance after the output is printed. You must use `\n` to include a newline character in the `printf` argument; if you try something like
```c
  printf("hello, world
  ");
```
the C compiler will produce an error message.

`printf` never supplies a newline automatically, so several calls may be used to build up an output line in stages. Our first program could just as well have been written
```c
#include <stdio.h>

int main()
{
  printf("hello");
  printf("world");
  printf("\n");
}
```
to produce identical output.

Notice that \n represents only a single character. An escape sequence like
`\n` provides a general and extensible mechanism for representing hard-to-type or invisible characters. Among the others that C provides are `\t` for tab, `\b` for backspace, `\"` for the double quote, and `\\` for the backslash itself. There is a complete list in Section 2.3

### Exercises
- Exercise 1.1: Run the `"hello, world"` program on your system. Experiment with leaving out parts of the program, to see what error messages you get.
- Exercise 1.2: Experiment to find out what happens when `printf`'s argument string contains `\c`, where *c* is some character not listed above


## 1.2 Variables and Arithmetic Expressions
The next program uses the formula `C - (519)(0 F-32)` to print the following table of Fahrenheit temperatures and their centigrade or Celsius equivalents:
```
0	-17
20	-6
40	4
60	15
80	26
100	37
120	48
140	60
160	71
180	82
200	93
220	104
240	115
260	126
280	137
300	148
```

The program itself still consists of the definition of a single function named main. It is longer than the one that printed `"hello, world"`, but not complicated. It introduces several new ideas, including comments, declarations, variables, arithmetic expressions, loops, and formatted output.
```C
#include <stdio.h>

// print Fahrenheit-Celsius table for farh = 0, 20, ..., 300
int main()
{
    int fahrenheit, celsius;
    int lower, upper, step;

    lower = 0;   // lower limit of temperature table
    upper = 300; // upper limit
    step = 20;   // step size

    fahrenheit = lower;

    while(fahrenheit <= upper) {
        celsius = (5 * (fahrenheit-32) / 9);
        printf("%d\t%d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}
```
The two lines
```c
  /* print Fahrenheit-Celsius table
     for fahr = 0, 20, ..., 300 */
```
are a *comment*, which in this case explains briefly what the program does. Any characters between `/*` and `*/` are ignored by the compiler; they may be used freely to make a program easier to understand. Comments may appear anywhere a blank or tab or newline can.

In C, all variables must be declared before they are used, usually at the beginning of the function before any executable statements. A *declaration* announces the properties of variables; it consists of a type name and a list of variables, such as
```c
  int fahrenheit, celsius;
  int lower, upper, step;
```
The type `int` means that the variables listed are integers, by contrast with `float`, which means floating point, i.e., numbers that may have a fractional part. The range of both `int` and `float` depends on the machine you are using; 16-bit `int`s, which lie between -32768 and +32767, are common, as are 32-bit `int`s. A `float` number is typically a 32-bit quantity, with at least six significant digits and magnitude generally between about $10^{-38}$ and $10^{+38}$.  
C provides several other basic data types besides `int` and `float`, including:  

|   type   |           description           |
| -------- | ------------------------------- |
| `char`   | character; a single byte        |
| `short`  | short integer                   |
| `long`   | long integer                    |
| `double` | double-precision floating point |

The sizes of these objects are also machine-dependent. There are also *arrays*, *structures* and *unions* of these basic types, *pointers* to them, and *functions* that return them, all of which we will meet in due course.  
Computation in the temperature conversion program begins with the assignment statements:
```c
  lower = 0;   // lower limit of temperature table
  upper = 300; // upper limit
  step = 20;   // step size

  fahrenheit = lower;
```

which set the variables to their initial values. Individual statements are terminated by semicolons.
Each line of the table is computed the same way, so we use a loop that repeats once per output line; this is the purpose of the `while` loop
```c
  while(fahrenheit <= upper) {
    // ...
  }
```

The `while` loop operates as follows: The condition in parentheses is tested. If it is true (`fahr` is less than or equal to `upper`), the body of the loop (the three statements enclosed in braces) is executed. Then the condition is re-tested, and if true, the body is executed again. When the test becomes false (`fahr` exceeds `upper`) the loop ends, and execution continues at the statement that follows the loop. There are no further statements in this program, so it terminates.  
The body of a `while` can be one or more statements enclosed in braces, as in the temperature converter, or a single statement without braces, as in
```c
  while(i < j)
    i = 2 * i;
```
In either case, we will always indent the statements controlled by the `while` by one tab stop (which we have shown as four spaces) so you can see at a glance which statements are inside the loop. The indentation emphasizes the logical structure of the program. Although C compilers do not care about how a program looks, proper indentation and spacing are critical in making programs easy for people to read. We recommend writing only one statement per line, and using blanks around operators to clarify grouping. The position of braces is less important, although people hold passionate beliefs. We have chosen one of several popular styles. Pick a style that suits you, then use it consistently.  
Most of the work gets done in the body of the loop. The Celsius temperature is computed and assigned to the variable `celsius` by the statement  
```c
  celsius = 5 * (fahrenheit-32) / 9;
```
The reason for multiplying by `5` and then dividing by `9` instead of just multiplying by `5/9` is that in C, as in many other languages, integer division *truncates*: any fractional part is discarded. Since `5` and `9` are integers, `5/9` would be truncated to zero and so all the Celsius temperatures would be reported as zero.  
This example also shows a bit more of how `printf` works. `printf` is a general-purpose output formatting function, which we will describe in detail in Chapter 7. Its first argument is a string of characters to be printed, with each `%` indicating where one of the other (second, third, ...) arguments is to be substituted, and in what form it is to be printed. For instance, `%d` specifies an integer argument, so the statement
```c
  printf("%d\t%d\n", fahrenheit, celsius);
```
causes the values of the two integers `fahrenheit` and `celsius` to be printed, with a tab (`\t`) betweenthem.  
Each `%` construction in the first argument of `printf` is paired with the corresponding second argument, third argument, etc.; they must match up properly by number and type, or you'll get wrong answers.   
By the way, `printf` is not part of the C language; there is no input or output defined in C itself. `printf` is just a useful function from the.standard library of functions that are normally accessible to C programs. The behavior ofprintf isdefinedintheANSIstandard,however,soitspropertiesshouldbe the same with any compiler and library that conforms to the standard.   






---
```C
#include <stdio.h>

// print Fahrenheit-Celsius table for farh = 0, 20, ..., 300
int main()
{
    float fahrenheit, celsius;
    int start_num, end_num, current_step;

    start_num = 0;     // lower limit of temperature table
    end_num = 300;     // upper limit
    current_step = 20; // step size

    fahrenheit = start_num;

    while(fahrenheit <= end_num) {
        celsius = (5.0/9.0) * (fahrenheit-32.0);
        // printf("%d\t%d\n", fahrenheit, celsius);
        printf("%3.0f\t%6.1f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + current_step;
    }
}
```

Width and precision may be omitted from a specification: `%6f` says that the number is to be at least six characters wide; `%.2f` specifies two characters after the decimal point, but the width is not constrained; and `%f` merely says to print the number as floating point.

| input |                              output                              |
| ----- | ---------------------------------------------------------------- |
| %d    | print as decimal integer                                         |
| %6d   | print as decimal integer, at least 6 characters wide             |
| %f    | print as floating point                                          |
| %6f   | print as floating point, at least 6 characters wide              |
| %.2f  | print as floating point, 2characters after decimal point         |
| %6.2f | print as floating point, at least 6wide and 2after decimal point |

Among others, `printf` also recognizes `%0` for octal, `%x` for hexadecimal, `%c`  for character, `%s` for character string, and `%%` for `%` itself.


### Exercises
- Exercise 1.3: Modify the temperature conversion program to print a heading above the table.
- Exercise 1.4: Write a program to print the corresponding Celsius to Fahrenheit table.


## 1.3 The For Statement

