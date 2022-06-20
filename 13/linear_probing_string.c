#include <stdio.h>
#include <string.h>
#define KEY_SIZE 10
//#define M 13
//#define M 17
#define M 31

typedef struct
{
	char key[KEY_SIZE];
}htable;

htable ht[M];
int hash(char[]);

void linear_probing(char[]);
void linear_probing_search(char[]);
void see();

int main(void)
{
	int i;
	char key[10];
	for(i=0; i<M; i++)
	{
		strcpy(ht[i].key, "\0");
	}
	see();
	
	// 해시테이블에 키 추가
	printf("\ninsert key = ");
	scanf("%s", key);
	while(strcmp(key, "-1") != 0)
	{
		linear_probing(key);
		see();
		printf("\ninsert key = ");
		scanf("%s", key);
	}
	
	// 해시테이블에서 키 탐색
	printf("\nsearch key = ");
	scanf("%s", key);
	while(strcmp(key, "-1") != 0)
	{
		linear_probing_search(key);
		printf("\nsearch key = ");
		scanf("%s", key);
	}
	
	return 0;
}

void linear_probing(char key[])
{
	int i, hash_value;
	i = hash_value = hash(key);
	printf("i=%d, ", i);
	while(strcmp(ht[i].key, "\0") != 0)
	{
		// 같은 키가 있으면 삽입 안함
		if(strcmp(ht[i].key, key) == 0)
		{
			printf("The key is already in the table at ht[%d]\n", i);
			return;
		}
		i = (i+1) % M;
		printf("i=%d, ", i);
		if(i == hash_value)
		{
			printf("\nHash Table is full\n");
			exit(1);
		}
	}
	strcpy(ht[i].key, key);
}

void linear_probing_search(char key[])
{
	int i, hash_value;
	i = hash_value = hash(key);
	printf("i=%d, ", i);
	while(strcmp(ht[i].key, "\0") != 0)
	{
		// 탐색 성공
		if(strcmp(ht[i].key, key) == 0)
		{
			printf("\nkey(%s) is found at ht[%d]\n", ht[i].key, i);
			return;
		}
		i = (i+1) % M;
		printf("i=%d, ", i);
		if(i == hash_value)
		{
			printf("\nkey(%s) is not found!\n", key);
			exit(1);
		}
	}
	printf("\nkey(%s) is not found!\n", key);
}

void see()
{
	int i;
	for(i=0; i<M; i++)
	{
		printf("\n[%d] : %s", i, ht[i].key);
	}
	printf("\n");
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