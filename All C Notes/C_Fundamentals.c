#include <stdio.h> // Allows us to run printf, import all libraries up here!

// Our code to run goes here, main returns an integer (0 means the program returned successfully)
int main() {
  
  printf("Hello World!"); // C Print Statement
  printf("%d", 55); // Prints out decimals
  
  // Define a local variable x
  int x = 1;
  
  // Define a pointer variable and point it to x
  int * ptr = &x;
  printf("The value x is %d\n", x);
  printf("The value of x is also %d\n", *ptr);
  
  // Structs can hold pointers!
  cake order;
  order.cake_type = "Chocolate";
  order.number_ordered = 10;

  return 0;
}

typedef struct {
  char * cake_type;
  int number_ordered;
} cake;