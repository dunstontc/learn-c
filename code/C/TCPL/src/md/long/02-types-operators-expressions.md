# Chapter 2: Types, Operators, and Expressions

Variables and constants are the basic data objects manipulated in a program. Declarations list the variables to be used, and state what type they have and perhaps what their initial values are. Operators specify what is to be done to them. Expressions combine variables and constants to produce new values. The type of an object determines the set of values it can have and what operations can be performed on it. These building blocks are the topics of this chapter.  

The ANSI standard has made many small changes and additions to basic types and expressions. There are now `signed` and `unsigned` forms of all integer types, and notations for unsigned constants and hexadecimal character constants. Floating-point operations may be done in single precision;.there is also a `long double` type for extended precision. String constants may be concatenated at compile time. Enumerations have become part of the language, formalizing a feature of long standing. Objects may be declared `const`, which prevents them from being changed. The rules for automatic coercions among arithmetic types have been augmented to handle the richer set of types.


## 2.1. Variable Names

Although we didn't say so in Chapter 1, there are some restrictions on the names of variables and symbolic constants. Names are made up of letters and digits; the first character must be a letter. The underscore `"_"` counts as a letter; it is sometimes useful for improving the readability of long variable names. Don't begin variable names with underscore, however,since library routines often use such names. Upper case and lower case letters are distinct, so `x` and `X` are two different names. Traditional C practice is to use lower case for variable names, and all upper case for symbolic constants.

At least the first 31 characters of an internal name are significant. For function names and external variables, the number may be less than 31, because external names may be used by assemblers and loaders over which the language has no control. For external names, the standard guarantees uniqueness only for 6 characters and a single case. Keywords like `if`, `else`, `int`, `float`, etc., are reserved; you can't use them as variable names. They must be in lower case.

It's wise to choose variable names that are related to the purpose of the variable, and that are unlikely to get mixed up typographically. We tend to use short' names for local variables, especially loop indices, and longer names for external variables.


## 2.2. Data Types and Sizes

There are only a few basic data types in C:

|          |                                                                                     |
| -------- | ----------------------------------------------------------------------------------- |
| `char`   | a single byte, capable of holding one character in the local character set          |
| `int`    | an integet, typicalllly reflecting the natural size of integers on the host machine |
| `float`  | single-precision floating point                                                     |
| `double` | double-precision floating point                                                     |

In addition, there are a number of qualifiers that can be applied to these basic types. `short` and `long` apply to integers:
```c
    short int sh;
    long int counter;
```
The word `int` can be omitted in such declarations, and typically is.

The intent is that `short` and `long` should provide different lengths of integers where practical; `int` will normally be the natural size for a particular machine. `short` is often 16 bits, `long` 32 bits, and `int` either 16 or 32 bits. Each compiler is free to choose appropriate sizes for its own hardware, subject
only to the restriction that `short`s and `int`s are at least 16 bits, `long`s are at least 32 bits, and `short` is no longer than `int`, which is no longer than `long`.

