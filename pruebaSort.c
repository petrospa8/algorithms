/* This program was done for Practical 2 of Algorithms by Sergio García Cascón
and Pedro Pillado García-Gesto*/
/* pedro.pilladog@udc.es | sergio.gcascon@udc.es */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#define THRESHOLD 1

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

void SortAux (int v[], int left, int right){
  int i,j,pivot;
  if ((left + THRESHOLD) <= right){
    Median3 (v, left, right);
    pivot = v[left];
    i = left;
    j = right;
  	do{
			do{
				i++;
			}while(v[i] < pivot);
			do{
				j--;
			}while(v[j] > pivot);
			swap(v, i, j);
  	}while(j > i);
	swap(v, i, j);
	swap(v, left, j);
	SortAux(v, left, j-1);
	SortAux(v, j+1, right);
	}
}

void quick_sort (int v[], int n ){
  SortAux(v, 0, n-1);
  if (THRESHOLD > 1)
    InsertionSort(v,n);
}
void testQuickRandom (int size){
	int v[size];
	bool ran;
	printf("Testing Quick sort algorithm with a random initialized array:\n");
	random_init(v,size);
	printArray(v,size);

	quick_sort(v,size);

	ran = checkOrdered(v, size);
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

void testQuickAscending (int size){
	int v[size];
	bool asc;
	printf("Testing Quick sort algorithm with an ascending array:\n");
	ascending_init(v,size);
	printArray(v,size);

	quick_sort(v,size);

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

void testQuickDescending (int size){
	int v[size];
	bool desc;
	printf("Testing Quick sort algorithm with a descending array:\n");
	descending_init(v,size);
	printArray(v,size);

  quick_sort(v,size);

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

void testQuickSort (int size){
	testQuickRandom(size);
	testQuickAscending(size);
  testQuickDescending(size);
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
		for(i = 1; i <= k; i++){
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
	int j;
	float f,g,h;
	double t,t1,t2,tr,time;
	tr = time_init_r(v,n,k);
	t1 = microseconds();
	random_init(v,n);
  InsertionSort(v,n);
  t2 = microseconds();
  t = t2 - t1 - tr; /* Sorting time with random numbers */
	if (t < 500){
		t1 = microseconds();
		for(j = 1; j < k; j++){
			random_init(v,n);
			InsertionSort(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		t2 = microseconds();
		time = (t2 - t1)/k - tr;
	}
	else {
		time = t;
	}
	f = t / (pow(n,1.8)); /* underestimated bound */
	g = t / (pow(n,2)); /*tight bound*/
	h = t / (pow(n,2.2)); /* overestimated bound */
	TableOFValues2(n,time,f,g,h);
}

void InsertionTimeA(int n, int k){
	int v[n];
	int j;
	float f,g,h;
	double t,t1,t2,ta,time;
	ta = time_init_a(v,n,k);
	t1 = microseconds();
	ascending_init(v,n); /* Puse esto porque hay que restar el tiempo de inicializacion y no lo estabamos haciendo */
  InsertionSort(v,n);
  t2 = microseconds();
  t = t2 - t1 - ta; /* Sorting time with random numbers */
	if (t < 500){
		t1 = microseconds();
		for(j = 1; j < k; j++){
			ascending_init(v,n);
			InsertionSort(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		t2 = microseconds();
		time = (t2 - t1)/k - ta;
	}
	else {
		time = t;
	}
	f = t / (pow(n,0.8)); /* underestimated bound */
	g = t / n; /*tight bound*/
	h = t / (pow(n,1.2)); /* overestimated bound */
	TableOFValues2(n,time,f,g,h);
}

void InsertionTimeD(int n, int k){
	int v[n];
	int j;
	float f,g,h;
	double t,t1,t2,td,time;
	td = time_init_d(v,n,k);
	t1 = microseconds();
	descending_init(v,n);
  InsertionSort(v,n);
  t2 = microseconds();
  t = t2 - t1 - td; /* Sorting time with random numbers */
	if (t < 500){
		t1 = microseconds();
		for(j = 1; j < k; j++){
			descending_init(v,n);
			InsertionSort(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		t2 = microseconds();
		time = (t2 - t1)/k - td;
	}
	else {
		time = t;
	}
	f = t / (pow(n,1.8)); /* underestimated bound */
	g = t / (pow(n,2)); /*tight bound*/
	h = t / (pow(n,2.2)); /* overestimated bound */
	TableOFValues2(n,time,f,g,h);
}

void InsertionTime(int k){
	int i;
	printf("Insertion sort with random initialisaion. \n\n");
	for(i = 512; i <= 1000000 ; i = i * 2){
			InsertionTimeR(i,k);
	}
	printf("Insertion sort with ascending initialisaion. \n\n");
	for(i = 512; i <= 1000000 ; i = i * 2){
			InsertionTimeA(i,k);
	}
	printf("Insertion sort with descending initialisaion. \n\n");
	for(i = 512; i <= 1000000 ; i = i * 2){
			InsertionTimeD(i,k);
	}
}

void QuickTimeR (int n, int k){
	int v[n];
	int j;
	float f,g,h;
	double t,t1,t2,tr,time;
	tr = time_init_r(v,n,k);
	t1 = microseconds();
	random_init(v,n);
	quick_sort(v,n);
  t2 = microseconds();
	t = t2 - t1; /* Sorting time with random numbers */
	if (t < 500){
		t1 = microseconds();
		for(j = 1; j < k; j++){
			random_init(v,n);
			quick_sort(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		t2 = microseconds();
		time = (t2 - t1)/k - tr;
	}
	else {
		time = t - tr;
	}
	f = t / (n*log(n)); /* underestimated bound */
	g = t / (n*log(n)); /*tight bound*/
	h = t / (n*log(n)); /* overestimated bound */
	TableOFValues2(n,time,f,g,h);
}

void QuickTimeA (int n, int k){
	int v[n];
	int j;
	float f,g,h;
	double t,t1,t2,ta,time;
	ta = time_init_a(v,n,k);
	t1 = microseconds();
	ascending_init(v,n);
  quick_sort(v,n);
  t2 = microseconds();
  t = t2 - t1; /* Sorting time with random numbers */
	if (t < 500){
		t1 = microseconds();
		for(j = 1; j < k; j++){
			ascending_init(v,n);
			quick_sort(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		t2 = microseconds();
		time = (t2 - t1)/k - ta;
	}
	else {
		time = t - ta;
	}
	f = t / (n*log(n)); /* underestimated bound */
	g = t / (n*log(n)); /*tight bound*/
	h = t / (n*log(n)); /* overestimated bound */
	TableOFValues2(n,time,f,g,h);
}

void QuickTimeD (int n, int k){
	int v[n];
	int j;
	float f,g,h;
	double t,t1,t2,td,time;
	td = time_init_d(v,n,k);
	t1 = microseconds();
	descending_init(v,n);
  quick_sort(v,n);
  t2 = microseconds();
	t = t2 - t1; /* Sorting time with random numbers */
	if (t < 500){
		t1 = microseconds();
		for(j = 1; j < k; j++){
			descending_init(v,n);
			quick_sort(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		t2 = microseconds();
		time = (t2 - t1)/k - td;
	}
	else {
		time = t - td;
	}
	f = t / (n*log(n)); /* underestimated bound */
	g = t / (n*log(n)); /*tight bound*/
	h = t / (n*log(n)); /* overestimated bound */
	TableOFValues2(n,time,f,g,h);
}


void QuickTime(int k){
	int i;
		printf("Quick sort with random initialisaion:\n\n");
		for(i = 1024; i <= 1000000 ; i = i * 2){
				QuickTimeR(i,k);
		}
		printf("Quick sort with ascending initialisaion:\n\n");
		for(i = 1024; i <= 1000000 ; i = i * 2){
				QuickTimeA(i,k);
		}
		printf("Quick sort with descending initialisaion:\n\n");
		for(i = 1024; i <= 1000000 ; i = i * 2){
				QuickTimeD(i,k);
		}

}

void benchmark(){
	int k = 1000;


	printf("\n\n");
	printf("Insertion sort algorithm: \n\n");
	printf("          n          |         t         |      t(n)/f(n)      ");
	printf("|      t(n)/g(n)     |   t(n)/h(n)    \n");
	printf("-------------------------------------------------------------");
	printf("----------------------------------------\n");
  InsertionTime(k);

	printf("\n");
	printf("Quick sort algorithm with threshold %d: \n\n",THRESHOLD);
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
