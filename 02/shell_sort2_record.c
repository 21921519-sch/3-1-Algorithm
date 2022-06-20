#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 2000000
#define NAME_SIZE 996

typedef struct
{
	int key;
	char name[NAME_SIZE];
}record;

record A[MAX_SIZE];
int n, m;
void record_shell_sort();

void main()
{
	int count = 0;
	int i, j;
	clock_t a, b;
	printf("Enter the number of records to generate : ");
	scanf("%d", &n);
	printf("Decrease the interval between input : ");
	scanf("%d", &m);
	srand((unsigned)time(NULL));
	for(i=0; i<n; i++) // A[i].key = (rand()*rand())%100000;
	{
		A[i].key = (rand()*rand())%100000;
		for(j=0; j<=NAME_SIZE-2; j++)
		{
			A[i].name[j] = rand()%26 + 'a';
		}
		A[i].name[j] = '\0';
		//printf("%d(%s)\n", A[i].key, A[i].name);
	}
	a = clock();
	record_shell_sort();
	b = clock();
	printf("\n\nSorted array :\n");
	/*
	for(i=0; i<n; i++)
	{
		count++;
		printf("%d(%s)\n", A[i].key, A[i].name);
	}
	*/
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

void record_shell_sort()
{
	int i, j, gap;
	record key;
	gap = n/m;
	while(gap>0)
	{
		for(i=gap; i<n; i++)
		{
			key = A[i];
			for(j=i-gap; j>=0 && A[j].key>key.key; j=j-gap)
			{
				A[j+gap].key = A[j].key;
			}
			A[j+gap].key = key.key;
		}
		if (gap!=1 && gap/m==0)
			gap = 1;
		else
			gap = gap/m;
	}
}