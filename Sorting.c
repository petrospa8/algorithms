/* This program was done for Practical 2 of Algorithms by Sergio García Cascón
and Pedro Pillado García-Gesto*/
/* pedro.pilladog@udc.es | sergio.gcascon@udc.es */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

double microseconds() {
	struct timeval t;
	if (gettimeofday(&t, NULL) < 0 )
		return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
}

void init_seed() {
  srand(time(NULL));
}

void random_init(int v[], int n){
  int i, m = 2*n+1;
  for (i = 0; i < n; i++){
    v[i] = (rand() % m) - n;
	}
}

void ascending_init (int v[], int n){
  int i;
  for (i = 0; i < n; i++)
    v[i] = i;
}

void descending_init (int v[], int n){
  int i,k;
  k = n+3;
  for (i = 0; i < n; i++){
    v[i] = k;
    k--;
  }
}

void InsertionSort (int v[], int n){
  int i,j,x;
  for (i = 0; i < n; i++){
    x = v[i];
    j = i-1;
    while(j>=0 && v[j]>x) {
      v[j+1] = v[j];
			j--;
    }
    v[j+1] = x;
  }
}

bool checkOrdered(int v[], int size){
  int i;
  for(i = 0; i < (size - 1); i++){
    if (v[i] > v[i+1]){
       return false;
	 	}
	}
  return true;
}

void printArray(int v[],int size){
	int i;
	printf("[");
	for (i = 0; i<(size-1); i++){
		printf(" %d ;", v[i]);
	}
	printf(" %d ]\n", v[size-1]);
}

void testInsertRandom (int size){
	int v[size];
	bool ran;
	printf("Testing Insertion sort algorithm with a random initialized array:\n");
	random_init(v,size);
	printArray(v,size);
	InsertionSort(v,size);

	ran = checkOrdered(v,size);
	if (ran) {
		printf("Insertion sort has successfully sorted an");
		printf(" array with random values.\n");
		printArray(v,size);
	}
	else {
		printf("Insertion sort has failed to sort an array with random values.\n");
		printArray(v,size);
	}
}

void testInsertAscending (int size){
	int v[size];
	bool asc;
	printf("Testing Insertion sort algorithm with an ascending array:\n");
	ascending_init(v,size);
	printArray(v,size);

	InsertionSort(v,size);
	asc = checkOrdered(v,size);
	if (asc) {
		printf("Insertion sort has successfully sorted an");
		printf(" array with ascending values.\n");
		printArray(v,size);
	}
	else {
		printf("Insertion sort has failed to sort an array with descending");
		printf(" values.\n");
		printArray(v,size);
	}
}

void testInsertDescending (int size){
	int v[size];
	bool desc;
	printf("Testing Insertion sort algorithm with a descending array:\n");
	descending_init(v,size);
	printArray(v,size);

	InsertionSort(v,size);
	desc = checkOrdered(v, size);
	if (desc) {
		printf("Insertion sort has successfully sorted an");
		printf(" array with descending values.\n");
		printArray(v,size);
	}
	else {
		printf("Insertion sort has failed to sort an array with descending");
		printf(" values.\n");
		printArray(v,size);
	}
}
void testInsertionSort (int size){
  testInsertRandom(size);
	testInsertAscending(size);
	testInsertDescending(size);
}

void swap (int v[], int i, int j){
  int aux ;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;

}

void Median3 (int v[], int i, int j){
  int k;
  k = (i + j) / 2;
  if (v[k] > v[j])
    swap(v,k,j);
  if (v[k] > v[i])
    swap(v,k,i);
  if (v[i] > v[j])
    swap(v,i,j);
}

void SortAux (int v[], int left, int right, int threshold){
  int i,j,pivot;
  if ((left + threshold) <= right){
    Median3 (v, left, right);
    pivot = v[left];
    i = left;
    j = right;
  	do{
			do{
				i++;
			}while(v[i] < pivot);
			do{
				j += -1;
			}while(v[j] > pivot);
			swap(v, i, j);
  	}while(j > i);
	swap(v, i, j);
	swap(v, left, j);
	SortAux(v, left, j-1,threshold);
	SortAux(v, j+1, right,threshold);
	}
}

void quick_sort (int v[], int n, int threshold){
  SortAux(v, 0, n-1, threshold);
  if (threshold > 1)
    InsertionSort(v,n);
}
void testQuickRandom (int size, int threshold){
	int v[size];
	bool ran;
	printf("Testing Quick sort algorithm with a random initialized array:\n");
	random_init(v,size);
	printArray(v,size);

	quick_sort(v,size,threshold);

	ran = checkOrdered(v,size);
	if (ran) {
		printf("Quick sort has successfully sorted an");
		printf(" array with random values.\n");
		printArray(v,size);
	}
	else {
		printf("Quick sort has failed to sort an array with random values.\n\n");
		printArray(v,size);
	}
}

