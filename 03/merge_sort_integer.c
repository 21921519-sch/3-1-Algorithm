#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 200000000 // 최대 배열 크기

int A[MAX_SIZE];
int B[MAX_SIZE];
int n; // 실제 사용하는 레코드의 수

void merge_sort(); // 정렬 유형

void main()
{
	int count = 0; // // 정렬된 레코드 출력 카운팅
	int i;
	clock_t a, b;
	printf("Number of Records = ");
	scanf("%d", &n); // 실제 사용하는 레코드의 수 입력 받음
	srand((unsigned)time(NULL)); // 난수 발생 함수 초기화
	for(i=0; i<n; i++) // 난수 생성 및 출력
	{
		//A[i] = rand()%100; // 난수범위 0~99
		A[i] = (rand()*rand())%10000; // 난수범위 0~9999999
		//printf("%d ", A[i]); // n이 매우 클 경우 주석 처리
	}

	// 시간 측정
	a = clock();
	merge_sort(0, n-1); // 정렬 호출
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

void merge(int left, int mid, int right)
{
	int i, j, k, l;
	i = left; // i:정렬된 왼쪽리스트 A 인덱스
	j = mid+1; // j:정렬된 오른쪽리스트 A 인덱스
	k = left; // k:정렬될 리스트 B 인덱스
	while(i<=mid && j<=right)
	{
		if(A[i] <= A[j])
		{
			B[k++] = A[i++];
		}
		else
		{
			B[k++] = A[j++];
		}
	}
	// 남아 있는 레코드의 일괄 복사
	if (i > mid)
	{
		for(l=j; l<=right; l++)
		{
			B[k++] = A[l];
		}
	}
	else
	{
		for(l=i; l<=mid; l++)
		{
			B[k++] = A[l];
		}
	}
	// 리스트 B를 리스트 A로 복사
	for(l=left; l<=right; l++)
	{
		A[l] = B[l];
	}
}

void merge_sort(int left, int right)
{
	int mid;
	if(left < right)
	{
		mid = (left+right)/2; // 리스트의 균등분할
		merge_sort(left, mid); // 왼쪽 리스트 정렬
		merge_sort(mid+1, right); // 오른쪽 리스트 정렬
		merge(left, mid, right); // 두 개의 리스트 합병
	}
}