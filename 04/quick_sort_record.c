#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE 5000000 // 최대 배열 크기
#define NAME_SIZE 996

// 1000 byte 레코드를 정의하기 위한 구조체
typedef struct
{
	int key;
	char name[NAME_SIZE];
}record;

record A[MAX_SIZE]; // 구조체 배열 선언
int n; // 실제 사용하는 레코드의 수

void record_quick_sort(); // 레코드정렬함수 유형

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
		//printf("%d(%s)\n", A[i].key, A[i].name); // n이 클 경우 주석 처리
	}
	a = clock();
	record_quick_sort(0, n-1); // 레코드 정렬 호출
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

void record_quick_sort(int left, int right)
{
	int pivot, i, j;
	record temp;
	//리스트에 2개 이상의 레코드가 있을 경우
	if(left<right)
	{
		i = left;
		j = right + 1;
		//피벗 설정
		pivot = A[left].key;
		
		do
		{
			//왼쪽에서 피벗보다 큰 레코드 선택
			do
			{
				i++;
			}while(A[i].key<pivot);
			//오른쪽에서 피벗보다 작은 레코드 선택
			do
			{
				j--;
			}while(A[j].key>pivot);
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