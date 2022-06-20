#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE 10000000

int A[MAX_SIZE];
int n;
void bubble_sort();

void main()
{
	int count = 0;
	int i;
	clock_t a, b;
	printf("Number of Records = ");
	scanf("%d", &n);
	srand((unsigned)time(NULL));
	for(i=0; i<n; i++)
	{
		A[i] = rand()%100;
		// A[i] = (rand()*rand())%10000000;
		//printf("%d ", A[i]);
	}
	a = clock();
	bubble_sort();
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

void bubble_sort()
{
	int i, j, temp;
	for(i=n-1; i>0; i--)
	{
		for(j=0; j<i; j++)
		{
			if(A[j]>A[j+1]) 
				SWAP(A[j], A[j+1], temp);
		}
	}
}