#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 4100000 // 최대 배열 크기
#define NAME_SIZE 996

// 1000 byte 레코드를 정의하기 위한 구조체
typedef struct
{
	int key;
	char name[NAME_SIZE];
}record;

record A[MAX_SIZE]; // 구조체 배열 선언
record B[MAX_SIZE];
int n; // 실제 사용하는 레코드의 수

void record_merge_sort(); // 레코드정렬함수 유형

void main()
{
	int count = 0; // 정렬된 레코드 출력 카운팅
	int i, j;
	clock_t a, b;
	printf("Enter the number of records to generate : ");
	scanf("%d", &n); // 실제 사용하는 레코드의 수 입력 받음
	srand((unsigned)time(NULL)); // 난수 발생 함수 초기화
	for(i=0; i<n; i++)
	{
		A[i].key = (rand()*rand())%10000; // 난수범위 0~99999
		// A[i].key = rand()%1000; // 임의의 key 값 생성 0~999

		// 임의의 995 문자 name 값 생성
		for(j=0; j<=NAME_SIZE-2; j++)
		{
			A[i].name[j] = rand()%26 + 'a'; // 정수 0~25를 문자 'a'~'z'로 변환
		}
		A[i].name[j] = '\0'; // End of String 추가로 문자열 완성
		// printf("%d(%s)\n", A[i].key, A[i].name); // n이 클 경우 주석 처리
	}
	a = clock();
	record_merge_sort(0, n-1); // 레코드 정렬 호출
	b = clock();

	// 정렬된 레코드 출력
	printf("\n\nSorted array : \n");
	/*
	for(i=0; i<n; i++) // n이 클 경우 반복문 전체 주석 처리
	{ // n이 클 경우 반복문 전체 주석 처리
		count++;
		printf("%d(%s)\n", A[i].key, A[i].name); // n이 클 경우 반복문 전체 주석 처리
	} // n이 클 경우 반복문 전체 주석 처리
	*/
	if (count == 0) // 정렬된 레코드 출력 여부 판별
	{
		printf("skip.\n");
	}
	printf("\n");

	// 정렬 검증
	for(i=0; i<n-1; i++)
	{
		if (A[i].key > A[i+1].key)
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
	printf("\n");
	printf("Execution Duration=%f\n",(double)(b-a)/CLOCKS_PER_SEC); // 실행시간 출력
}

void record_merge(int left, int mid, int right)
{
	int i, j, k, l;
	i = left; // i:정렬된 왼쪽리스트 A 인덱스
	j = mid+1; // j:정렬된 오른쪽리스트 A 인덱스
	k = left; // k:정렬될 리스트 B 인덱스
	while(i<=mid && j<=right)
	{
		if(A[i].key <= A[j].key)
		{
			B[k++].key = A[i++].key;
		}
		else
		{
			B[k++].key = A[j++].key;
		}
	}
	// 남아 있는 레코드의 일괄 복사
	if (i > mid)
	{
		for(l=j; l<=right; l++)
		{
			B[k++].key = A[l].key;
		}
	}
	else
	{
		for(l=i; l<=mid; l++)
		{
			B[k++].key = A[l].key;
		}
	}
	// 리스트 B를 리스트 A로 복사
	for(l=left; l<=right; l++)
	{
		A[l].key = B[l].key;
	}
}

void record_merge_sort(int left, int right)
{
	int mid;
	if(left < right)
	{
		mid = (left+right)/2; // 리스트의 균등분할
		record_merge_sort(left, mid); // 왼쪽 리스트 정렬
		record_merge_sort(mid+1, right); // 오른쪽 리스트 정렬
		record_merge(left, mid, right); // 두 개의 리스트 합병
	}
}