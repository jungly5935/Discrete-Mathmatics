#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	FILE* out = fopen("family.out", "wt");
	FILE* inp = fopen("family.inp", "rt");

	int test, num, a, b;

	fscanf(inp, "%d", &test);
	for (int t = 0; t < test; t++)
	{
		int* Graph = (int*)malloc(sizeof(int) * 500000);
		int* add = (int*)malloc(sizeof(int) * 500000);
		memset(Graph, 0, 500000);
		memset(add, 0, 500000);

		int cnt = 1;

		fscanf(inp, "%d", &num);

		for (int k = 0; k < num - 1; k++) { //사람수 -1 만큼 반복
			fscanf(inp, "%d %d", &a, &b);
			Graph[b] = a;
		}

		for (int i = 1; i < num + 1; i++)
		{
			int	A = i;
			cnt = 1;
			for (int j = i; j > 0; j++) {
			love:
				A = Graph[A];
				add[i] = ++cnt;
				if (Graph[A] == 0) break;
				goto love;
			}


		}

		//배열 안에서 제일 큰 수 출력
		int MAX = 0;
		MAX = add[1];
		for (int i = 1; i < num + 1; i++)
		{
			if (add[i + 1] > MAX) MAX = add[i + 1];
		}
		fprintf(out, "%d\n", MAX);

		free(Graph);
		free(add);

	}//테스트케이스

	fclose(out);
	fclose(inp);
	return 0;
}