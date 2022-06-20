#include <stdio.h>
// 노드의 수
#define NODES 4
// 무한대 코스트
#define INF 99

// 네트워크의 인접행렬
int A[NODES][NODES] =
{
	/*
	{0, 5, 2, 8},
	{3, 0, 10, 4},
	{9, 4, 0, 3},
	{2, 5, 10, 0}
	*/
	{0, 5, 2, 5},
	{3, 0, 9, 7},
	{10, 7, 0, 10},
	{6, 8, 5, 0}
	
};

int P[NODES][NODES];
void see();
void path(int, int);

int main(void)
{
	int i, j, k;
	for(i=0; i<NODES; i++)
	{
		for(j=0; j<NODES; j++)
		{
			P[i][j] = -1;
		}
	}
	see();
	
	for(k=0; k<NODES; k++)
	{
		printf("\n[k=%d]", k);
		for(i=0; i<NODES; i++)
		{
			for(j=0; j<NODES; j++)
			{
				if((i!=k && j!=k) && i!=j)
				{
					printf("\nmin(A[%d][%d],A[%d][%d]+A[%d][%d])=min(%d, %d)=", i, j, i, k, k, j, A[i][j], A[i][k]+A[k][j]);
				}
				if(A[i][j]>A[i][k]+A[k][j])
				{
					// 행렬 D 갱신
					A[i][j] = A[i][k]+A[k][j];
					// 경유행렬 P 갱신
					P[i][j] = k;
				}
				if((i!=k && j!=k) && i!=j)
				{
					printf("%d", A[i][j]);
				}
			}
		}
		see();
	}
	printf("\n");
	/*
	printf("\n순방향 최단경로 출력");
	for(i=0; i<NODES; i++)
	{
		for(j=0; j<NODES; j++)
		{
			printf("\n[%d~%d] %d : %d -> ", i, j, A[i][j], i);
			path(i, j);
			printf("%d", j);
		}
	}
	*/
	printf("\n");
	return 0;
}

void see()
{
	int i, j;
	printf("\n\n");
	for(i=0; i<NODES; i++)
	{
		for(j=0; j<NODES; j++)
		{
			printf("%3d", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0; i<NODES; i++)
	{
		for(j=0; j<NODES; j++)
		{
			printf("%3d", P[i][j]);
		}
		printf("\n");
	}
}

void path(int i, int j)
{
	int k;
	k = P[i][j];
	if(k != -1)
	{
		path(j, k);
		printf("%d -> ", k);
		path(k, j);
	}
}