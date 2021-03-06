## Exercise 4.1

> What is the value returned by 5 + 10 * 20 / 2

105

## Exercise 4.2

> Using Table 4.12 (p.166), parenthesize the following expressions to indicate the order in which the operands are grouped:

(a)
```cpp
* (vec.begin())
```

(b)
```cpp
(* (vec.begin())) + 1
```

## Exercise 4.3

> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

No.

## Exercise 4.4

> Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its results.
> `12 / 3 * 4 + 5 * 15 + 24 % 4 / 2`

`((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2)`

result is 16+75+0 = 91

## Exercise 4.5

> Determine the result of the following expressions.

(a) ` -30 * 3 + 21 / 5 `

-90+4 = -86

(b) ` -30 + 3 * 21 / 5 `

-30 + 63 / 5 = -18

(c) ` 30 / 3 * 21 % 5 `

0

(d) ` -30 / 3 * 21 % 4 `

-2

## Exercise 4.6

> Write an expression to determine whether an `int` value is even or odd.

`i % 2` for i >= 0

`i & 0x1` or `i & 1` for all `int`

## Exercise 4.7

> What does overflow mean? Show three expressions that will overflow.

Overflow happens when a value is computed that is outside the range of values that the type can represent.

```cpp
short sv = 32767;
sv += 1;

unsigned uv = 0;
uv -= 1;

unsigned short usv = 65535;
usv += 1;
```

## Exercise 4.8

> Explain when operands are evaluated in the logical _AND_, logical _OR_, and equality operators.

- `&&` and `||` always evaluate their left operand before the right.
- The right side of an `&&` is evaluated _if and only if_ the left side is __true__.
- The right side of an `||` is evaluated _if and only if_ the left side is __false__.
- `==` always evaluate both side

## Exercise 4.9

> Explain the behavior of the condition in the following if:
```cpp
const char *cp = "Hello World";
if (cp && *cp) 
```

check the pointer cp and the string cp points to are both not 0. True.

## Exercise 4.10

> Write the condition for a while loop that would read ints from the standard input and stop when the value read is equal to 42.

```cpp
int i;
while (std::cin >> i && i != 42)
```

## Exercise 4.11

> Write an expression that tests four values, a, b, c, and d, and ensures that a is greater than b, which is greater than c, which is greater than d.

```cpp
if (a > b && b > c && c > d)
```

## Exercise 4.12

> Assuming i, j, and k are all ints, explain what i != j < k means.

~~first check if `i` equals `j`, get `0` or `1`, the compare with `k`~~

`i != j < k` equals `i != (j < k)`

## Exercise 4.13

> What are the values of `i` and `d` after each assignment?
> `int i; double d;`

(a) `d = i = 3.5;`

d = 3.0, i = 3

(b) `i = d = 3.5;`

i = 3, d = 3.5

## Exercise 4.14

> Explain what happens in each of the if tests:

```cpp
if (42 = i)   // error: literal is rvalue
if (i = 42)   // true.
```

## Exercise 4.15

> The following assignment is illegal. Why? How would you correct it?
```cpp
double dval; int ival; int *pi;
dval = ival = pi = 0;
```

pointer to int and int are not convertable.

```cpp
dval = ival = 0;
pi = 0;
```

## Exercise 4.16

> Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.
```cpp
if (p = getPtr() != 0)
if (i = 1024)
```

First one, `=` has low precedence, should be `if ((p = getPtr()) != 0)`

Second one, should be `if (i == 1024)`

## Exercise 4.17

> Explain the difference between prefix and postfix increment.

The prefix operators return the object itself as an lvalue.
The postfix operators return a copy of the object's original value as an rvalue.

## Exercise 4.18

> What would happen if the `whlie` loop on page 148 that prints the elements from a `vector` used the prefix increment operator?

~~`*++pbeg` return the pbeg advanced pointed value~~

It will print elements starting from second, at last print the dereference `v.end()`, which is undefined.

## Exercise 4.19

> Given that ptr points to an int, that vec is a vector, and that ival is an int, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?

