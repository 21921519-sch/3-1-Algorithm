#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define KEY_SIZE 10
//#define M 13
//#define M 17
//#define M 31
#define M 9973

typedef struct
{
	char key[KEY_SIZE];
}htable;

htable ht[M];
int hash(char *);
void linear_probing(char[]);
//void see();
int cnt = 0;

int main(void)
{
	int i, j, k;
	char key[10];
	for(i=0; i<M; i++)
	{
		strcpy(ht[i].key, "\0");
	}
	// 난수 발생 함수 초기화
	srand((unsigned)time(NULL));
	while(1)
	{
		for(j=0; j<(rand()%9+1); j++)
		{
			key[j] = rand()%26 + 'a';
		}
		key[j] = '\0';
		linear_probing(key);
		//see();
	}
	return 0;
}
/*
void see()
{
	int i;
	for(i=0; i<M; i++)
	{
		printf("\n[%d] : %s", i, ht[i].key);
	}
	printf("\n");
}
*/
void linear_probing(char key[])
{
	int i, hash_value;
	i = hash_value = hash(key);
	//printf("\nkey = %s, ", key);
	//printf("i = %d", i);
	while(strcmp(ht[i].key, "\0")!=0)
	{
		// 같은 키가 있으면 삽입 안함
		if(strcmp(ht[i].key, key) == 0)
		{
			return;
		}
		cnt = cnt + 1;
		i = (i+1) % M;
		if(i == hash_value)
		{
			printf("\n충돌 횟수 : %d", cnt);
			printf("\nHash Table is full\n");
			exit(1);
		}
	}
	strcpy(ht[i].key, key);
}

// 더하기 방법
/*
int hash(char A[])
{
	int i, addr = 0;
	for(i=0; A[i]!='\0'; i++)
	{
		addr = addr + A[i];
	}
	return (addr % M);
}
*/

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
