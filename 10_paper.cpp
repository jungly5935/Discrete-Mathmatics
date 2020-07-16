#include <stdio.h>

FILE* input = fopen("paper.inp", "rt");
FILE* output = fopen("paper.out", "wt");

int arr1[50][50];
int arr2[50][50];

int main()
{
    int test; // 테스트 갯수
    int N, M; // 세로 , 가로

    fscanf(input, "%d", &test);
start:
    while (test--)
    {
        fscanf(input, "%d %d", &N, &M);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M - 1; j++)
                fscanf(input, "%d", &arr1[i][j]);
        }
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < M; j++)
                fscanf(input, "%d", &arr2[i][j]);
        }
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < M - 1; j++)
            {
                if (arr1[i][j] + arr1[i + 1][j] + arr2[i][j] + arr2[i][j + 1] == 1 || arr1[i][j] + arr1[i + 1][j] + arr2[i][j] + arr2[i][j + 1] == 3)
                    continue;
                else
                {
                    fprintf(output, "0 ");
                    goto start;
                }
            }
        }
        fprintf(output, "1 ");
    }
    return 0;
}