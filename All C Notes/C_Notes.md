# C Notes
Required to compile code to a machine-code executable file (extension is .c)

Compile:

`gcc filename.c -o filename`

To run:

`./filename`

#### Disadvantages
* Must be compiled on every architecture
* Difficult to debug

#### Static Typing
Once you set the type for the variable, it must remain that way!

#### A bit more Unsafe than Java
Ex: char generic_array[] = {'a','b','c'};
generic_array[2];
// Returns 'c';
generic_array[6];
// Returns garbage value!!! ----> Be careful! SEGFAULTS! 

### Memory Layout
* malloc: Does not initialize the memory allocated
* calloc: Initializes allocated memory to 0.

Malloc takes in 1 argument: num of bytes that need to be allocated. 

`sizeof(int)` returns the number of bytes in an integer and we mutliply this by the number of elements in the array.

```c
int number_elemets = 5;
int * ptr = malloc(sizeof(int) * number_elements);
```

```c
int main() {
  
  // Allocate memory for images of cake
  images *cake = malloc(sizeof(cake_image) * NUMBER_OF_CAKE_IMAGES);
  //Do something with the cake images here
  free(cake); //FREE THE SPACE!
  
}
```

## KNOW THE MEMORY LAYOUT! Or we are gonna get those segfaults :(

## Pointers! (REALLY REALLY IMPORTANT)
A pointer is a variable that contains a memory address of another variable. In C, the asterisk (*) denotes a variable as a pointer to the data type to the left of it.

Ex. `int * num1;` Is a pointer to an integer. And `int ** num2;` is a pointer to a pointer to an integer.

The `&` sign allows you to get the memory location of that variable.

Ex. 
```c
int x = 4;
int * ptr = &x; //ptr is a pointer to the memory location of `x`
```

Pointers are used for several reasons:
* Strings
* Dynamic memory allocation
* Sending function arguments by reference
* building complicated data structures
* pointing to functions
* Building special data structures (like Tree, Tries, etc.)

## Memory diagram
One of the many types of memory diagrams to visualize the layout:

`int x = 4; // The compiler chooses the location`
+----------+-------+
| Location | Value |
+----------+-------+
| 0x00     |       |
+----------+-------+
| 0x01     | 4     |
+----------+-------+
| 0x02     |       |
+----------+-------+
| 0x03     |       |
+----------+-------+

If we create a pointer that points to variable x: `int * ptr = &x;`
+----------+-------+
| Location | Value |
+----------+-------+
| 0x00     |       |
+----------+-------+
| 0x01     | 4     |
+----------+-------+
| 0x02     |  0x01 |
+----------+-------+
| 0x03     |       |
+----------+-------+
 
What about this one? `int ** ptr2 = &ptr;`
 +----------+-------+
| Location | Value |
+----------+-------+
| 0x00     |       |
+----------+-------+
| 0x01     | 4     |
+----------+-------+
| 0x02     |  0x01 |
+----------+-------+
| 0x03     |  0x02 |
+----------+-------+

## Get the values of pointers
Use the dereference operator (*). Derefences a pointer to the location it points to:

We can change the contents of the dereferenced variable.

```c
//Example of changing a dereferenced variable
int x = 1;
int * ptr = &x;

//Change x
x += 10;

*ptr += 1;

//Will print out 12
printf("The value of x is now %d\n", x);
```

#### Use arrays as examples
array a (below) is just a pointer to the first element. They are collections of consecutive memory locations.
Arrays can only have 1 type of variable because they are implemented as a sequence of values in a computer's memory.
```c
int a[] = {1, 2, 3};
int first_value = *a; // Dereference to return 1
int next_value = *(a + 1); // get the next memory address (a + 1) then dereferences that memory address to return 2.
int third_value = a[2]; // Same thing as *(a + 2), returns 3.
```

C Arrays are NOT DYNAMIC, if we want to append an element to the end, we must manually allocate more space (I cry).

```c
int num_of_elements = 3;
int *resize_arr = malloc(sizeof(int) * num_of_elements); // Original size
resize_arr = realloc(resize_arr, sizeof(int) * (num_of_elements + 1)); // Resize
free(resize_arr);
```

## You can cast your types regardless of byte size.
Will throw warnings.

If you want to case your char as an int, go ahead! If you want to cast a pointer to an integer, go ahead!

# C Fundamentals

## Data Types
* Integers: Whole numbers, positive or negative. By default, they are signed.

* Unsigned Integers: Can only be positive! (Can also have unsigned char, int, short, long, long long)

* Float/double: Real numbers (decimals)

A char can range from -128 to 127, a long can range from -2,147,483,648  to 2,147,483,648 .

C Does NOT have a boolean type, so we can use:

```c
#define BOOL char
#define FALSE 0
#define TRUE 1
```

C Uses arrays of characters to define strings. (ex. char * string_name)

## "Strings"
Don't forget to import `#include <string.h>`!

To create a string that we can only read, use: `char * var_name = "value";`

To create a string that can be manipulated, define it as a local character array: `char var_name[] = "value";`
This allocates an array variable so we can manipulate it and the `[]` tells the compiler to calculate the size of the array automatically (the same as adding 1 to the length of the string).

Ex. `char name[] = "Sally";` Is the same as `char name[6] = "Sally";`

### printf Statements
Use `printf()` to print output.

Ex. 
```c
char * name = "Sally"; // --> Allocates a local (stack) variable called `name` which is a pointer to where the first character resides at in memory.
int age = 33;

printf("%s is %d years old.\n", name, age); // We need a "\n" to print the next printf on a new line

```

