#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE 6000000
#define NAME_SIZE 996

typedef struct
{
	int key;
	char name[NAME_SIZE];
}record;

record A[MAX_SIZE];
int n;
void heap_sort();
void heap_print();

int main()
{
	int i, j;
	clock_t a, b;
	printf("Enter the number of records to generate : ");
	scanf("%d", &n);
	srand((unsigned)time(NULL));
	for(i=1; i<=n; i++)
	{
		//A[i] = rand()%100;
		A[i].key = (rand()*rand())%10000;
		
		for(j=1; j<=NAME_SIZE-1; j++)
		{
			A[i].name[j] = rand()%26 + 'a'; // 정수 0~25를 문자 'a'~'z'로 변환
		}
		A[i].name[j] = '\0'; // End of String 추가로 문자열 완성
		//printf("%5d", A[i]);
	}
	printf("\n");
	
	//heap_print();
	a = clock();
	heap_sort();
	b = clock();
	
	printf("\n\nSorted array : \n");
	/*
	for(i=1; i<=n; i++)
	{
		printf("%5d(%s)\n", A[i].key, A[i].name);
	}
	*/
	printf("\n");
	
	for(i=1; i<n; i++)
	{
		if(A[i].key < A[i+1].key)
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
	int child;
	record temp;
	// 기준노드 값 저장
	temp = A[root];
	// 왼쪽 자식노드
	child = 2*root;
	while(child<=n)
	{
		if(child<n && A[child].key>A[child+1].key)
		{
			child++;
		}
		if(temp.key < A[child].key)
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
	int i;
	record temp;
	printf("\nHeap Build\n");
	for(i=n/2; i>0; i--)
	{
		adjust(i, n);
		//heap_print();
	}
	printf("\nHeap Sort\n");
	for(i=n-1; i>0; i--)
	{
		SWAP(A[1], A[i+1], temp);
		adjust(1, i);
		//heap_print();
	}
}
/*
void heap_print()
{
	printf("          %d\n", A[1]);
	printf("     %d          %d\n", A[2], A[3]); 
	printf("  %d    %d    %d    %d\n", A[4], A[5], A[6], A[7]);
	printf("%d   %d     %d\n", A[8], A[9], A[10]);
}
*/