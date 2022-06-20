#include <stdio.h>
#include <malloc.h>
//#define MAX 5
#define MAX 6
#define S 3

int M[MAX][MAX] =
{
	/*
	{0,1,1,0,0},
	{1,0,1,0,0},
	{1,0,0,1,1},
	{1,0,1,0,1},
	{1,1,1,1,0}
	*/
	
	{0,1,1,1,0,1},
	{0,0,1,0,0,0},
	{0,1,0,1,1,0},
	{0,0,0,0,1,1},
	{0,0,1,0,0,0},
	{1,0,0,1,0,0}
	
};

typedef struct node
{
	int data;
	struct node *link;
}list;
list *H[MAX];
int visited[MAX];
void dfs_mat(int v);
void dfs_list(int v);

int main()
{
	int i, j;
	list *temp, *ptr;
	for(i=0; i<MAX; i++)
	{
		H[i] = NULL;
	}
	for(i=0; i<MAX; i++)
	{
		for(j=MAX-1; j>=0; j--)
		{
			if(M[i][j] == 1)
			{
				temp = (list*)malloc(sizeof(list));
				temp->link = H[i];
				temp->data = j;
				H[i] = temp;
			}
		}
	}
	// 인접행렬 출력
	for(i=0; i<MAX; i++)
	{
		printf("\n");
		for(j=0; j<MAX; j++)
		{
			printf("%d", M[i][j]);
		}
	}
	printf("\n\n");
	
	// 인접리스트 출력
	for(i=0; i<MAX; i++)
	{
		printf("%d : ", i);
		ptr = H[i];
		while(ptr)
		{
			printf("%d->", ptr->data);
			ptr = ptr->link;
		}
		printf("\n");
	}
	
	printf("\n");
	for(i=0; i<MAX; i++)
	{
		visited[i]=0;
	}
	printf("\n");
	printf("===== dfs 인접행렬 =====\n");
	dfs_mat(S);
	return 0;
}

void dfs_mat(int v)
{
	int w;
	visited[v] = 1;
	printf("[노드 %d 방문]", v);
	for(w=0; w<MAX; w++)
	{
		printf("(%d, %d)", v, w);
		if(M[v][w] && !visited[w])
		{
			printf("CALL(%d)\n", w);
			dfs_mat(w);
		}
	}
	printf("BACK\n");
}