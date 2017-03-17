all: pointers.c check_ptrs

pointers: pointers.c
	gcc -o pointers pointers.c 

check_ptrs: pointers.c check_ptrs.c
	gcc -o check_ptrs check_ptrs.c pointers.c -lcheck
