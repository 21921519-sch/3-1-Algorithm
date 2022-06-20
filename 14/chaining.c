#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_SIZE 10
#define M 13
//#define M 9973

typedef struct node
{
	char key[KEY_SIZE];
	struct node *link;
}list;
list *ht[M];

void insert(list **, char[]);
void search(list *, char[]);
void see();
int hash(char[]);

int main(void)
{
	int i;
	char key[KEY_SIZE];
	for(i=0; i<M; i++)
	{
		ht[i] = NULL;
	}
	see();
	
	// 해시테이블에 키 추가
	printf("\ninsert key = ");
	scanf("%s", key);
	while(strcmp(key, "-1") != 0)
	{
		i = hash(key);
		printf("i=%d\n", i);
		insert(&ht[i], key);
		see();
		printf("\ninsert key = ");
		scanf("%s", key);
	}
	
	// 해시테이블에 키 탐색
	printf("\nsearch key = ");
	scanf("%s", key);
	while(strcmp(key, "-1") != 0)
	{
		i = hash(key);
		printf("i=%d\n", i);
		search(ht[i], key);
		printf("\nsearch key = ");
		scanf("%s", key);
	}
	return 0;
}

void insert(list **p, char key[])
{
	list *temp;
	for( ; *p; p=&((*p)->link))
	{
		// 키 존재하면 저장된 항목 삭제
		if(strcmp((*p)->key, key) == 0)
		{
			temp = (*p);
			*p = temp->link;
			free(temp);
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
}

void search(list *p, char key[])
{
	list *temp;
	for( ; p; p=p->link)
	{
		if(strcmp(p->key, key) >= 0)
		{
			break;
		}
	}
	// 탐색 실패
	if(p == NULL)
	{
		printf("key(%s) is not found!\n", key);
	}
	// 탐색 성공
	else if(strcmp(p->key, key) == 0)
	{
		printf("key(%s) is found\n", p->key);
	}
	// 탐색 실패
	else
	{
		printf("key(%s) is not found\n", key);
	}
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

void see()
{
	list *p;
	int i;
	for(i=0; i<M; i++)
	{
		printf("ht[%d] : ", i);
		for(p=ht[i]; p; p=p->link)
		{
			printf(" -> %s", p->key);
		}
		printf("\n");
	}
}