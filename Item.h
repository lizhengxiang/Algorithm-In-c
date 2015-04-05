/*
The file Item.h that is included in Program 6.9 defines the data type for the items to be
sorted. In this example, the items are small records consisting of integer keys and
associated floating-point information. We declare that the overloaded operator< will be
implemented separately, as will the three functions scan (read an Item into its argument),
rand (store a random Item in its argument), and show (print an Item).
*/
typedef double Item;
#define key (a)  (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b){ Item t = a; a = b; b = t}
#define compexch(a, b) if(less(a, b)) exch(a, b)

Item ITEMrand(void);
int ITEMscan(Item *);
void ITEMshow(Item );