The qualifier `signed` or `unsigned` may be applied to `char` or any integer. `unsigned` numbers are always positive or zero, and obey the laws of arithmetic modulo $2^n$, where $n$ is the number of bits in the type. So, for instance, if `char`s are 8 bits, unsigned `char` variables have values between 0 and 255, while signed `chars` have values between `-128` and `127` (in a two's complement machine). Whether plain `char`s are signed or unsigned is machine-dependent, but printable characters are always positive.

The type `long double` specifies extended-precision floating point. As with integers, the sizes of floating-point objects are implementation-defined; `float`, `double` and `long double` could represent one, two or three distinct sizes.

The standard headers `<limits.h>` and `<float.h>` contain symbolic constants for all of these sizes, along with other properties of the machine and compiler. These are discussed in Appendix B.

### Exercises 
- **Exercise 2.1**: Write a program to determine the ranges of `char`, `short`, `int`, and `long` variables, both `signed` and `unsigned`, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.


## 2.3. Constants

An integer constant like `1234` is an `int`. A `long` constant is written with a terminal `l` (ell) or `L`, as in `123456789L`; an integer too big to fit into an `int` will also be taken as a `long`. Unsigned constants are written with a terminal `u` or `U`, and the suffix `ul` or `UL` indicates `unsigned long`.

Floating-point constants contain a decimal point (`123.4`) or an exponent (`1e-2`) or both; their type is `double`, unless suffixed. The suffixes `f` or `F` indicate a `float` constant; `l` or `L` indicate a `long double`.

The value of an integer can be specified in octal or hexadecimal instead of decimal. A leading `0` (zero) on an integer constant means octal; a leading `Ox` or `ox` means hexadecimal. For example, decimal `31` can be written as `037` in octal and `Ox1f` or `OX1Fin` hex. Octal and hexadecimal constants may also be followed by `L` to make them `long` and `U` to make them `unsigned`: `OXFUL` is an `unsigned long` constant with value `15` decimal.

A *character constant* is an integer, written as one character within single quotes, such as `'x'`. The value of a character constant is the numeric value of the character in the machine's character set. For example, in the ASCII character set the character constant `'0'` has the value `48,` which is unrelated to the numeric value `0`. If we write `'0'` instead of a numeric value like `48` that depends on character set, the program is independent of the particular value and easier to read. Character constants participate in numeric operations just as any other integers, although they are most often used in comparisons with other characters.

Certain characters can be represented in character and string constants by *escape sequences* like `\n` (newline); these sequences look like two characters, but represent only one. In addition, an arbitrary byte-sized bit pattern can be specified by
```c
    '\000'
```
where *000* is one to three octal digits (0...7) or by
```c
    '\xhh'
```
where *hh* is one or more hexadecimal digits (0...9, a...f, A...F).  So we might write
```c
#define VTAB '\013' /* ASCII vertical tab */ 
#define BELL '\007' /* ASCII bell character */
```
or, in hexadecimal,
```c
#define VTAB '\xb' /* ASCII vertical tab */ 
#define BELL '\x7' /* ASCII bell character */
```
The complete set of escape sequences is

| escape sequence |         output         |
| --------------- | ---------------------- |
| `\a`            | alert (bell) character |
| `\b`            | backspace              |
| `\f`            | formfeed               |
| `\n`            | newline                |
| `\r`            | carriage return        |
| `\t`            | horizontal tab         |
| `\v`            | vertical tab           |
| `\\`            | backslash              |
| `\?`            | question mark          |
| `\'`            | single quote           |
| `\"`            | double quote           |
| `\000`          | octal number           |
| `\xhh`          | hexadecimal number     |

The character constant `'\0'` represents the character with value zero, the *null character*. `'\0'` is often written instead of `0` to emphasize the character nature of some expression, but the numeric value is just `0`.

A *constant expression* is an expression that involves only constants. Such expressions may be evaluated during compilation rather than run-time, and accordingly may be used in any place that a constant can occur, as in
```c
    "I am a string"
```
or
```c
    "" // the empty string
```

The quotes are not part of the string, but serve only to delimit it. The same escape sequences used in character constants apply in strings; `\"` represents the double-quote character. String constants can be concatenated at compile time:
```c
    "hello," " world"
```
is equivalent to
```c
    "hello, world"
```
This is useful for splitting long strings across several source lines.

Technically, a string constant is an array of characters. The internal representation of a string has a null character `'\0'` at the end, so the physical storage required is one more than the number of characters written between the quotes. This representation means that there is no limit to how long a string can be, but programs must scan a string completely to determine its length.
The standard library function `strlen(s)` returns the length of its character string argument `s`, excluding the terminal `'\0'`. Here is our version:
```c
/* strlen: return length of s */
int strlen(char s[])
{
    int i;

    i = 0;
    while(s[i] != '\0')
        ++i; 
    return i;
}
```
`strlen` and other string functions are declared in the standard header `<string.h>`.

Be careful to distinguish between a character constant and a string that contains a single character: `'x'` is not the same as `"x"`. The former is an integer, used to produce the numeric value of the letter *x* in the machine's character set. The latter is an array of characters that contains one character (the letter *x*) and a `'\0'`.

There is one other kind of constant, the *enumeration constant*. An enumeration is a list of constant integer values, as in
```c
    enum boolean { NO, YES };
```
The first name in an `enum` has value `0`, the next `1`, and so on, unless explicit values are specified. If not all values are specified, unspecified values continue the progression from the last specified value, as in the second of these examples:
```c
    enum escapes { 
        BELL = '\a',
        BACKSPACE = '\b',
        TAB = '\t',
        NEWLINE = '\n',
        VTAB = '\v',
        RETURN = '\r'
    };

    enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
    /* FEB is 2, MAR is 3, etc. */
```
Names in different enumerations must be distinct. Values need not be distinct in the same enumeration.

Enumerations provide a convenient way to associate constant values with names, an alternative to `#define` with the advantage that the values can be generated for you. Although variables of `enum` types may be declared, compilers need not check that what you store in such a variable is a valid value for the enumeration. Nevertheless, enumeration variables offer the chance of checking and so are often better than `#defines`. In addition, a debugger may be able to print values of enumeration variables in their symbolic form.


## 2.4. Declarations

All variables must be declared before use, although certain declarations can be made implicitly by context. A declaration specifies a type, and contains a list of one or more variables of that type, as in
```c
    int lower, upper, step; 
    char c, line[1000];
```
Variables can be distributed among declarations in any fashion; the lists above could equally well be written as
```c
    int lower;
    int upper;
    int step;
    char c;
    char line[1000];
```
This latter form takes more space, but is convenient for adding a comment to each declaration or for subsequent modifications.

A variable may also be in itialized in its declaration. If the name is followed by an equals sign and an expression, the expression serves as an initializer, as in
```c
    char esc = '\\';
    int i = 0;
    int limit = MAXLINE+1; 
    float eps = 1.0e-5;
```
If the variable in question is not automatic, the initialization is done once only, conceptually before the program starts executing, and the initializer must be a constant expression. An explicitly initialized automatic variable is initialized each time the function or block it is in is entered; the initializer may be any expression. External and static variables are initialized to zero by default. Automatic variables for which there is no explicit initializer have undefined (i.e., garbage) values.

The qualifier `const` can be applied to the declaration of any variable to specify that its value will not be changed. For an array, the `const` qualifier says that the elements will not be altered.
```c
    const double e = 2.71828182845905; 
    const char msg[] = "warning: ";
```
The `const` declaration can also be used with array arguments, to indicate that the function does not change that array:
```c
    int strlen(const char[]);
```
The result is implementation-defined if an attempt is made to change a `const`.


## 2.5. Arithmetic Operators

The binary arithmetic operators are `+`, `-`, `*`, `/`, and the modulus operator `%`. Integer division truncates any fractional part. The expression
```c
    x % y
```
produces the remainder when `x` is divided by `y`, and thus is zero when `y` divides `x` exactly. For example, a year is a leap year if it is divisible by 4 but not by 100, except that years divisible by 400 *are* leap years. Therefore
```c
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) 
        printf("%d is a leap year\n", year);
    else 
        printf("%d is not a leap year\n", year);
```

The `%` operator cannot be applied to `float` or `double`. The direction of truncation for `/` and the sign of the result for `%` are machine-dependent for negative operands, as is the action taken on overflow or underflow.

The binary `+` and `-` operators have the same precedence, which is lower than the precedence of `*`, `/`, and `%`, which is in turn lower than unary `+` and `-`. Arithmetic operators associate left to right.

Table 2-1 at the end of this chapter summarizes precedence and associativity for all operators.
 

## 2.6. Relational and Logical Operators

The relational operators are:
- `>`
- `>=`
- `<`
- `<=`

They all have the same precedence. Just below them in precedence are the equality operators:
- `==`
- `!=`

Relational operators have lower precedence than arithmetic operators, so an expression like `i < lim-1` is taken as `i < (lim-1)`, as would be expected.

More interesting are the logical operators `&&`, and `||`. Expressions connected by `&&` or `||` are evaluated left to right, and evaluation stops as soon as the truth or falsehood of the result is known. Most C programs rely on these properties. For example, here is a loop from the input function `getline` that we wrote in Chapter 1:
```c
    for (i = 0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
```
Before reading a new character it is necessary to check that there is room to store it in the arrays,so the test `i < lim-1` *must* be made first. Moreover, if this test fails, we must not go on and read another character.

Similarly, it would be unfortunate if `c` were tested against `EOF` before `getchar` is called; therefore the call and assignment must occur before the character in `c` is tested.

The precedence of `&&` is higher than that of `||`, and both are lower than relational and equality operators, so expressions like
```c
    i<lim-1 && (c = getchar()) != '\n' && c != EOF
```
need no extra parentheses. But since the precedence of `!=` is higher than assignment, parentheses are needed in
```c
    (c = getchar()) != '\n'
```
to achieve the desired result of assignment to `c` and then comparison with `'\n'`.

By definition, the numeric value of a relational or logical expression is 1 if the relation is true, and 0 if the relation is false.

The unary negation operator `!` converts a non-zero operand into 0, and a zero operand into 1. A common use of `!` is in constructions like
```c
    if (!valid)
```
rather than
```c
    if (valid == 0)
```
It's hard to generalize about which form is better. Constructions like `!valid` read nicely ("if not valid"), but more complicated ones can be hard to understand.

### Exercises
- **Exercise 2.2**: Write a loop equivalent to the `for` loop above without using `||` or `||`.


## 2.7. Type Conversions

When an operator has operands of different types, they are converted to a common type according to a small number of rules. In general, the only automatic conversions are those that convert a *"narrower"* operand into a *"wider"* one without losing information, such as converting an integer to floating point in an expression like `f + i`. Expressions that don't make sense, like using a `float` as a subscript, are disallowed. Expressions that might lose information, like assigning a longer integer type to a shorter, or a floating-point type to an integer, may draw a warning, but they are not illegal.

A `char` is just a small integer, so chars may be freely used in arithmetic expressions. This permits considerable flexibility in certain kinds of character transformations. One is exemplified by this naive implementation of the function `atoi`, which converts a string of digits into its numeric equivalent.
```c
/* atoi: convertstointeger */
int atoi(char s[])
{
    int i, n;
    n = 0;

    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0'); 
    return n;
}
```
As we discussed in Chapter 1, the expression
```c
    s[i] - '0'
```
gives the numeric value of the character stored in `s[i]`, because the values of `'0'`, `'1'`, etc., form a contiguous increasing sequence.

Another example of `char` to `int` conversion is the function `lower`, which maps a single character to lower case for *the ASCII character set*. If the character is not an upper case letter, `lower` returns it unchanged.
```c
/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
```
This works for ASCII because corresponding upper case and lower case letters are a fixed distance apart as numeric values and each alphabet is contiguous; there is nothing but letters between A and Z. This latter observation is not true of the EBCDIC character set, however, so this code would convert more than just letters in EBCDIC.

The standard header `<ctype.h>`, described in Appendix B, defines a family
of functions that provide tests and conversions that are independent of character set. For example, the function `tolower(c)` returns the lower case value of `c` if `c` is upper case, so `tolower` is a portable replacement for the function `lower` shown above. Similarly, the test
```c
      if (c >= '0' && c <= '9')
```
can be replaced by
```c
    isdigit(c)
```
We will use the `<ctype.h>` functions from now on.

There is one subtle point about the conversionof characters to integers. The
language does not specify whether variables of type char are signed or unsigned quantities. When a char is converted to an int, can it ever produce a negative integer? The answer varies from machine to machine, reflecting differences in architecture. On some machines a char whose leftmost bit is 1 will be converted to a negative integer ("sign extension"). On others, a char is promoted to an int by adding zeros at the left end, and thus is always positive.

The definition of C guarantees that any character in the machine's standard printing character set will never be negative, so these characters will always be positive quantities in expressions. But arbitrary bit patterns stored in 'character variables may appear to be negative on some machines, yet positive on others. For portability, specify signed or unsigned if non-character data is to be stored in char variables.

Relational expressions like `i > j` and logical expressions connected by `&&` and `||` are defined to have value `1` if true, and `0` if false. Thus the assignment
```c
    d = c >= '0' && c <= '9'
```
sets `d` to `1` if `c` is a digit, and `0` if not. However, functions like `isdigit` may return any non-zero value for true. In the test part of `if`, `while`, `for`, etc., *"true"* just means *"non-zero"*, so this makes no difference.

Implicit arithmetic conversions work much as expected. In general, if an operator like `+` or `*` that takes two operands (a binary operator) has operands of different types, the "lower" type is *promoted* to the "higher" type before the operation proceeds. The result is of the higher type. Section 6 of Appendix A states the conversion rules precisely. If there are no unsigned operands, however, the following informal set of rules will suffice:
- If either operand is `long double`, convert the other to `long double`. 
- Otherwise, if either operand is `double`, convert the other to `double`. 
- Otherwise, if either operand is `float`, convert the other to `float`. 
- Otherwise, convert `char` and `short` to `int`.
- Then, if either operand is `long`, convert the other to `long`.

Notice that `float`s in an expression are not automatically converted to `double`; this is a change from the original definition. In general, mathematical functions like those in `<math.h>` will use double precision. The main reason for using `float` is to save storage in large arrays, or, less often, to save time on machines where double-precision arithmetic is particularly expensive.

Conversion rules are more complicated when uns igned operands are involved. The problem is that comparisons between signed and unsigned values are "machine-dependent" because they depend on the sizes of the various integer types. For example, suppose that int is 16 bits and long is 32 bits. Then `-1L < 1U`, because `1U`, which is an `int`, is promoted to a `signed long`. But `-1L > 1UL`, because `-1L` is promoted to `unsigned long` and thus appears to be a large positive number.

Conversions take place across assignments; the value of the right side is converted to the type of the left, which is the type of the result. 
A character is converted to an integer, either by sign extension or not, as described above.

Longer integers are converted to shorter ones or to `chars` excess high-order bits. Thus in
```c
    int i; 
    char c;

    i = c; 
    c = i;
```
the value of `c` is unchanged. This is true whether or not sign extension is involved. Reversing the order of assignments might lose information, however.

If `x` is `float` and `i` is `int`, then `x = i` and `i = x` both causeconversions; `float` to `int` causes truncation of any fractional part. When `double` is converted to `float`, whether the value is rounded or truncated is implementation-dependent.

Since an argument of a function call is an expression, type conversions also take place when arguments are passed to functions. In the absence of a function prototype, `char` and `short` become `int`, and `float` becomes `double`. This is why we have declared function arguments to be `int` and `double` even when the function is called with `char` and `float`.

Finally, explicit type conversions can be forced (*coerced*) in any expression, with a unary operator called a *cast*. In the construction:
```c
    (type) expression
```
the *expression* is converted to the named type by the conversion rules above. The precise meaning of a cast is as if the *expression* were assigned to a variable of the specified type, which is then used in place of the whole construction. For example, the library routine `sqrt` expects a `double` argument, and will produce nonsense if inadvertently handed something else. (`sqrt` is declared in `<math•h>`). So if `n` is an integer, we can use
```c
    sqrt((double) n)
```
to convert the value of `n` to `double` before passing it to `sqrt`. Note that the cast produces the *value* of `n` in the proper type; `n` itself is not altered. The cast operator has the same high precedence as other unary operators, as summarized in the table at the end of this chapter.

If arguments are declared by a function prototype, as they normally should be, the declaration causes automatic coercion of any arguments when the function is called. Thus, given a function prototype for sqrt:
```c
    double sqrt(2);
```
the call
```c
    root2 = sqrt(2);
```
coerces the integer `2` into the `double` value `2.0` without any need for a cast.

The standard library includes a portable implementation of a pseudo-random number generator and a function for initializing the seed; the former illustrates a cast:
```c
unsigned long int next = 1

/* rand: return pseudo-random integer on 0..3276 */
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed)
{
    next = seed;
}
```

### Exercises
- **Exercise 2.3**: Write the function `htoi(s)`, which converts a string of hexadecimal digits (including an optional `Ox` or `ox`) into its equivalent integer value. The allowable digits are `0` through `9`, `a` through `f`, and `A` through `F`.


## 2.8. Increment and Decrement Operators

C provides two unusual operators for incrementing and decrementing variables. The *increment* operator `++` adds 1 to its operand, while the *decrement* operator `--` subtracts 1. We have frequently used `++` to increment variables, as in
```c
    if (c == '\n')
```

The unusual aspect is that `++` and `--` may be used either as prefix operators (before the variable, as in `++n`), or postfix (after the variable: `n++`). In both cases, the effect is to increment `n`. But the expression `++n` increments `n` *before* its value is used, while `n++` increments `n` *after* its value has been used. This means that in a context where the value is being used, not just the effect, `++n` and `n++` are different. If `n` is `5`, then
```c
    x = n++;
```
sets `x` to `5`, but
```c
    x = ++n;
```
sets `x` to `6`. In both cases, `n` becomes `6`. The increment and decrement operators can only be applied to variables; an expression like `(i+j)++` is illegal.

In a context where no value is wanted, just the incrementing effect, as in
```c
    if (c == '\n')
        nl++;
```
prefix and postfix are the same. But there are situations where one or the other is specifically called for. For instance, consider the function `squeeze(S, C)`, which removes all occurrences of the character `c` from the string `s`.
```c
/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] 1 = '\0'; i++) 
        if (s[i] 1 = c)
            s[j++] = s[i]; 
    s[j] = '\0';
}
```
Each time a non-`c` occurs, it is copied into the current `j` position, and only then is `j` incremented to be ready for the next character. This is exactly equivalent to
```c
    if (s[i] 1 = c) { 
        s[j] = s[i];
        j++;
    }
```

Another example of a similar construction comes from the `getine` function that we wrote in Chapter 1, where we can replace
```c
    if (c == '\n') { 
        s[i] = c;
        ++i;
    }
```
with the more compact
```c
    if (c == '\n')  
        s[i++] = c;
```

As a third example, consider the standard function `strcat(s, t)`, which concatenates the string `t` to the end of the string `s`. `strcat` assumes that there is enough space in `s` to hold the combination. As we have written it, `strcat` returns no value; the standard library version returns a pointer to the resulting string.
```c
/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] 1= '\0') /* find end of s */
        i++;
    while ((s[i++] = t[j++]) 1= '\0') /* copy t */
        ;
}
```
As each character is copied from `t` to `s`, the postfix `++` is applied to both `i` and `j` to make sure that they are in position for the next pass through the loop.

### Exercises
- **Exercise 2.4**: Write an alternate version of `squeeze(s1, s2)` that deletes each character in `s1` that matches any character in the string `s2`.
- **Exercise 2.5**: Write the function `any(s1, s2)`, which returns the first location in the string `s1` where any character from the string `s2` occurs, or `-1` if `s1` contains no characters from `s2`. (The standard library function `strpbrk` does the same job but returns a pointer to the location).



## 2.9. Bitwise Operators
## 2.10. Assignment Operators and Expressions
## 2.11. Conditional Expressions


## 2.12. Precedence and Order of Evaluation

Table 2-1 summarizes the rules for precedence and associativity of all operators, including those that we have not yet discussed. Operators on the same line have the same precedence; rows are in order of decreasing precedence, so, for example, `*`, `|`, and `%` all have the same precedence, which is higher than that of binary `+` and `-.` The "operator" `()` refers to function call. The operators `->` and `.` are used to access members of structures; they will be covered in Chapter 6, along with `sizeof` (size of an object). Chapter 5 discusses `*` (indirection through a pointer) and `&`. (address of an object), and Chapter 3 discusses the comma operator.

Note that the precedence of the bitwise operators `&`, `^`, and `|` falls below `==` and `!=`. This implies that bit-testing expressions like
```c
    if ((x & MASK) == 0) ...
```
must be fully parenthesized to give proper results.

C, like most languages, does not specify the order in which the operands of an operator are evaluated. (The exceptions are `&&`, `||`, `?:`,and `,`.) For example, in a statement like
```c
    x = f() + g();
```
`f` may be evaluated before `g` or vice versa; thus if either `f` or `g` alters a variable on which the other depends, `x` can depend on the order of evaluation. Intermediate results can be stored in temporary variables to ensure a particular sequence.

Similarly, the order in which function arguments are evaluated is not specified, so the statement
```c
    printf ("%d %d\n", ++n, power(2, n)); /* WRONG */
```
can produce different results with different compilers, depending on whether `n`
is incremented before `power` is called. The solution, of course, is to write
```c
    ++n;
    printf( "%d %d\n", n, power(2, n));
```

Function calls, nested assignment statements, and increment and decrement operators cause *"side effects"*; some variable is changed as a by-product of the evaluation of an expression. In any expression involving side effects, there can be subtle dependencies on the order in which variables taking part in the expression are updated. One unhappy situation is typified by the statement  
```c
    a[i] = i++;
```
The question is whether the subscript is the old value of `i` or the new.  

Compilers can interpret this in different ways, and generate different answers depending on their interpretation. The standard intentionally leaves most such matters unspecified. When side effects (assignment to variables) take place within an expression is left to the discretion of the compiler, since the best order depends strongly on machine architecture. (The standard does specify that all side effects on arguments take. effect before a function is called, but that would not help in the call to `printf` above.)  

The moral is that writing code that depends on order of evaluation is a bad programming practice in any language. Naturally, it is necessary to know what things to avoid, but if you don't know *how* they are done on various machines, you won't be tempted to take advantage of a particular implementation.  

|                        Operators                        | Associativity |
| ------------------------------------------------------- | ------------- |
| `()` `[]` `->` `.`                                      | left to right |
| `!` `~` `++` `--` `+` `-` `*` `&` `(type)` `sizeof`     | right to left |
| `*` `/` `%`                                             | left to right |
| `+` `-`                                                 | left to right |
| `<<` `>>`                                               | left to right |
| `<` `<=` `>` `>=`                                       | left to right |
| `==` `!=`                                               | left to right |
| `&`                                                     | left to right |
| `^`                                                     | left to right |
| `|`                                                     | left to right |
| `&&`                                                    | left to right |
| `\|\|`                                                  | left to right |
| `?:`                                                    | right to left |
| `=` `+=` `-=` `*=` `/=` `%=` `&=` `^=` `|=` `<<=` `>>=` | right to left |
| `,`                                                     | left to right |

