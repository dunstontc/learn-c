# Chapter 3: Control Flow

<!-- TOC -->

- [3.1. Statements and Blocks](#31-statements-and-blocks)
- [3.2. If-Else](#32-if-else)
- [3.3. Else-If](#33-else-if)
- [3.4. Switch](#34-switch)
- [3.5. Loops – While and For](#35-loops--while-and-for)
- [3.6. Loops – Do-while](#36-loops--do-while)
- [3.7. Break and Continue](#37-break-and-continue)
- [3.8. Goto and Labels](#38-goto-and-labels)

<!-- /TOC -->

The control-flow statements of a language specify the order in which computations are performed. We have already met the most common control-flow constructions in earlier examples; here we will complete the set, and be more precise about the ones discussed before.


## 3.1. Statements and Blocks

An expressionsuch as `x = 0` or `i++` or `printf(...)` becomes a statement when it is followed by a semicolon, as in
```c
    x = 0;
    i++;
    printf("...");
```
In C, the semicolon is a statement terminator, rather than a separator as it is in languages like Pascal.

Braces `{` and `}` are used to group declarations and statements together into a *compound statement*, or *block*, so that they are syntactically equivalent to a single statement. The braces that surround the statements of a function are one obvious example; braces around multiple statements after an `if`, `else`, `while`, or `for` are another. (Variables can be declared inside any block; we will talk about this in Chapter 4.) There is no semicolon after the right brace that ends a block.


## 3.2. If-Else

The `if`-`else` statement is used to express decisions. Formally, the syntax is
```c
    if (expression_1)
        statement_1
    else
        statement_2
```
where the `else` part is optional. The expression is evaluated; if it is true (that is, if `expression_1` has a non-zero value), `statement_1` is executed. If it is false (expression is zero) and if there is an else part, `statement_2` is executed instead.

Since an `if` simply tests the numeric value of an expression, certain coding shortcuts are possible. The most obvious is writing
```c
    if (expression)
```
instead of
```c
    if (expression != 0)
```
Sometimes this is natural and clear; at other times it can be cryptic.

Because the else part of an `if`-`else` is optional, there is an ambiguity when an `else` is omitted from a nested `if` sequence. This is resolved by associating the `else` with the closest previous `else`-less `if`. For example, in
```c
    if (n > 0)
        if (a > b)
            z = a;
        else
            z = b;
```
the `else` goes with the inner `if`, as we have shown by indentation. If that isn't what you want, braces must be used to force the proper association:
```c
    if (n > 0) {
        if (a > b)
            z = a;
    }
    else
        z = b;
```
The ambiguity is especially pernicious in situations like this:
```c
    if (n >= 0)
        for (i = 0; i < n; i++)
            if (s[i] > 0) {
                printf("...");
                return i;
            }
    else        /* WRONG */
      printf("error -- n is negative\n");
```
The indentation shows unequivocally what you want, but the compiler doesn't get the message, and associates the `else` with the inner `if`. This kind of bug can be hard to find; it's a good idea to use braces when there are nested `if`s.

By the way, notice that there is a semicolon after `z = a` in
```c
    if (a > b)
        z = a;
    else
        z = b;
```
This is because grammatically, a *statement* follows the `if`, and an expression statement like `z = a;` is always terminated by a semicolon.


## 3.3. Else-If

The construction
```c
    if (expression)
        statement
    else if (expression)
        statement
    else if (expression)
        statement
    else if (expression)
        statement
    else
        statement
```
occurs so often that it is worth a brief separate discussion. This sequence of `if` statements is the most general way of writing a multi-way decision. The expressions are evaluated in order; if any *expression* is true, the *statement* associated with it is executed, and this terminates the whole chain. As always, the code for each statement is either a single statement, or a group in braces.

The last `else` part handles the "none of the above" or *default* case where none of the other conditions is satisfied. Sometimes there is no explicit action for the default; in that case the trailing
```c
    else
        statement
```
can be omitted, or it may be used for error checking to catch an "impossible" condition.

To illustrate a three-way decision, here is a binary search function that decides if a particular value `x` occurs in the sorted array `v`. The elements of `v` must be in increasing order. The function returns the position (a number between `0` and `n-1`) if `x` occurs in `v`, and `-1` if not.

Binary search first compares the input value `x` to the middle element of the array `v`. If `x` is less than the middle value, searching focuses on the lower half of the table, otherwise on the upper half. In either case, the next step is to compare `x` to the middle element of the selected half. This process of dividing the range in two continues until the value is found or the range is empty.
```c
/* binsearch: find x in v[O] <= v[1] <= ••• <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
      mid = (low + high) / 2;

      if (x < v[mid])
          high = mid - 1;
      else if (x > v[mid])
          low = mid + 1;
      else     /* found match */
          return match
    }
    return -1; /* no match */
}
```
The fundamental decision is whether `x` is less than, greater than, or equal to the middle element `v[mid]` at each step; this is a natural for `else`-`if`.

### Exercises
- **Exercise 3.1**: Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside the loop and measure the difference in run-time.


## 3.4. Switch

The `switch` statement is a multi-way decision that tests whether an expression matches one of a number of *constant* integer values, and branches accordingly.
```c
    switch (expression) {
        case const_expr: statements
        case const_expr: statements
        default: statements
    }
```
Each case is labeled by one or more integer-valued constants or constant expressions. If a case matches the expression value, execution starts at that case. All case expressions must be different. The case labeled `default` is executed if none of the other cases are satisfied. A `default` is optional;if it isn't there and if none of the cases match, no action at all takes place. Cases and the default clause can occur in any order.

In Chapter 1 we wrote a program to count the occurrences of each digit, white space, and all other characters, using a sequence of `if ... else if ... else`. Here is the same program with a `switch`:
```c
```c
#include <stdio.h>

/* count digits, whitespace, and others */
main()
{
    int c, i, nwhite, nother, ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i) 
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) 
    {
        if (c >= '0' && c <= '9') 
        {
            ++ndigit[c-'O'];
        }
        else if (c == ' ' ||  c == '\n' || c == '\t') 
        {
            ++nwhite; 
        }
        else 
        {
            ++nother;
        }
    } 

    printf("digits =");
    for (i = 0; i < 10; ++i) 
    {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
}
```
```
The break statement causes an immediate exit from the switch. Because
cases serve just as labels, after the code for one case is done, execution falls through to the next unless you take explicit action to escape. break and returnarethemostcommonwaystoleaveaswitch.Abreakstatement can also be used to force an immediate exit from while, for, and do loops,as will be discussed later in this chapter.

Falling through cases is a mixed blessing. On the positive side, it allows several cases to be attached to a single action, as with the digits in this example. But it also implies that normally each case must end with a break to prevent falling through to the next. Falling through from one case to another is not robust, being prone to disintegration when the program is modified. With the exception of multiple labels for a single computation, fall-throughs should be used sparingly, and commented.

As a matter of good form, put a `break` after the last case (the `default` here) even though it's logically unnecessary. Some day when another case gets added at the end, this bit of defensive programming will save you

### Exercises
- **Exercise 3.2**: Write a function `escape(s, t)` that converts characters like newline and tab into visible escape sequences like `\n` and `\t` as it copies the string `t` to `s`. Use a `switch`. Write a function for the other direction as well, converting escape sequences into the real characters.


## 3.5. Loops – While and For
## 3.6. Loops – Do-while
## 3.7. Break and Continue
## 3.8. Goto and Labels