void testQuickAscending (int size, int threshold){
	int v[size];
	bool asc;
	printf("Testing Quick sort algorithm with an ascending array:\n");
	ascending_init(v,size);
	printArray(v,size);

	quick_sort(v,size,threshold);

	asc = checkOrdered(v,size);
	if (asc) {
		printf("Quick sort has successfully sorted an");
		printf(" array with ascending values.\n");
		printArray(v,size);
	}
	else {
		printf("Quick sort has failed to sort an array with descending values.\n\n");
		printArray(v,size);
	}
}

void testQuickDescending (int size, int threshold){
	int v[size];
	bool desc;
	printf("Testing Quick sort algorithm with a descending array:\n");
	descending_init(v,size);
	printArray(v,size);

  quick_sort(v,size,threshold);

  desc = checkOrdered(v, size);
  if (desc) {
    printf("Quick sort has successfully sorted an");
    printf(" array with descending values.\n");
		printArray(v,size);
  }
  else {
    printf("Quick sort has failed to sort an array with descending values.\n\n");
		printArray(v,size);
  }
}

void testQuickSort (int size, int threshold){
	testQuickRandom(size, threshold);
	testQuickAscending(size,threshold);
  testQuickDescending(size,threshold);
}

double time_init_r (int v[], int n, int k){
	int i;
	double t1,t2,tf;
	t1 = microseconds();
	random_init(v,n);
	 /*measure the tme of initialising an array with random values */
	t2 = microseconds();
	tf = t2 - t1;
	if (tf < 500){
		t1 = microseconds();
		for(i = 1; i < k; i++){
			random_init(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		t2 = microseconds();
		tf = (t2 - t1)/k;
	}
	return tf;
}
double time_init_a (int v[], int n, int k){
	int i;
	double t1,t2,tf;
	t1 = microseconds();
	ascending_init(v,n);
	/*measure the tme of initialising an array with random values */
	t2 = microseconds();
	tf = t2 - t1;
	if (tf < 500){
		t1 = microseconds();
		for(i = 1; i < k; i++){
			ascending_init(v,n);
			/*measure the tme of initialising an array with random values */
		}
		t2 = microseconds();
		tf = (t2 - t1)/k;
  }
	return tf;
}

double time_init_d (int v[], int n, int k){
	int i;
	double t1,t2,tf;
	t1 = microseconds();
	descending_init(v,n);
	/*measure the tme of initialising an array with random values */
	t2 = microseconds();
	tf = t2 - t1;
	if (tf < 500){
		t1 = microseconds();
		for(i = 1; i < k; i++){
			descending_init(v,n);
			/*measure the tme of initialising an array with random values */
		}
		t2 = microseconds();
		tf = (t2 - t1)/k;
	}
	return tf;
}

void TableOFValues2(int n, float t, float f, float g, float h){
		printf("      %*d    |    %11.3lf    |      %9.5f      |",11,n,t,f);
		printf("       %7.5f      |    %0.5f    \n",g,h );
}

void InsertionTimeR(int n, int k){
	int v[n];
	float f,g,h;
	double t,t1,t2,tr;
	tr = time_init_r(v,n,k);
	t1 = microseconds();
  InsertionSort(v,n);
  t2 = microseconds();
  t = t2 - t1 - tr; /* Sorting time with random numbers */
	f = t / (pow(n,1.8)); /* underestimated bound */
	g = t / (pow(n,2)); /*tight bound*/
	h = t / (pow(n,2.2)); /* overestimated bound */
	TableOFValues2(n,t,f,g,h);
}

void InsertionTimeA(int n, int k){
	int v[n];
	float f,g,h;
	double t,t1,t2,ta;
	ta = time_init_a(v,n,k);
	t1 = microseconds();
  InsertionSort(v,n);
  t2 = microseconds();
  t = t2 - t1 - ta; /* Sorting time with random numbers */
	f = t / (pow(n,0.8)); /* underestimated bound */
	g = t / n; /*tight bound*/
	h = t / (pow(n,1.2)); /* overestimated bound */
	TableOFValues2(n,t,f,g,h);
}

void InsertionTimeD(int n, int k){
	int v[n];
	float f,g,h;
	double t,t1,t2,td;
	td = time_init_d(v,n,k);
	t1 = microseconds();
  InsertionSort(v,n);
  t2 = microseconds();
  t = t2 - t1 - td; /* Sorting time with random numbers */
	f = t / (pow(n,1.8)); /* underestimated bound */
	g = t / (pow(n,2)); /*tight bound*/
	h = t / (pow(n,2.2)); /* overestimated bound */
	TableOFValues2(n,t,f,g,h);
}

void InsertionTime(int k){
	int i;
	printf("Insertion sort with random initialisaion. \n");
	for(i = 100; i <= 100000 ; i = i * 10){
			InsertionTimeR(i,k);
	}
	printf("Insertion sort with ascending initialisaion. \n");
	for(i = 100; i <= 100000 ; i = i * 10){
			InsertionTimeA(i,k);
	}
	printf("Insertion sort with descending initialisaion. \n");
	for(i = 100; i <= 100000 ; i = i * 10){
			InsertionTimeD(i,k);
	}
}

void QuickTimeR (int n, int k, int threshold){
	int v[n];
	int j;
	float f,g,h;
	double t,t1,t2,tr;
	tr = time_init_r(v,n,k);
	t1 = microseconds();
  quick_sort(v,n,threshold);
  t2 = microseconds();
	t = t2 - t1; /* Sorting time with random numbers */
	if (t < 500){
		t1 = microseconds();
		for(j = 1; j < k; j++){
			quick_sort(v,n,threshold);
			 /*measure the tme of initialising an array with random values */
		}
		t2 = microseconds();
		t = (t2 - t1)/k - tr;
	}
	else {
		t = t - tr;
	}
	f = t / (0.8*n*(log(n))); /* underestimated bound */
	g = t / (n*(log(n))); /*tight bound*/
	h = t / (1.2*n*(log(n))); /* overestimated bound */
	TableOFValues2(n,t,f,g,h);
}

void QuickTimeA (int n, int k, int threshold){
	int v[n];
	int j;
	float f,g,h;
	double t,t1,t2,ta;
	ta = time_init_a(v,n,k);
	t1 = microseconds();
  quick_sort(v,n,threshold);
  t2 = microseconds();
  t = t2 - t1; /* Sorting time with random numbers */
	if (t < 500){
		t1 = microseconds();
		for(j = 1; j < k; j++){
			quick_sort(v,n,threshold);
			 /*measure the tme of initialising an array with random values */
		}
		t2 = microseconds();
		t = (t2 - t1)/k - ta;
	}
	else {
		t = t - ta;
	}
	f = t / (pow(n,1.8)); /* underestimated bound */
	g = t / (pow(n,2)); /*tight bound*/
	h = t / (pow(n,2.2)); /* overestimated bound */
	TableOFValues2(n,t,f,g,h);
}

void QuickTimeD (int n, int k, int threshold){
	int v[n];
	int j;
	float f,g,h;
	double t,t1,t2,td;
	td = time_init_d(v,n,k);
	t1 = microseconds();
  quick_sort(v,n,threshold);
  t2 = microseconds();
	t = t2 - t1; /* Sorting time with random numbers */
	if (t < 500){
		t1 = microseconds();
		for(j = 1; j < k; j++){
			quick_sort(v,n,threshold);
			 /*measure the tme of initialising an array with random values */
		}
		t2 = microseconds();
		t = (t2 - t1)/k - td;
	}
	else {
		t = t - td;
	}
	f = t / (pow(n,1.8)); /* underestimated bound */
	g = t / (pow(n,2)); /*tight bound*/
	h = t / (pow(n,2.2)); /* overestimated bound */
	TableOFValues2(n,t,f,g,h);
}


void QuickTime(int k){
	int i, threshold;
	for(threshold = 1; threshold <= 100; threshold = threshold*10){
		printf("Quick sort with random initialisaion and threshold %d. \n",threshold);
		for(i = 1000; i <= 1000000 ; i = i * 10){
				QuickTimeR(i,k,threshold);
		}
		printf("Quick sort with ascending initialisaion and threshold %d. \n",threshold);
		for(i = 1000; i <= 1000000 ; i = i * 10){
				QuickTimeA(i,k,threshold);
		}
		printf("Quick sort with descending initialisaion and threshold %d. \n",threshold);
		for(i = 1000; i <= 1000000 ; i = i * 10){
				QuickTimeD(i,k,threshold);
		}
	}
}

void benchmark(){
	int k = 100;


	printf("\n\n");
	printf("Insertion sort algorithm: \n\n");
	printf("           n          |         t(n)/f(n)         |         t(n)/g(n)         ");
	printf("|         t(n)/h(n)         \n");
	printf("-------------------------------------------------------------");
	printf("----------------------------\n");
  InsertionTime(k);

	printf("\n");
	printf("Quick sort algorithm: \n\n");
	printf("          n          |         t         |      t(n)/f(n)      ");
	printf("|      t(n)/g(n)     |   t(n)/h(n)    \n");
	printf("-------------------------------------------------------------");
	printf("----------------------------------------\n");
	QuickTime(k);
}

int main(){
/*	int i;
	int testSize = 10;
	printf("\n\n");
	testInsertionSort(testSize);
	for(i = 1; i <= 100; i = i * 10){
		testQuickSort(testSize,i);
	}
	*/
	benchmark();

}
