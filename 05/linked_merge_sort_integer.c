#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 60000000 // 최대 배열 크기
#define NAME_SIZE 992

// 레코드를 정의하기 위한 구조체
typedef struct
{
	int key;
	int link;
}record;

// 구조체 배열 선언
record A[MAX_SIZE+1];
// 실제 레코드 수
int n;
// 합병 정렬
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
		A[i].key = rand()%100;
		A[i].link = -1;
		//printf("[%d, %d]", A[i].key, A[i].link);
	}
	
	a = clock();
	start = merge_sort(0, n-1);
	b = clock();
	
	printf("\n\nSorted Array : \n");
	/*
	for(i=0; i<n; i++)
	{
		printf("[%d, %d]", A[i].key, A[i].link);
	}
	printf("\n");
	*/
	
	printf("\nSorted Linked List : \n");
	for(i=start; i!=-1; i=A[i].link)
	{
		if(A[i].key > A[A[i].link].key)
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
	printf("Execution Duration=%f\n", (double)(b-a)/CLOCKS_PER_SEC);
	return 0;
}

int merge_sort(int left, int right)
{
	int i, j, k, mid;
	if(left < right)
	{
		mid = (left+right)/2;
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

// 인덱스 k는 항상 앞으로 갱신될 link를 가진 레코드를 가리킴
int merge(int i, int j)
{
	// n번째 노드를 수정될 노드로 지정
	int k = n;
	// 한 리스트라도 소진되면 반복 종료
	while(i != -1 && j != -1)
	{
		if(A[i].key <= A[j].key)
		{
			// i가 가리키는 레코드를 k가 가리키는 레코드에 연결
			A[k].link = i;
			// k는 최근 연결된 레코드를 가리킴
			k = i;
			// 인덱스가 링크를 따라가 다음 레코드를 가리킴
			i = A[i].link;
		}
		else
		{
			// j가 가리키는 레코드를 k가 가리키는 레코드에 연결
			A[k].link = j;
			// k는 최근 연결된 레코드를 가리킴
			k = j;
			// 인덱스가 링크를 따라가 다음 레코드를 가리킴
			j = A[j].link;
		}
	}
	// 나머지 리스트의 연결
	if(i == -1)
	{
		A[k].link = j;
	}
	else
	{
		A[k].link = i;
	}
	
	// 합병된 리스트의 첫 레코드 인덱스 반환
	return A[n].link;
}