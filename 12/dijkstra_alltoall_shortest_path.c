#include <stdio.h>
// 노드의 수
#define NODES 4
// 무한대 코스트
#define IF 99

// 네트워크의 인접행렬
int C[NODES][NODES] =
{
	{0, 5, 2, 8},
	{3, 0, 10, 4},
	{9, 4, 0, 3},
	{2, 5, 10, 0}
};

// 2차원 배열
int D[NODES][NODES];
// 2차원 배열
int P[NODES][NODES];
int visited[NODES];

void Dijkstra(int);
void path(int, int);

int main()
{
	int i, j, start;
	printf("D : \n");
	for(start=0; start<NODES; start++)
	{
		Dijkstra(start);
	}
}

// 시작노드 인덱스 start
void Dijkstra(int start)
{
	int i, j, k, min;
	// 배열 D, P, visited 초기화
	for(i=0; i<NODES; i++)
	{
		D[start][i] = C[start][i];
		P[start][i] = start;
		visited[i] = 0;
	}
	// S에 시작노드 포함
	visited[start] = 1;
	
	for(i=0; i<NODES-1; i++)
	{
		min = IF;
		k = start;
		for(j=0; j<NODES; j++)
		{
			// S에 속하지 않은 노드 중에서 가장 가까운 노드 k 선택
			if(D[start][j]<min && !visited[j])
			{
				min = D[start][j];
				k = j;
			}
		}
		// S에 노드 k 포함
		visited[k] = 1;
		for(j=0; j<NODES; j++)
		{
			if(D[start][j]>(D[start][k]+C[k][j]) && !visited[j])
			{
				// 배열 D 갱신
				D[start][j] = D[start][k] + C[k][j];
				// 배열 P 갱신
				P[start][j] = k;
			}
		}
	}
	for(i=0; i<NODES; i++)
	{
		for(j=0; j<NODES; j++)
		{
			printf("%d", D[i][j]);
		}
		printf("\n");
	}
	printf("\nP:\n");
	for(i=0; i<NODES; i++)
	{
		for(j=0; j<NODES; j++)
		{
			printf("%d", P[i][j]);
		}
		printf("\n");
	}
	/*
	printf("\n순방향 최단경로 출력");
	// 순방향 최단경로 출력
	for(start=0; start<NODES; start++)
	{
		for(i=0; i<NODES; i++)
		{
			printf("\n[%d~%d]%d : %d -> ", start, i, D[start][i], start);
			path(start, i);
		}
		printf("\n");
	}
	printf("\n");
	*/
	return 0;
}

void path(int start, int i)
{
	if(i!=start)
	{
		path(start, P[start][i]);
		printf("%d -> ", i);
	}
}