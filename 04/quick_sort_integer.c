#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE 400000000 // 최대 배열 크기

int A[MAX_SIZE];
int n; // 실제 사용하는 레코드의 수

void quick_sort(); // 정렬 유형

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
	quick_sort(0, n-1); // 정렬 호출
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

void quick_sort(int left, int right)
{
	int pivot, i, j, temp;
	//리스트에 2개 이상의 레코드가 있을 경우
	if(left<right)
	{
		i = left;
		j = right + 1;
		//피벗 설정
		pivot = A[left];
		
		do
		{
			//왼쪽에서 피벗보다 큰 레코드 선택
			do
			{
				i++;
			}while(A[i]<pivot);
			//오른쪽에서 피벗보다 작은 레코드 선택
			do
			{
				j--;
			}while(A[j]>pivot);
			if(i<j)
			{
				//선택된 두 레코드 교환
				SWAP(A[i], A[j], temp);
			}
		}while(i<j); //인덱스 i, j가 엇갈리지 않는 한 반복

		//인덱스 j 레코드와 피벗 교환
		SWAP(A[left], A[j], temp);
		//피벗을 제외한 왼쪽 부분리스트를 퀵정렬
		quick_sort(left, j-1);
		//피벗을 제외한 오른쪽 부분리스트를 퀵정렬
		quick_sort(j+1, right);
	}
}