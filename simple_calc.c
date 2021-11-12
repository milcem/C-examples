/*
  Milka Murdjeva
  simple_calc.c
*/

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

typedef void* (*Function)();

int main(int argc, char *argv[]) {

  // Variables
  void *handle;
  void *symbol_addr;
  char *error;
  char *symbol;
  int arg1;
  int arg2;
  int choice;
  Function operation;

  printf("-----\n");
  printf("Simple Calculator\n");
  printf("-----\n\n");
  printf("Please enter two integers:\n");
  printf("First argument: ");
  scanf("%d", &arg1);
  printf("Second argument: ");
  scanf("%d", &arg2);
  printf("\n-----\n");
  printf("Choose an operation:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n\n");
  printf("-->");
  scanf("%d", &choice);
  printf("\n-----\n\n");

  switch(choice) {

    case 1 :
      printf("Addition chosen.\n");
      symbol = "addition";
      handle = dlopen("./addition.so", RTLD_LAZY);
      break;

    case 2 :
      printf("Subtraction chosen.\n");
      symbol = "subtraction";
      handle = dlopen("./subtraction.so", RTLD_LAZY);
      break;

    case 3 :
      printf("Multiplication chosen.\n");
      symbol = "multiplication";
      handle = dlopen("./multiplication.so", RTLD_LAZY);
      break;

    case 4 :
      printf("Division chosen.\n");
      symbol = "division";
      handle = dlopen("./division.so", RTLD_LAZY);
      break;
  }

  if(handle == NULL) {
    puts(dlerror());
    exit(1);
  }

  dlerror();
  *(void**)(&operation) = dlsym(handle, symbol);
  if(error = dlerror()) {
    puts(error);
    exit(1);
  }

  (void) operation(arg1, arg2);

  dlclose(handle);

  printf("\n-----\n");

  return 0;
}
