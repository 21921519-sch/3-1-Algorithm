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

typedef struct node
{
	int key[DIGIT];
	struct node *link;
}record;
record A[MAX];
record *first;
record *radix_sort(record *);

int main()
{
	int i, j;
	record *ptr;
	for(i=0; i<MAX; i++)
	{
		for(j=0; j<DIGIT; j++)
		{
			A[i].key[j] = rand()%10;
		}
	}
	first = A;
	for(i=0; i<MAX-1; i++)
	{
		A[i].link = &(A[i+1]);
	}
	A[MAX-1].link = NULL;
	first = radix_sort(first);
	
	
	
	
	/*
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
	}
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
	*/
}

record *radix_sort(record *ptr)
{
	int i, j, digit;
	record *bottom[BINS], *up[BINS];
	for(i=DIGIT-1; i>=0; i--)
	{
		for(j=0; j<BINS; j++)
		{
			bottom[j] = NULL;
			up[j] = NULL;
		}
		while(ptr)
		{
			digit = ptr->key[i];
			if(!bottom[digit])
			{
				bottom[digit] = ptr;
			}
			else
			{
				up[digit]->link = ptr;
			}
			up[digit] = ptr;
			ptr = ptr->link;
		}
		
		ptr = NULL;
		for(i=BINS-1; j>=0; j--)
		{
			if(bottom[j])
			{
				up[j]->link = ptr;
				ptr = bottom[j];
			}
		}
	}
	return ptr;
}




/*
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
		i = 0;
		for(j=0; j<BINS; j++)
		{
			for(k=0; k<C[j]; k++)
			{
				A[i++] = B[j][k];
			}
		}
		printf("\n");
		for(j=0; j<BINS; j++)
		{
			printf("[%d]", j);
			for(k=0; k<C[j]; k++)
			{
				for(i=0; i<DIGIT; i++)
				{
					printf("%d", B[j][k].key[l]);
				}
				printf(" ");
			}
			printf("\n";)
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
*/