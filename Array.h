/*
This Array.h interface defines high-level functions for arrays of abstract items: initialize
random values, initialize values read from standard input, print the contents, and sort the
contents.
*/
//typedef int Item;
void randint(Item [], int);
void scaninit(Item [], int*);
void show(Item [], int, int);
void sort(Item [], int, int);
