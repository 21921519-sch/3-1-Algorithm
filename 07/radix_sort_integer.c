#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
// 레코드 수
#define MAX 10
// 기수 자릿수
#define DIGIT 3
// 상자(bin) 수 (버켓 수)
#define BINS 10

typedef struct
{
	int key[DIGIT];
}record;
record A[MAX];
// BIN(버켓)
record B[BINS][MAX];
// 각 BIN의 카운터
int C[BINS];

// 배열 기수정렬
void radix_sort();
int main()
{
	int i, j;
	clock_t a, b;
	srand((unsigned)time(NULL));
	for(i=0; i<MAX; i++)
	{
		for(j=0; j<DIGIT; j++)
		{
			A[i].key[j] = rand()%10;
		}
	}
	
	for(i=0; i<MAX; i++)
	{
		for(j=0; j<DIGIT; j++)
		{
			printf("%d", A[i].key[j]);
		}
		printf("\t");
	};
	
	printf("\n");
	
	a = clock();
	radix_sort();
	b = clock();
	
	printf("\n정렬 결과\n");
	for(i=0; i<MAX; i++)
	{
		for(j=0; j<DIGIT; j++)
		{
			printf("%d", A[i].key[j]);
		}
		printf("\t");
	}
	printf("\n");
	
	for(i=0; i<MAX-1; i++)
	{
		for(j=0; j<DIGIT; j++)
		{
			if(A[i].key[j] < A[i+1].key[j])
			{
				break;
			}
			else if(A[i].key[j] > A[i+1].key[j])
			{
				i = MAX;
				break;
			}
		}
	}
	
	if(i == MAX-1)
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

void radix_sort()
{
	int i, j, k, l, digit;
	for(i=DIGIT-1; i>=0; i--)
	{
		for(j=0; j<BINS; j++)
		{
			C[j] = 0;
		}
		for(j=0; j<MAX; j++)
		{
			digit = A[j].key[i];
			B[digit][C[digit]] = A[j];
			C[digit]++;
		}
		l = 0;
		for(j=0; j<BINS; j++)
		{
			for(k=0; k<C[j]; k++)
			{
				A[l++] = B[j][k];
			}
		}
		printf("\n");
		
		for(j=0; j<BINS; j++)
		{
			printf("[%d]", j);
			for(k=0; k<C[j]; k++)
			{
				for(l=0; l<DIGIT; l++)
				{
					printf("%d", B[j][k].key[l]);
				}
				printf(" ");
			}
			printf("\n");
		}
		
		printf("\n");
		for(j=0; j<MAX; j++)
		{
			for(k=0; k<DIGIT; k++)
			{
				printf("%d", A[j].key[k]);
			}
			printf(" ");
		}
		printf("\n");
		
	}
}