#include <stdio.h>
#define N 6

// 선수과목 프로젝트
int A[N][N] =
{
	{0, 0, 1, 1, 0, 0},
	{0, 0, 0, 1, 1, 0},
	{0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0}
};
// 내차수 배열 초기화
int in[N] = {0, 0, 0, 0, 0, 0};
void see();

int main()
{
	int i, j, k;
	// 내차수 저장
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(A[i][j] == 1)
			{
				in[j]++;
			}
		}
	}
	// 내차수 배열 출력 함수
	see();
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		//for(j=N-1; j>=0; j--)
		{
			// 내차수 0인 노드 선택
			if(in[j] == 0)
			{
				printf("[%d]\n", j);
				// 선택된 내차수 0인 노드 삭제
				in[j] = -1;
				for(k=0; k<N; k++)
				{
					if(A[j][k]==1 && in[k]!=-1)
					{
						in[k]--;
					}
				}
				see();
				break;
			}
		}
		if(j==N)
		{
			printf("\n실행 불가능 프로젝트!!\n");
			break;
		}
	}
	return 0;
}

void see()
{
	int i;
	printf("내차수 : ");
	for(i=0; i<N; i++)
	{
		printf("%d ", in[i]);
	}
	printf("\n");
}