### String length
Use `strlen` to return the length of a string:
Ex. `strlen(string_name);` 

### String comparison
strncmp compares 2 strings and returns 0 if they are equal. 

* If return value is < 0, var1 < var 2.
* If return value is > 0, var 1 > var 2.

Syntax: `strncmp(const char * str1, const char * str2, size_t n)`. "n" is the max number of characters you want to compare.

### String concatenation
`strncat` appends the first "n" characters of a source string to the destination string where n is min(n, length(src)).

Ex. `strncat(dest, src, 20);`

### Multidimensional Arrays
C can create and use multidimensional arrays.

ex. `int foo[1][2][3];` or another example: `char vowels[1][5] = {{'a','e','i','o','u'}};

#### 2D Arrays
Syntax: `Data_Type array_name[rows][columns];`

The compiler will already know that there are 2 dimensions, but we do need to indicate the number of columns. This is valid:

```c
char vowels[][5] = { 
  {'A', 'E', 'I', 'O', 'U'},
  {'a', 'e', 'i', 'o', 'u'}
};

//Can also be initialized as so:

char vowelss[2][5] = {'A','E','I','O','U','a','e','i','o','u'};
```

Access 2D array elements like so: `array_name[row][column];`

## Defining variables
```c
int foo; //uninitialized` -> If we try to access it, we don't know what's in it
int bar = 1; //initialized
```

## If-Else statements
Similar to Java. Comparator operands like `<`,`>`,`>=`,`<=`,`==`,`!=` can be used. Can also use AND `&&` and OR `||` to add more than 1 condition.

Ex:
```c
int num = 10;
if(num == 10) {
  printf("Num is 10");
}
```

## For loops & While Loops
Similar to Java. Can use for loops to iterate array values.

```c
//Example, this will print out the numbers 0-9 per line.
int i;
for (i = 0; i < 10; i++) {
    printf("%d\n", i);
}

printf("While Loop: \n");
int n = 0;
while (n < 10) {
    n++;
}
```

While loops can execute infinitely like so:

`while(1) { /* do something */ };`

### Break and Continue
Break stops a loop and the program will skip the rest of this loop or condition.

Continue skips 1 iteration of the loop.

## Functions
Arguments are pass by value to functions (we cannot change the arguments to affect their values outside the function. To do so, we need to use pointers).

Functions must be defined before they are called in the code! 2 return types: return a type, or don't return (void) 

```c
//Example of a function that multiplies an integer by 10
int foo(int num) {
  return num * 10;
}

int main() {
  foo(2); // Function call
}
```

OR 

```c
int foo(int num); // Declare function here

int main() {
  foo(2); // Function call
}

// Define the function here
int foo(int num) {
  return num * 10;
}

```

Void method example:
`void foo() {/* Do something */};`

Main method example:
`int main() //For zero arguments`

`int main(int argc, char * argv[]) //argc is the number of command line arguments including the name of the program, argv are all the arguments. argv[0] is the name of the program

## Static keyword

#### Variables:
The `static` keyword will increase the scope of a variable to the entire file containing them.

If `static` is not used, variables inside functions will not be updated because it is removed from memory as soon as the function finishes, but
if we use `static`, the value will be updated.

#### Functions:
By default, functions are global in C, we we declare a function as `static`, the scope is reduced to the file containing it.

Syntax:
```c
static void foo(void) {
  /*Do something */
}
```
## Global
Global variables can be accessed outside the file too.

## Structures
C Structs are like large variables that have variables inside them.

Example: 
```c
// Creates a struct that acts like a coordinate (x,y)
struct point {
    int x;
    int y;
};
```

Access struct arguments like so:

Example:
```c
struct point p;
p.x = 1;
p.y = 3;
```

## Typedefs
Allow us to define types with different names

Example:
```c
typedef struct {
  int x;
  int y;
} point;

// Define a new point:
point p;
```

## Function arguments by reference
Function arguments are passed by value, this means they are copied in and out of functions but if we copy pointers to values, we can change them because we know where they are in memory!

## Pointers to structures
Let's use our previous point struct as an example. If we want to create a function to move a point forward in both (x,y), instead of sending 2 pointers, we pass the struct in as a pointer.

```c
void move(point * p) {
    (*p).x++;
    (*p).y++;
}
```

BUT, if we want to dereference the struct and access one of it's attributes, we need to use `->` inside data structures.
```c
void move(point * p) {
    p->x++;
    p->y++;
}
```

## Dynamic allocation
Example: Dynamically allocate a structure like so:
```c
typedef struct {
    char * name;
    int number;
} foo;
```
To allocate a new foo struct, use the following example:
```c
foo * new_foo = (foo *) malloc(sizeof(foo));
```
This tells the compiler, we want to dynamically allocate just enough space to hold a foo struct in memory then return a pointer.

To access foo's members, use `->`:
`new_foo->name = "generic_name";`

Then free the struct: `free(new_foo);`

Free does not delete the `new_foo` variable, it releases the data it points to. If we try to call `new_foo` after freeing it, we get PROBLEMS!

## Bit masking:
Storing data as bits opposed to chars/ints/floats. Based on boolean logic through logical operations.

* NOT (!)
* AND (&)
* OR (|)
* XOR (^)

### Setting bit "n"
To set the bit n, OR the value of the storage variable with the value 2^n.

### Clearing bit "n"
To clear the bit n, AND the value of the storage variable with the inverse (NOT) of the value 2^n.

## C Example
```c

```

## C++ Example
```cpp
int main() {
  cout << "Hellow World!" << std::endl();
}
```
