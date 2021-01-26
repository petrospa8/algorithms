/* This program was done for Practical 2 of Algorithms by Sergio García Cascón
and Pedro Pillado García-Gesto*/
/* pedro.pilladog@udc.es | sergio.gcascon@udc.es */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#ifndef THRESHOLD

#define THRESHOLD 10
#endif
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
  int i;
  for (i = 0; i < n; i++){
    v[i] = n-i;
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
	return;
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

void TableOFValues2(int n, int star, float t, float f, float g, float h){
	if (star == 1){
		printf("      %*d *  |    %11.3lf    |      %9.7f      |",11,n,t,f);
		printf("       %7.7f      |    %0.7f    \n",g,h );
	}
	else{
		printf("      %*d   |    %11.3lf    |      %9.7f      |",12,n,t,f);
		printf("       %7.7f      |    %0.7f    \n",g,h );
	}

}

void InsertionTimeR(int n, int k){
	int * v = (int *) malloc(n*sizeof(int));
	int j, star;
	float f,g,h;
	double t,ta,tb,t1,t2;
	random_init(v,n);
	ta = microseconds();
  InsertionSort(v,n);
  tb = microseconds();
  t = tb - ta; /* Sorting time with random numbers */
	star = 0;
	if (t < 500){
		star = 1;
		ta = microseconds();
		for(j = 1; j < k; j++){
			random_init(v,n);
			InsertionSort(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		tb = microseconds();
		t1 = tb - ta;
		ta = microseconds();
		for(j = 1; j < k; j++){
			random_init(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		tb = microseconds();
		t2 = tb - ta;
		t = (t1-t2) / k;
	}
	f = t / (pow(n,1.8)); /* underestimated bound */
	g = t / (pow(n,2)); /*tight bound*/
	h = t / (pow(n,2.2)); /* overestimated bound */
	TableOFValues2(n,star,t,f,g,h);
	free(v);
}

void InsertionTimeA(int n, int k){
	int * v = (int *) malloc(n*sizeof(int));
	int j,star;
	float f,g,h;
	double t,ta,tb,t1,t2;
	ascending_init(v,n);
	ta = microseconds();
  InsertionSort(v,n);
  tb = microseconds();
  t = tb - ta; /* Sorting time with random numbers */
	star = 0;
	if (t < 500){
		star = 1;
		ta = microseconds();
		for(j = 0; j < k; j++){
			ascending_init(v,n);
			InsertionSort(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		tb = microseconds();
		t1 = tb - ta;
		ta = microseconds();
		for(j = 1; j < k; j++){
			ascending_init(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		tb = microseconds();
		t2 = tb - ta;
		t = (t1-t2) / k;
	}
	f = t / (pow(n,0.8)); /* underestimated bound */
	g = t / n; /*tight bound*/
	h = t / (pow(n,1.2)); /* overestimated bound */
	TableOFValues2(n,star,t,f,g,h);
	free(v);
}

void InsertionTimeD(int n, int k){
	int * v = (int *) malloc(n*sizeof(int));
	int j,star;
	float f,g,h;
	double t,ta,tb,t1,t2;
	descending_init(v,n);
	ta = microseconds();
	InsertionSort(v,n);
	tb = microseconds();
	t = tb - ta; /* Sorting time with random numbers */
	star = 0;
	if (t < 500){
		star = 1;
		ta = microseconds();
		for(j = 0; j < k; j++){
			descending_init(v,n);
			InsertionSort(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		tb = microseconds();
		t1 = tb - ta;
		ta = microseconds();
		for(j = 0; j < k; j++){
			descending_init(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		tb = microseconds();
		t2 = tb - ta;
		t = (t1-t2) / k;
	}
	f = t / (pow(n,1.8)); /* underestimated bound */
	g = t / (pow(n,2)); /*tight bound*/
	h = t / (pow(n,2.2)); /* overestimated bound */
	TableOFValues2(n,star,t,f,g,h);
	free(v);
}


void InsertionTime(int k){
	int i;
	printf("Insertion sort with random initialisaion. \n\n");
	for(i = 500; i <= 128000 ; i = i * 2){
			InsertionTimeR(i,k);
	}
	printf("\n");
	printf("Insertion sort with ascending initialisaion. \n\n");
	for(i = 500; i <= 128000 ; i = i * 2){
			InsertionTimeA(i,k);
	}
	printf("\n");
	printf("Insertion sort with descending initialisaion. \n\n");
	for(i = 500; i <= 128000 ; i = i * 2){
			InsertionTimeD(i,k);
	}
	printf("\n");
}

void QuickTimeR (int n, int k){
	int * v = (int *) malloc(n*sizeof(int));
	int j, star;
	float f,g,h;
	double t,t1,t2,ta,tb;
	random_init(v,n);
	ta = microseconds();
	quick_sort(v,n);
  tb = microseconds();
	t = tb - ta; /* Sorting time with random numbers */
	star = 0;
	if (t < 500){
		star = 1;
		ta = microseconds();
		for(j = 0; j < k; j++){
			random_init(v,n);
			quick_sort(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		tb = microseconds();
		t1 = tb -ta;
		ta = microseconds();
		for(j = 0; j < k; j++){
			random_init(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		tb = microseconds();
		t2 = tb - ta;
		t = (t1 - t2)/k;
	}
	f = t / pow(n,0.9); /* underestimated bound */
	g = t / pow(n,1.1); /*tight bound*/
	h = t / pow(n,1.3); /* overestimated bound */
	TableOFValues2(n,star,t,f,g,h);
	free(v);
}

void QuickTimeA (int n, int k){
	int * v = (int *) malloc(n*sizeof(int));
	int j, star;
	float f,g,h;
	double t,t1,t2,ta,tb;
	ascending_init(v,n);
	ta = microseconds();
	quick_sort(v,n);
  tb = microseconds();
	t = tb - ta; /* Sorting time with random numbers */
	star = 0;
	if (t < 500){
		star = 1;
		ta = microseconds();
		for(j = 0; j < k; j++){
			ascending_init(v,n);
			quick_sort(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		tb = microseconds();
		t1 = tb -ta;
		ta = microseconds();
		for(j = 0; j < k; j++){
			ascending_init(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		tb = microseconds();
		t2 = tb - ta;
		t = (t1 - t2)/k;
	}
	f = t / pow(n,0.9); /* underestimated bound */
	g = t / pow(n,1.1); /*tight bound*/
	h = t / pow(n,1.3); /* overestimated bound */
	TableOFValues2(n,star,t,f,g,h);
	free(v);
}

void QuickTimeD (int n, int k){
	//int v[n];
	int * v = (int *) malloc(n*sizeof(int));
	int j,star;
	float f,g,h;
	double t,t1,t2,ta,tb;
	descending_init(v,n);
	ta = microseconds();
	quick_sort(v,n);
  tb = microseconds();
	t = tb - ta; /* Sorting time with random numbers */
	star = 0;
	if (t < 500){
		star = 1;
		ta = microseconds();
		for(j = 0; j < k; j++){
			descending_init(v,n);
			quick_sort(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		tb = microseconds();
		t1 = tb - ta;
		ta = microseconds();
		for(j = 0; j < k; j++){
			descending_init(v,n);
			 /*measure the tme of initialising an array with random values */
		}
		tb = microseconds();
		t2 = tb - ta;
		t = (t1 - t2)/k;
	}
	f = t / pow(n,0.9); /* underestimated bound */
	g = t / pow(n,1.1); /*tight bound*/
	h = t / pow(n,1.3); /* overestimated bound */
	TableOFValues2(n,star,t,f,g,h);
	free(v);
}


void QuickTime(int k){
	int i;
		printf("Quick sort with random initialisaion:\n\n");
		for(i = 500; i <= 2000000  ; i = i * 2){
				QuickTimeR(i,k);
		}
		printf("\n");
		printf("Quick sort with ascending initialisaion:\n\n");
		for(i = 500; i <= 2000000  ; i = i * 2){
				QuickTimeA(i,k);
		}
		printf("\n");
		printf("Quick sort with descending initialisaion:\n\n");
		for(i = 500; i <= 2000000  ; i = i * 2){
				QuickTimeD(i,k);
		}
		printf("\n");
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

	int testSize = 10;
	printf("\n\n");
	testInsertionSort(testSize);
	testQuickSort(testSize);

	benchmark();

}
