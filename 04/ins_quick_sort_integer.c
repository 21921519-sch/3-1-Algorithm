#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE 400000000 // 최대 배열 크기

int A[MAX_SIZE];
int n; // 실제 사용하는 레코드의 수
int k; // 키보드에 입력받는 전역변수

void ins_quick_sort(); // 정렬 유형

void main()
{
	int count = 0; // // 정렬된 레코드 출력 카운팅
	int i;
	clock_t a, b;
	printf("Number of Records = ");
	scanf("%d", &n); // 실제 사용하는 레코드의 수 입력 받음
	printf("k = ");
	scanf("%d", &k); // 특정 시점
	srand((unsigned)time(NULL)); // 난수 발생 함수 초기화
	for(i=0; i<n; i++) // 난수 생성 및 출력
	{
		//A[i] = rand()%100; // 난수범위 0~99
		A[i] = (rand()*rand())%100000; // 난수범위 0~9999999
		//printf("%d ", A[i]); // n이 매우 클 경우 주석 처리
	}

	// 시간 측정
	a = clock();
	ins_quick_sort(0, n-1); // 정렬 호출
	b = clock();

	// 정렬된 레코드 출력
	printf("\n\nSorted array : \n");
	/*
	for(i=0; i<n; i++) // n이 매우 클 경우 반복문 전체 주석 처리
	{ // n이 매우 클 경우 반복문 전체 주석 처리
		count++; // 정렬된 레코드 출력 카운팅
		printf("%d ", A[i]); // n이 매우 클 경우 반복문 전체 주석 처리
	} // n이 매우 클 경우 반복문 전체 주석 처리
	*/
	if (count == 0) // 정렬된 레코드 출력 여부 판별
	{
		printf("skip.\n");
	}
	printf("\n");

	// 정렬 검증
	for(i=0; i<n-1; i++)
	{
		if (A[i] > A[i+1])
		{
			break;
		}
	}
	if (i == n-1)
	{
		printf("정렬 완료!!\n");
	}
	else
	{
		printf("정렬 안됨!!\n");
	}
	printf("Execution Duration=%f\n", (double)(b-a)/CLOCKS_PER_SEC); // 실행시간 출력
}


void ins_quick_sort(int left, int right)
{
	int pivot, i, j, temp;
	if((right-left) >= k)
	{
		i = left;
		j = right+1;
		pivot = A[left];
		do
		{
			do
			{
				i++;
			}while(A[i]<pivot);
			do
			{
				j--;
			}while(A[j]>pivot);
			if(i < j)
			{
				SWAP(A[i], A[j], temp);
			}
		}while(i<j);
		SWAP(A[left], A[j], temp);
		ins_quick_sort(left, j-1);
		ins_quick_sort(j+1, right);
	}
	else
	{
		for(i=left+1; i<=right; i++)
		{
			temp = A[i];
			for(j=i-1; j>=0 && A[j]>temp; j--)
			{
				A[j+1] = A[j];
			}
			A[j+1] = temp;
		}
	}
}