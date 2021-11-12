addition: addition.c
	gcc -c -Wall -Werror -fpic $^
	gcc -shared -o addition.so addition.o
	rm -f addition.o

subtraction: subtraction.c
	gcc -c -Wall -Werror -fpic $^
	gcc -shared -o subtraction.so subtraction.o
	rm -f subtraction.o

multiplication: multiplication.c
	gcc -c -Wall -Werror -fpic $^
	gcc -shared -o multiplication.so multiplication.o
	rm -f multiplication.o

division: division.c
	gcc -c -Wall -Werror -fpic $^
	gcc -shared -o division.so division.o
	rm -f division.o

simple_calc: simple_calc.c
	gcc -ldl -o $@ $^
