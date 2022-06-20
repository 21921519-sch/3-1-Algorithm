#include <stdio.h>
#include <stdlib.h>
//#define M 7
#define M 13

int ht[M];
int hash(int);

void linear_probing(int);
void linear_probing_search(int);
void see();

int main(void)
{
	int i, key;
	for(i=0; i<M; i++)
	{
		ht[i] = -1;
	}
	see();
	
	// 해시테이블에 키 추가
	printf("\ninsert key = ");
	scanf("%d", &key);
	while(key >= 0)
	{
		linear_probing(key);
		see();
		printf("\ninsert key = ");
		scanf("%d", &key);
	}
	
	// 해시테이블에서 키 탐색
	printf("\nsearch key = ");
	scanf("%d", &key);
	while(key >= 0)
	{
		linear_probing_search(key);
		printf("\nsearch key = ");
		scanf("%d", &key);
	}
	
	return 0;
}

int hash(int key)
{
	return key % M;
}

void linear_probing(int key)
{
	int i, hash_value;
	i = hash_value = hash(key);
	printf("i=%d, ", i);
	while(ht[i] >= 0)
	{
		// 같은 키가 있으면 삽입 안함
		if(ht[i] == key)
		{
			printf("The key is already in the table at ht[%d]\n", i);
			return;
		}
		i = (i+1) % M;
		printf("i=%d ", i);
		if(i == hash_value)
		{
			printf("The table is full\n");
			exit(1);
		}
	}
	ht[i] = key;
}

void linear_probing_search(int key)
{
	int i, hash_value;
	i = hash_value = hash(key);
	printf("i=%d, ", i);
	while(ht[i] >= 0)
	{
		// 탐색 성공
		if(ht[i] == key)
		{
			printf("\nkey(%d) is found at ht[%d]\n", ht[i], i);
			return;
		}
		i = (i+1) % M;
		printf("i=%d ", i);
		if(i == hash_value)
		{
			printf("\nkey(%d) is not found!\n", key);
			exit(1);
		}
	}
	printf("\nkey(%d) is not found!\n", key);
}

void see()
{
	int i;
	for(i=0; i<M; i++)
	{
		printf("\n[%d] : %2d ", i, ht[i]);
	}
	printf("\n");
}