```cpp
ptr != 0 && *ptr++; // check ptr is not a nullptr, then check ptr original value and advance ptr

ival++ && ival; // check ival and ival + 1 whether equal zero

vec[ival++] <= vec[ival]; // error. undefine behavior.
```
See also [order of evaluation](http://en.cppreference.com/w/cpp/language/eval_order)

## Exercise 4.20

> Assuming that `iter` is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.

```cpp
*iter++; // legal, return *iter, then advance iter
(*iter)++; // illegal, *iter is string
*iter.empty(); // illegal, iter is pointer which does not apply empty(), should be iter->empty()
iter->empty(); // legal, check *iter is empty or not
++*iter; // illegal, *iter is string
iter++->empty(); // legal, check original *iter is empty or not
```

## Exercise 4.21

> Write a program to use a conditional operator to find the elements in a `vector<int>` that have odd value and double the value of each such element.

[code](ex4_21.cpp)

## Exercise 4.22

> Extend the program that assigned high pass, pass and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more `if` statements. Which version do you think is easier to understand and why?

[code](ex4_22.cpp)

`if` version is better to understand.

## Exercise 4.23

> The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

conditional operators has really low precedence. Should be like: `string pl = s + (s[s.size() - 1] == 's' ? "" : "s");`

## Exercise 4.24

> Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.

`finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";`

for right associative:

`finalgrade = ((grade > 90) ? "high pass" : ((grade < 60) ? "fail" : "pass"));`

if change to left associative:

`finalgrade = (((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass");`

so result might only be fail or pass.

## Exercise 4.25

> What is the value of ~'q' << 6 on a machine with 32-bit ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the bit pattern 01110001?

`~` has higher precedence than `<<`, so `~'q'` will be: `10001110`, where `char` is signed 8 bits, -128~127, ~'q' equals -114.

Then (-114) << 6 equals (-114) * 2^6 = -7296 

Another procedure is: 

0111 0001 ->
 
1000 1110 (8 bits in dec: -114) -> 

1111 1111 1111 1111 1111 1111 1000 1110 (32 bits in dec: -114) ->

1111 1111 1111 1111 1110 0011 1000 0000 ( << 6, in dec: 4294960000 - 2^32 = -7296)

[code](ex4_25)

## Exercise 4.26

> In our grading example in this section, what would happen if we used `unsigned int` as the type for `quiz1`?

`int` without `long` could only promise at least 16 bits, but the teacher has 30 students, so the `int` might not be large enough to hold all of the students data.

## Exercise 4.27

> What is the result of each of these expressions?
```cpp
unsigned long ul1 = 3, ul2 = 7;
```

(a) ```cpp ul1 & ul2; // 3 ```

(b) ```cpp ul1 | ul2; // 7 ```

(c) ```cpp ul1 && ul2; // true ```

(d) ```cpp ul1 || ul2; // true ```

## Exercise 4.28

> Write a program to print the size of each of the built-in types.

[code](ex4_28.cpp)

## Exercise 4.29

> Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
```cpp
int x[10]; int *p = x;
cout << sizeof(x) / sizeof(*x) << endl;
cout << sizeof(p) / sizeof(*p) << endl;
```

The first one is 10

The second one depends on the machine

## Exercise 4.30

> Using Table 4.12 (p.166), parenthesize the following expressions to match the default evaluation:
> (a) `sizeof x + y`
> (b) `sizeof p->mem[i]`
> (c) `sizeof a < b`
> (d) `sizeof f()`

(a) `(sizeof x) + y`

(b) `sizeof (p->mem[i])`

(c) `(sizeof a ) < b`

(d) `sizeof (f())` if `f()` does not return void!

## Exercise 4.31

> The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.

Using postfix or prefix doesn't matter the result in this example.

refer to [Advice: Use Postfix Operators only When Necessary](http://stackoverflow.com/questions/22591387/usage-of-prefix-or-postfix-increment-or-decrement)

## Exercise 4.32

> Explain the following loop.
```cpp
constexpr int size = 5;
int ia[size] = { 1, 2, 3, 4, 5 };
for (int *ptr = ia, ix = 0;
    ix != size && ptr != ia+size;
    ++ix, ++ptr) { /* ... */ }
```

ptr is the pointer to array, ix is the index to array, they act same function in this loop

## Exercise 4.33

> Using Table 4.12 (p.166) explain what the following expression does:
> `someValue ? ++x, ++y : --x, --y`

~~if someValue is true, x += 1, y += 1, return new value of y. Else, x -= 1, y -= 1, return new value of y~~

comma has the lowest precedence in this expression, so it should be like `(someValue ? ++x, ++y : --x), --y`.

First check someValue is true or not. If true, x += 1, y += 1, then y -= 1, return the new y;

Else, x -= 1, then y -= 1, return the new y.

## Exercise 4.34

> Given the variable definitions in this section, explain what conversions take place in the following expressions: 
> 
> (a) `if (fval)`
> 
> (b) `dval = fval + ival;` 
> 
> (c) `dval + ival * cval;`
> 
> Remember that you may need to consider the associativity of the operators.

(a) if fval equals 0, convert to false, else to true

(b) ival converts to float, the result of fval add ival convert to double

(c) cval converts to int, then the result of ival times cval convert to double

## Exercise 4.35

> Given the following definitions,
> 
> ```cpp char cval; int ival; unsigned int ui; float fval; double dval; ```
> 
> identify the implicit type conversions, if any, taking place:
> 
> (a) `cval = 'a' + 3;`
> 
> (b) `fval = ui - ival * 1.0;` 
> 
> (c) `dval = ui * fval;`
> 
> (d) `cval = ival + fval + dval;`

(a) 'a' converts to int then the add result convert to char

(b) ival convert to double, ui convert to double, then the result truncate to float

(c) ui convert to float, then the muiltiple result convert to double

(d) ival and fval convert to double, then the add result convert to char by truncation.

## Exercise 4.36

> Assuming `i` is an `int` and `d` is a `double`. Write the expression `i *= d` so that it does integral, rather than floating-point, multiplication.

```cpp
i *= static_cast<int>(d);
```

## Exercise 4.37

> Rewrite each of the following old-style casts to use a named cast:
> ```cpp int i; double d; const string *ps; char *pc; void *pv; ```
> 
> (a) `pv = (void*)ps;`
> 
> (b) `i = int(*pc);`
> 
> (c) `pv = &d;`
> 
> (d) `pc = (char*) pv;`

(a) `pv = const_cast<string*>(ps)`

(b) `i = static_cast<int>(*pc)`

(c) `pv = static_cast<void*>(&d)`

(d) ~~`pc = static_cast<char*>(pv)`~~
If neither cast is legal, then an old-style cast performs a `reinterpret_cast`. So,

`pc = reinterpret_cast<char*>(pv)`

## Exercise 4.38

> Explain the following expression:
> `double slope = static_cast<double>(j/i);`

if j and i are both int, (j/i) will be an int, then convert to double.