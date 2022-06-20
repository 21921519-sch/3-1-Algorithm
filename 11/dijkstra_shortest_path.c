#include <stdio.h>
// 노드의 수
#define NODES 7
// 무한대 코스트
#define IF 100

int D[NODES];
int P[NODES];
int visited[NODES];
// 네트워크의 인접행렬
int C[NODES][NODES] =
{
	// 기본값 : {IF, IF, IF, IF, IF, IF, IF}
	
	{0, 7, IF, IF, 3, 10, IF},
	{7, 0, 4, 10, 2, 6, IF},
	{IF, 4, 0, 2, IF, IF, IF},
	{IF, 10, 2, 0, 11, 9, 4},
	{3, 2, IF, 11, 0, IF, 5},
	{10, 6, IF, 9, IF, 0, IF},
	{IF, IF, IF, 4, 5, IF, 0}
	
	/*
	{0, 2, IF, 5, 3, IF, IF},
	{2, 0, 4, IF, IF, IF, IF},
	{IF, 4, 0, 9, IF, 6, 11},
	{5, IF, 9, 0, IF, IF, IF},
	{3, IF, IF, IF, 0, 7, IF},
	{IF, IF, 6, IF, 7, 0, 10},
	{IF, IF, 11, IF, IF, 10, 0}
	*/
};

void Dijkstra(int);
// 배열 D, P 출력
void see();
void path(int, int);

int main(void)
{
	int i, j, start = 0;
	Dijkstra(start);
	
	printf("\n역방향 최단경로 출력");
	for(i=0; i<NODES; i++)
	{
		printf("\n[%d~%d] : %d(%d) <- ", start, i, i, D[i]);
		for(j=P[i]; j!=start; j=P[j])
		{
			printf("%d(%d) <- ", j, D[j]);
		}
		printf("%d(%d)", start, D[start]);
	}
	printf("\n순방향 최단경로 출력");
	for(i=0; i<NODES; i++)
	{
		printf("\n[%d~%d] : %d(%d) -> ", start, i, start, D[start]);
		path(start, i);
	}
	
	printf("\n");
}

void see()
{
	int i;
	printf("\n ");
	for(i=0; i<NODES; i++)
	{
		printf("%4d", i);
	}
	printf("\nD : ");
	for(i=0; i<NODES; i++)
	{
		printf("%4d", D[i]);
	}
	printf("\nP : ");
	for(i=0; i<NODES; i++)
	{
		printf("%4d", P[i]);
	}
	printf("\n");
}

void path(int start, int i)
{
	if(i!=start)
	{
		path(start, P[i]);
		printf("%d(%d) -> ", i, D[i]);
	}
}

// 시작노드 인덱스 start
void Dijkstra(int start)
{
	int i, j, k, min;
	// 배열 D, P, visited 초기화
	for(i=0; i<NODES; i++)
	{
		D[i] = C[start][i];
		P[i] = start;
		visited[i] = 0;
	}
	see();
	// S에 시작노드 포함
	visited[start] = 1;
	
	for(i=0; i<NODES-1; i++)
	{
		min = IF;
		k = start;
		for(j=0; j<NODES; j++)
		{
			// S에 속하지 않은 노드 중에서 가장 가까운 노드 k 선택
			if(D[j]<min && !visited[j])
			{
				min = D[j];
				k = j;
			}
		}
		printf("\nk = %d", k);
		// S에 노드 k 포함
		visited[k] = 1;
		for(j=0; j<NODES; j++)
		{
			if(!visited[j])
			{
				printf("\nD[%d] = min(D[%d], D[%d] + C[%d][%d]) = min(%d, %d + %d) = ", j, j, k, k, j, D[j], D[k], C[k][j]);
			}
			else
			{
				printf("\nD[%d] = %d", j, D[j]);
			}
			if(D[j]>(D[k]+C[k][j]) && !visited[j])
			{
				// 배열 D 갱신
				D[j] = D[k]+C[k][j];
				printf("%d", D[j]);
				P[j] = k;
			}
			else if(D[j]<=(D[k]+C[k][j]) && !visited[j])
			{
				printf("%d", D[j]);
			}
		}
		see();
	}
}