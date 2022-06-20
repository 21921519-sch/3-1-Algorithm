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

typedef struct node1
{
	int data;
	struct node1 *link;
}qlist;
qlist *F, *R;
void bfs_mat(int);
void bfs_list(int);
int delQ();
void addQ(int);
void see();

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
	
	for(i=0; i<MAX; i++)
	{
		visited[i] = 0;
	}
	printf("\n");
	printf("===== bfs 인접행렬 =====");
	bfs_mat(S);
	return 0;
}

void bfs_mat(int v)
{
	int w;
	F=NULL;
	R=NULL;
	visited[v]=1;
	printf("\n");
	printf("[노드 %d 방문]", v);
	addQ(v);
	see();
	while(F)
	{
		v=delQ();
		see();
		for(w=0; w<MAX; w++)
		{
			if(M[v][w] && !visited[w])
			{
				visited[w] = 1;
				printf("[노드 %d 방문]", w);
				addQ(w);
				see();
			}
		}
	}
}

void addQ(int data)
{
	qlist *temp;
	temp = (qlist *)malloc(sizeof(qlist));
	temp->data = data;
	temp->link = NULL;
	if (!F)
	{
		F = temp;
	}
	else
	{
		R->link = temp;
	}
	R = temp;
}
int delQ()
{
	int data;
	qlist *temp;
	if (!F)
	{
		printf("\nQueue Empty Error!!\n");
	}
	data = F->data;
	temp = F;
	F = F->link;
	free(temp);
	return data;
}
void see()
{
	qlist *ptr;
	printf("\nQueue : ");
	for(ptr=F; ptr; ptr=ptr->link)
	{
		printf("%d -> ", ptr->data);
	}
}