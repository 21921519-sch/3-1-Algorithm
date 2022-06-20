#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define KEY_SIZE 10
#define M 9973
#define N 50000

typedef struct node
{
	char key[KEY_SIZE];
	struct node *link;
}list;

list *ht[M];
void insert(list **, char[]);
int hash(char[]);
int k = 0;

int main(void)
{
	int i, j, cnt=0, len;
	float ave, sum=0.0;
	list *p;
	char key[10];
	
	for(i=0; i<M; i++)
	{
		ht[i] = NULL;
	}
	
	// 난수 발생 함수 초기화
	srand((unsigned)time(NULL));
	while(k<N)
	{
		for(j=0; j<(rand()%9+1); j++)
		{
			key[j] = rand()%26 + 'a';
		}
		key[j] = '\0';
		i = hash(key);
		insert(&ht[i], key);
	}
	
	ave = (float)N/(float)M;
	for(i=0; i<M; i++)
	{
		len = 0;
		for(p=ht[i]; p; p=p->link)
		{
			len++;
		}
		sum = sum + ((float)len-ave) * ((float)len-ave);
		cnt = cnt + len;
	}
	
	printf("데이터 = %d\n", cnt);
	printf("편차제곱합 = %f\n", sum);
	printf("평균 = %f\n", ave);
	printf("분산 = %f\n", sum/(float)M);
	printf("표준편차 = %f\n", sqrt(sum/(float)M));
	return 0;
}

void insert(list **p, char key[])
{
	list *temp;
	for( ; *p; p=&((*p)->link))
	{
		// 같은 키가 있으면 삽입 안함
		if(strcmp((*p)->key, key) == 0)
		{
			return;
		}
		if(strcmp((*p)->key, key) > 0)
		{
			break;
		}
	}
	temp = (list *)malloc(sizeof(list));
	strcpy(temp->key, key);
	temp->link = *p;
	(*p) = temp;
	k++;
}

int hash(char A[])
{
	int i, addr = 0;
	for(i=0; A[i]!='\0'; i++)
	{
		addr = addr + A[i];
	}
	return (addr % M);
}
/*
// 호너의 방법
int hash(char A[])
{
	int i, addr = 0;
	for(i=0; A[i]!='\0'; i++)
	{
		addr = 31 * addr + A[i];
	}
	if(addr < 0)
	{
		addr = -addr;
	}
	return (addr % M);
}
*/
double sqrt(double input)
{
    double x = 2;

    for (int i = 0; i < 10; i++)
    {
        x = (x + (input / x)) / 2;
    }

    return x;
}