#include <stdio.h>
//#define LINKS 12
#define LINKS 11
//#define NODES 8
#define NODES 7
#define SWAP(x, y, t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct
{
	int node1;
	int node2;
	int cost;
}link;

link E[LINKS+1] =
{
	/*
	{0,0,0}, {1,3,6}, {1,7,2}, {3,7,3}, {1,2,10},
	{0,7,8}, {6,7,12}, {3,5,11}, {0,4,5},
	{4,6,9}, {2,4,1}, {2,5,4}, {4,5,7}
	*/
	
	{0,0,0},
	{0,3,2},
	{1,2,3},
	{3,4,5},
	{2,5,7},
	{0,4,11},
	{2,3,13},
	{1,5,17},
	{2,4,19},
	{1,3,23},
	{5,6,29},
	{2,6,31},
	
};
int P[NODES];
void adjust(int, int);
int cycle(int, int);
void see();

int main(void)
{
	int i, cnt = 0, last = LINKS;
	link temp;
	// 부모 배열 초기화
	for(i=0; i<NODES; i++)
	{
		P[i] = -1;
	}
	see();
	
	printf("\n\n초기 링크 : \n");
	for(i=1; i<LINKS; i++)
	{
		printf("%d(%d,%d) ", E[i].cost, E[i].node1, E[i].node2);
	}
	printf("\n");
	
	// 최소히프 구축
	for(i=LINKS/2; i>0; i--)
	{
		adjust(i, LINKS);
	}

	printf("\n\n최소히프 링크 : \n");
	for(i=1; i<=LINKS; i++)
	{
		printf("%d(%d, %d) ", E[i].cost, E[i].node1, E[i].node2);
	}
	printf("\n");
	see();
	/*
	printf("\n\n정렬된 링크 : \n");
	for(i=0; i<LINKS; i++)
	{
		printf("%d(%d,%d) ", E[i].cost, E[i].node1, E[i].node2);
	}
	printf("\n\n");
	*/
	// Kruskal Algorithm
	for(i=0; i<LINKS; i++)
	{
		if(cycle(E[1].node1, E[1].node2) == 1)
		{
			printf("\n%d(%d,%d) 링크 사용", E[1].cost, E[1].node1, E[1].node2);
			cnt++;
		}
		else
		{
			printf("\n\n%d(%d,%d) 링크 기각", E[1].cost, E[1].node1, E[1].node2);
		}
		SWAP(E[1], E[last], temp);
		last--;
		adjust(1, last);

		if(cnt == NODES-1)
		{
			break;
		}
	}
	printf("\n");
	
	return 0;
}

void adjust(int root, int n)
{
	int child;
	link temp;
	temp = E[root];
	child = 2*root;
	while(child<=n)
	{
		// 자식 노드 중 작은 쪽 선택
		if(child<n && E[child].cost>E[child+1].cost)
		{
			child++;
		}
		
		if(temp.cost < E[child].cost)
		{
			break;
		}
		else
		{
			E[child/2] = E[child];
		}
		child = child*2;
	}
	E[child/2] = temp;
}

int cycle(int i, int j)
{
	for( ; P[i]>=0; i=P[i]);
	for( ; P[j]>=0; j=P[j]);
	if (i == j)
	{
		return 0;
	}
	if (P[i] <= P[j])
	{
		P[i] = P[i] + P[j];
		P[j] = i;
	}
	else
	{
		P[j] = P[i] + P[j];
		P[i] = j;
	}
	see();
	
	return 1;
}

void see()
{
	int i;
	printf("\n부모 배열 : ");
	for(i=0; i<NODES; i++)
	{
		printf("%3d ", P[i]);
	}
}