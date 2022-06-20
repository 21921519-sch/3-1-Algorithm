#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE 2000000 // 최대 배열 크기
#define DIGIT 3
#define NAME_SIZE 988

// 1000 byte 레코드를 정의하기 위한 구조체
typedef struct
{
	int key[DIGIT];
	char name[NAME_SIZE];
}record;

record A[MAX_SIZE+4]; // 구조체 배열 선언
int n; // 실제 사용하는 레코드의 수

int record_quick_sort(); // 레코드정렬함수 유형

int main()
{
	int i, j;
	clock_t a, b;
	printf("Enter the number of records to generate : ");
	scanf("%d", &n); // 실제 사용하는 레코드의 수 입력 받음
	srand((unsigned)time(NULL)); // 난수 발생 함수 초기화
	
	printf("\n");
	for(i=0; i<MAX_SIZE; i++)
	{
		for(j=0; j<DIGIT; j++)
		{
			A[i].key[j] = rand()%10;
		}
	}
	
	for(i=0; i<MAX_SIZE; i++)
	{
		for(j=0; j<DIGIT; j++)
		{
			printf("%d", A[i].key[j]);
		}
		printf("\t");
	};
	
	a = clock();
	record_quick_sort(0, n-1); // 레코드 정렬 호출
	b = clock();
	
	printf("\n정렬 결과\n");
	for(i=0; i<MAX_SIZE; i++)
	{
		for(j=0; j<DIGIT; j++)
		{
			printf("%d", A[i].key[j]);
		}
		printf("\t");
	}
	printf("\n");
	
	// 정렬 검증
	for(i=0; i<MAX_SIZE-1; i++)
	{
		for(j=0; j<DIGIT; j++)
		{
			if(A[i].key[j] < A[i+1].key[j])
			{
				break;
			}
			else if(A[i].key[j] > A[i+1].key[j])
			{
				i = MAX_SIZE;
				break;
			}
		}
	}
	
	if(i == MAX_SIZE-1)
	{
		printf("정렬 완료!!\n");
	}
	else
	{
		printf("정렬 안됨!!\n");
	}
	// 실행시간 출력
	printf("Execution Duration=%f\n", (double)(b-a)/CLOCKS_PER_SEC);
	return 0;
}

int record_quick_sort(int left, int right)
{
	int i, j, pivot;
	record temp;
	//리스트에 2개 이상의 레코드가 있을 경우
	if(left<right)
	{
		i = left;
		j = right + 1;
		//피벗 설정
		//pivot = A[left].key;
		
		do
		{
			//왼쪽에서 피벗보다 큰 레코드 선택
			do
			{
				i++;
			}while(A[i].key<A[left].key);
			//오른쪽에서 피벗보다 작은 레코드 선택
			do
			{
				j--;
			}while(A[j].key>A[left].key);
			if(i<j)
			{
				//선택된 두 레코드 교환
				SWAP(A[i], A[j], temp);
			}
		}while(i<j); //인덱스 i, j가 엇갈리지 않는 한 반복

		//인덱스 j 레코드와 피벗 교환
		SWAP(A[left], A[j], temp);
		//피벗을 제외한 왼쪽 부분리스트를 퀵정렬
		record_quick_sort(left, j-1);
		//피벗을 제외한 오른쪽 부분리스트를 퀵정렬
		record_quick_sort(j+1, right);
	}
}