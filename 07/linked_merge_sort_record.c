#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_SIZE 410000
//#define DIGIT 6
//#define DIGIT 12
//#define DIGIT 5
#define DIGIT 10
//#define NAME_SIZE 972
//#define NAME_SIZE 956
//#define NAME_SIZE 4976
#define NAME_SIZE 4956

typedef struct
{
	char key[DIGIT+1];
	char name[NAME_SIZE];
	int link;
}record;
record A[MAX_SIZE+1];

int n;
int merge_sort(int, int);
int merge(int, int);

int main()
{
	int i, j, start;
	clock_t a, b;
	printf("Enter the number of records to generate : ");
	scanf("%d", &n);
	srand((unsigned)time(NULL));
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<DIGIT; j++)
		{
			A[i].key[j] = rand()%10 + '0';
		}
		A[i].key[j] = '\0';
		for(j=0; j<=NAME_SIZE-2; j++)
		{
			A[i].name[j] = rand()%26 + 'a';
		}
		A[i].name[j] = '\0';
		A[i].link = -1;
		//printf("[%s(%s)%d]\n", A[i].key, A[i].name, A[i].link);
	}
	
	a = clock();
	start = merge_sort(0, n-1);
	b = clock();
	
	/*
	printf("\n\nSorted Array :\n");
	for(i=0; i<n; i++)
	{
		printf("[%s(%s)%d]\n", A[i].key, A[i].name, A[i].link);
	}
	printf("\n");
	printf("\n\nSorted Linked List :\n");
	for(i=start; i!=1; i=A[i].link)
	{
		printf("[%s(%s)] -> ", A[i].key, A[i].name);
	}
	printf("\n");
	*/
	// strcmb(a, b) : a>b이면 양수, a=b이면 0, a<b이면 음수 반환
	for(i=start; A[i].link!=-1; i=A[i].link)
	{
		if(strcmp(A[i].key, A[A[i].link].key) > 0)
		{
			break;
		}
	}
	
	if(A[i].link == -1)
	{
		printf("정렬 완료!!\n");
	}
	else
	{
		printf("정렬 안됨!!\n");
	}
	printf("\n");
	
	// 실행시간 출력
	printf("Execution Duration=%f\n", (double)(b-a)/CLOCKS_PER_SEC);
	return 0;
}

int merge_sort(int left, int right)
{
	int i, j, k, mid;
	if(left < right)
	{
		mid = (left + right)/2;
		i = merge_sort(left, mid);
		j = merge_sort(mid+1, right);
		k = merge(i, j);
		return k;
	}
	else
	{
		return left;
	}
}

// 인덱스 i와 j가 가리키는 리스트를 합병한 후,
// 합병된 리스트의 첫 번째 레코드 인덱스 반환
int merge(int i, int j)
{
	int k = n;
	while(i != -1 && j != -1)
	{
		if(strcmp(A[i].key, A[j].key) <= 0)
		{
			
			A[k].link = i;
			k = i;
			i = A[i].link;
		}
		else
		{
			A[k].link = j;
			k = j;
			j = A[j].link;
		}
	}
	if(i == -1)
	{
		A[k].link = j;
	}
	else
	{
		A[k].link = i;
	}
	
	return A[n].link;
}