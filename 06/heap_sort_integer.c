#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE 600000001

int A[MAX_SIZE];
int n;
void heap_sort();
void heap_print();

int main()
{
	int i;
	clock_t a, b;
	printf("Enter the number of records to generate : ");
	scanf("%d", &n);
	srand((unsigned)time(NULL));
	for(i=1; i<=n; i++)
	{
		A[i] = rand()%100;
		//A[i] = (rand()*rand())%10000;
		printf("%5d", A[i]);
	}
	printf("\n");
	
	heap_print();
	a = clock();
	heap_sort();
	b = clock();
	
	printf("\n\nSorted array : \n");
	
	for(i=1; i<=n; i++)
	{
		printf("%5d", A[i]);
	}
	
	printf("\n");
	
	for(i=1; i<n; i++)
	{
		if(A[i] < A[i+1])
		{
			break;
		}
	}
	if(i == n)
	{
		printf("정렬 완료!!\n");
	}
	else
	{
		printf("정렬 안됨!!\n");
	}
	printf("\n");
	printf("Execution Duration=%f\n", (double)(b-a)/CLOCKS_PER_SEC);
	return 0;
}

void adjust(int root, int n) // root=기준노드, n=마지막노드
{
	int child, temp;
	// 기준노드 값 저장
	temp = A[root];
	// 왼쪽 자식노드
	child = 2*root;
	while(child<=n)
	{
		if(child<n && A[child]>A[child+1])
		{
			child++;
		}
		if(temp<A[child])
		{
			break;
		}
		else
		{
			A[child/2] = A[child];
		}
		child = child*2;
	}
	A[child/2] = temp;
}

void heap_sort()
{
	int i, temp;
	printf("\nHeap Build\n");
	for(i=n/2; i>0; i--)
	{
		adjust(i, n);
		heap_print();
	}
	printf("\nHeap Sort\n");
	for(i=n-1; i>0; i--)
	{
		SWAP(A[1], A[i+1], temp);
		adjust(1, i);
		heap_print();
	}
}

void heap_print()
{
	printf("          %d\n", A[1]);
	printf("     %d          %d\n", A[2], A[3]); 
	printf("  %d    %d    %d    %d\n", A[4], A[5], A[6], A[7]);
	printf("%d %d %d\n", A[8], A[9], A[10]);
}