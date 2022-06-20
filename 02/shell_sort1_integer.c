#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100000000

double A[MAX_SIZE];
int n, m;
void shell_sort();
int gap;

void main()
{
	int count = 0;
	int i;
	clock_t a, b;
	printf("Number of Records = ");
	scanf("%d", &n);
	printf("Decrease the interval between input : ");
	scanf("%d", &m);
	srand((unsigned)time(NULL));
	for(i=0; i<n; i++)
	{
		//A[i] = rand()%100;
		A[i] = (rand()*rand())%100000;
		//printf("%d ", A[i]);
	}
	a = clock();
	shell_sort();
	b = clock();
	printf("\n\nSorted array :\n");
	/*
	for(i=0; i<n; i++)
	{
		count++;
		printf("%d ", A[i]);
	}
	*/
	if(count == 0)
		printf("skip.\n");
	printf("\n");
	
	for(i=0; i<n-1; i++)
	{
		if(A[i] > A[i+1])
			break;
	}
	if(i == n-1)
		printf("정렬 완료!!\n");
	else
		printf("정렬 안됨!!\n");
	printf("Execution Duration=%f\n",(double)(b-a)/CLOCKS_PER_SEC);
}

void inc_insertion_soft(int first, int last, int gap)
{
	int i, j, key;
	for(i=first+gap; i<=last; i=i+gap)
	{
		key = A[i];
		for(j=i-gap; j>=first && key<A[j]; j=j-gap)
			A[j+gap] = A[j];
		A[j+gap] = key;
	}
}

void shell_sort()
{
	//int i, gap;
	int i, k, gap;
	for(gap=n/m; gap>0; gap=gap/m)
	{
		for(int k=0; k<gap; k++)
			inc_insertion_soft(k, n-1, gap);
	}
}