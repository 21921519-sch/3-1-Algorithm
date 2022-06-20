#include <stdio.h>
#include <stdlib.h>
//#define NODES 8
#define NODES 7
#define IF 100
#define INF 200

int lowcost[NODES];
int closest[NODES];
int C[NODES][NODES] =
{
	/*
	{IF, IF, IF, IF, 5, IF, IF, 8},
	{IF, IF, 10, 6, IF, IF, IF, 2},
	{IF, 10, IF, IF, 1, 4, IF, IF},
	{IF, 6, IF, IF, IF, 11, IF, 2},
	{5, IF, 1, IF, IF, 7, 9, IF},
	{IF, IF, 4, 11, 7, IF, IF, IF},
	{IF, IF, IF, IF, 9, IF, IF, 12},
	{8, 2, IF, 3, IF, IF, 12, IF}
	*/
	
	{IF, IF, IF, 2, 11, IF, IF},
	{IF, IF, 3, 23, IF, 17, IF},
	{IF, 3, IF, 13, 19, 7, 31},
	{2, 23, 13, IF, 5, IF, IF},
	{11, IF, 19, 5, IF, IF, IF},
	{IF, 17, 7, IF, IF, IF, 29},
	{IF, IF, 31, IF, IF, 29, IF}
	
};

void prim_alg();
void see();

int main(void)
{
	int i, j;
	for(i=0; i<NODES; i++)
	{
		for(j=0; j<NODES; j++)
		{
			printf("%3d ", C[i][j]);
		}
		printf("\n");
	}
	prim_alg();
	printf("\n");
	return 0;
}

void see()
{
	int i;
	printf("\nlowcost : ");
	for(i=0; i<NODES; i++)
	{
		printf("%3d ", lowcost[i]);
	}
	printf("\nclosest : ");
	for(i=0; i<NODES; i++)
	{
		printf("%3d ", closest[i]);
	}
}

// 시작노드 0
void prim_alg()
{
	int i, j, k, min;
	for(i=0; i<NODES; i++)
	{
		lowcost[i] = C[0][i];
		closest[i] = 0;
	}
	see();
	lowcost[0] = INF;
	for(i=1; i<NODES; i++)
	{
		min = lowcost[1];
		k = 1;
		for(j=2; j<NODES; j++)
		{
			if(lowcost[j]<min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		printf("\n[%d, %d]=%d", closest[k], k, lowcost[k]);
		lowcost[k] = INF;
		for(j=1; j<NODES; j++)
		{
			if(C[k][j]<lowcost[j] && lowcost[j]<INF)
			{
				lowcost[j] = C[k][j];
				closest[j] = k;
			}
		}
		see();
	}
}