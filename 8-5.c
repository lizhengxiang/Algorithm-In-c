#define min(a, b) (a < b) ? a : b;
void mergesortBu(Item a[], int l, int r){
  int i, m;
  for(m = 1; m <= r-l; m += m)
    for(i = l; i <= r-m; i = 2 *m)
      merge(a, i, i+m-1, min(i+m+m-1, r));
}
