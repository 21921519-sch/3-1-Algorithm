#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define MAX 1000
#define MAX 200000
//#define DIGIT 6
//#define DIGIT 12
//#define DIGIT 5
#define DIGIT 10
#define BINS 10
//#define NAME_SIZE 972
//#define NAME_SIZE 956
//#define NAME_SIZE 4976
#define NAME_SIZE 4956

typedef struct node
{
	int key[DIGIT];
	char name[NAME_SIZE];
	struct node *link;
}record;

record A[MAX];
record *first, *ptr, *q;
record *radix_sort(record *);

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
		for(j=0; j<=NAME_SIZE-2; j++)
		{
			A[i].name[j] = rand()%26 + 'a';
		}
		A[i].name[j] = '\0';
	}
	first = A;
	for(i=0; i<MAX-1; i++)
	{
		A[i].link = &(A[i+1]);
	}
	A[MAX-1].link = NULL;
	/*
	for(ptr=first; ptr; ptr=ptr->link)
	{
		for(i=0; i<DIGIT; i++)
		{
			printf("%d", ptr->key[i]);
		}
		printf("(%s)", ptr->name);
		printf(" -> ");
	}
	printf("\n");
	*/
	a = clock();
	first = radix_sort(first);
	b = clock();
	/*
	for(ptr=first; ptr; ptr=ptr->link)
	{
		for(i=0; i<DIGIT; i++)
		{
			printf("%d", ptr->key[i]);
		}
		printf("(%s)", ptr->name);
		printf(" -> ");
	}
	printf("\n");
	*/
	// 정렬 검증
	for(ptr=first; ptr->link; ptr=ptr->link)
	{
		for(j=0; j<DIGIT; j++)
		{
			if(ptr->key[j] < (ptr->link)->key[j])
			{
				break;
			}
			else if(ptr->key[j] > (ptr->link)->key[j])
			{
				ptr = NULL;
				break;
			}
		}
	}
	
	if(ptr->link == NULL)
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

record *radix_sort(record *ptr)
{
	int i, j, k, digit;
	// BIN 생성
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
		for(j=BINS-1; j>=0; j--)
		{
			if(bottom[j])
			{
				up[j]->link = ptr;
				ptr = bottom[j];
			}
		}
		//printf("\n");
		/*
		for(j=0; j<BINS; j++)
		{
			printf("B[%d] : ", j);
			if(bottom[j])
			{
				for(q=bottom[j]; q != up[j]; q=q->link)
				{
					for(k=0; k<DIGIT; k++)
					{
						printf("%d", q->key[k]);
					}
					printf(" -> ");
				}
				for(k=0; k<DIGIT; k++)
				{
					printf("%d", q->key[k]);
				}
			}
			printf("\n");
		}

		for(q=ptr; q; q=q->link)
		{
			for(k=0; k<DIGIT; k++)
			{
				printf("%d", q->key[k]);
			}
			printf(" -> ");
		}
		printf("\n");
		*/
	}
	
	return ptr;
}