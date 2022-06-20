#include <stdio.h>
#define LINKS 12
//#define LINKS 11
#define NODES 8
//#define NODES 7
#define SWAP(x, y, t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct
{
	int node1;
	int node2;
	int cost;
}link;

link E[LINKS] =
{
	
	{1,3,6}, {1,7,2}, {3,7,3}, {1,2,10},
	{0,7,8}, {6,7,12}, {3,5,11}, {0,4,5},
	{4,6,9}, {2,4,1}, {2,5,4}, {4,5,7}
	
	/*
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
	*/
};
int P[NODES];
void quick_sort(int, int);
int cycle(int, int);
void see();

int main(void)
{
	int i, cnt = 0;
	for(i=0; i<NODES; i++)
	{
		P[i] = -1;
	}
	see();
	
	printf("\n\n초기 링크 : \n");
	for(i=0; i<LINKS; i++)
	{
		printf("%d(%d,%d) ", E[i].cost, E[i].node1, E[i].node2);
	}
	printf("\n");
	
	quick_sort(0, LINKS-1);
	
	printf("\n\n정렬된 링크 : \n");
	for(i=0; i<LINKS; i++)
	{
		printf("%d(%d,%d) ", E[i].cost, E[i].node1, E[i].node2);
	}
	printf("\n\n");
	
	// Kruskal Algorithm
	for(i=0; i<LINKS; i++)
	{
		if(cycle(E[i].node1, E[i].node2) == 1)
		{
			printf("\n%d(%d,%d) 링크 사용", E[i].cost, E[i].node1, E[i].node2);
			cnt++;
		}
		else
		{
			printf("\n\n%d(%d,%d) 링크 기각", E[i].cost, E[i].node1, E[i].node2);
		}
		if(cnt == NODES-1)
		{
			break;
		}
	}
	
	return 0;
}

void quick_sort(int left, int right)
{
	int pivot, i, j;
	link temp;
	if(left<right)
	{
		i = left;
		j = right+1;
		pivot = E[left].cost;
		do
		{
			do
			{
				i++;
			}while(E[i].cost<pivot);
			do
			{
				j--;
			}while(E[j].cost>pivot);
			if(i<j)
			{
				SWAP(E[i], E[j], temp);
			}
		}while(i<j);
		SWAP(E[left], E[j], temp);
		quick_sort(left, j-1);
		quick_sort(j+1, right);
	}
}

int cycle(int i, int j)
{
	for( ; P[i]>=0; i=P[i]);
	for( ; P[j]>=0; j=P[j]);
	if(i == j)
	{
		return 0;
	}
	if(P[i] <= P[j])
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