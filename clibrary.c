
//foo.h

#ifndef foo_h__
#define foo_h__
 
extern void foo(void);
 
#endif  // foo_h__


—————————————

//foo.c

#include <stdio.h>
 
 
void foo(void)
{
    puts("Hello, I'm a shared library");
}

——————————————

//main.c

#include <stdio.h>
#include "foo.h"
 
int main(void)
{
    puts("This is a shared library test...");
    foo();
    return 0;
}

—————————————

//1: Compiling with Independent Code

$ gcc -c -Wall -Werror -fpic foo.c


——————————————


//2: Create a shared library from object file

gcc -shared -o libfoo.so foo.o


——————————————


//3: Linking with a shared library

$ gcc -Wall -o test main.c -lfoo
/usr/bin/ld: cannot find -lfoo
collect2: ld returned 1 exit status


————————————

//Tell gcc where to find the library

$ gcc -L/home/username/foo -Wall -o test main.c -lfoo


————————————

//4: Making the Library at Runtime

$ ./test
./test: error while loading shared libraries: libfoo.so: cannot open shared object file: No such file or directory


————————————

//Using LD_LIBRARY_PATH


$ echo $LD_LIBRARY_PATH


————————————

//Prepend working directory to existing LD_LIBRARY_PATH


$ LD_LIBRARY_PATH=/home/username/foo:$LD_LIBRARY_PATH
$ ./test
./test: error while loading shared libraries: libfoo.so: cannot open shared object file: No such file or directory


————————————

//Export

$ export LD_LIBRARY_PATH=/home/username/foo:$LD_LIBRARY_PATH
$ ./test
This is a shared library test...
Hello, I'm a shared library


———————————

~~~EXPLORE~~~

//prog1.h

Implementation 1

#ifndef prog1_h__
#define prog1_h__
 
extern void prog1(void);
 
#endif  // prog1_h__


—————————————

//prog1.c

#include <stdio.h>
 
 
void prog1(void)
{
    puts(“Meow, I'm a book in the lib, I think“);
}

——————————————

//prog2.h

Implementation 2

#ifndef prog2_h__
#define prog2_h__
 
extern void prog2(void);
 
#endif  // prog1_h__


——————————————

//prog2.c

#include <stdio.h>
 
 
void prog2(void)
{
    int counter;
    for(int i = 0; i > 6; i++)
    {
	counter += 1;
    }

    puts(“Woof, I'm also a book in the lib, I’m lib book no. %d!“, counter);
}

——————————————

//main.c

#include <stdio.h>
#include “prog1.h”
#include “prog2.h”
 
int main(void)
{
    puts("This is a shared library test...");
    prog1();
    prog2();

    return 0;
}

—————————————

//1: Compiling with Independent Code

$ gcc -c -Wall -Werror -fpic prog1.c prog2.c


——————————————


//2: Create a shared library from object file

gcc -shared -o libprogs.so prog1.o prog2.o


——————————————


//3: Linking with a shared library

$ gcc -Wall -o test main.c -lprog
/usr/bin/ld: cannot find -lprog
collect2: ld returned 1 exit status


————————————

//Tell gcc where to find the library

$ gcc -L/home/username/prog -Wall -o test main.c -lprog


————————————

//4: Making the Library at Runtime

$ ./test
./test: error while loading shared libraries: libprog.so: cannot open shared object file: No such file or directory


————————————

//Using LD_LIBRARY_PATH


$ echo $LD_LIBRARY_PATH


————————————

//Prepend working directory to existing LD_LIBRARY_PATH


$ LD_LIBRARY_PATH=/home/username/prog:$LD_LIBRARY_PATH
$ ./test
./test: error while loading shared libraries: libprog.so: cannot open shared object file: No such file or directory


————————————

//Export

$ export LD_LIBRARY_PATH=/home/username/prog:$LD_LIBRARY_PATH
$ ./test
This is a shared library test...

Meow, I’m a book in the lib, I think
Woof, I’m also a book in the lib, I’m book no. 6!


———————————


