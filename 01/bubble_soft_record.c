#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE 100000
#define NAME_SIZE 996

typedef struct
{
	int key;
	char name[NAME_SIZE];
}record;

record A[MAX_SIZE];
int n;
void record_bubble_sort();

void main()
{
	int count = 0;
	int i, j;
	clock_t a, b;
	printf("Enter the number of records to generate : ");
	scanf("%d", &n);
	srand((unsigned)time(NULL));
	for(i=0; i<n; i++) // A[i].key = (rand()*rand())%100000;
	{
		A[i].key = rand()%1000;
		for(j=0; j<=NAME_SIZE-2; j++)
		{
			A[i].name[j] = rand()%26 + 'a';
		}
		A[i].name[j] = '\0';
		printf("%d(%s)\n", A[i].key, A[i].name);
	}
	a = clock();
	record_bubble_sort();
	b = clock();
	printf("\n\nSorted array :\n");
	
	for(i=0; i<n; i++)
	{
		count++;
		printf("%d(%s)\n", A[i].key, A[i].name);
	}
	
	if(count == 0)
		printf("skip.\n");
	printf("\n");
	
	for(i=0; i<n-1; i++)
	{
		if(A[i].key > A[i+1].key)
			break;
	}
	if(i == n-1)
		printf("정렬 완료!!\n");
	else
		printf("정렬 안됨!!\n");
	printf("Execution Duration=%f\n",(double)(b-a)/CLOCKS_PER_SEC);
}

void record_bubble_sort()
{
	int i, j; 
	record temp;
	for(i=n-1; i>0; i--)
	{
		for(j=0; j<i; j++)
		{
			if(A[j].key>A[j+1].key) 
				SWAP(A[j], A[j+1], temp);
		}
	}
}