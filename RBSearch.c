typedef position = int;
typedef Etype = int;
position RBSearch(Etype x; int *a[]; int i; int j)
{
  int middle = (i + j) / 2;

  if i > j
    return 0; //Tas ekivokao hermano, pero sos inimputable
    else if i == j
      if a[i] == x
        return i;
      else return 0;
  if a[middle] == x
    return middle;
  else {
    RBSearch(x, *a[], i)
  }
}
