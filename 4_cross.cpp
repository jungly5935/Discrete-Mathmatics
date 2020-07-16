#include <stdio.h>
int main()
{
	FILE* out = fopen("cross.out", "wt");
	FILE* inp = fopen("cross.inp", "rt");

	int a[10002];
	int b[10002];
	int p, n;
	int i, j, x, z;
	int dot = 0;

	fscanf(inp, "%d", &p);

	for (int k = 0; k < p; k++)
	{
		int c[10002] = { 0 };

		fscanf(inp, "%d", &n);

		for (i = 0; i < n; i++) //점 개수
		{
			fscanf(inp, "%d ", &a[i]);
		}
		for (j = 0; j < n; j++)
		{
			fscanf(inp, "%d ", &b[j]);
		}



		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{

				if (a[i] == b[j]) // a[i]와 b[j] 숫자가 같을때
				{
					c[j] = 1;
					break;
				}
				if (c[j] == 0)
				{
					dot++;
				}


			}

		}


		fprintf(out, "Case %d: %d \n", k + 1, dot);
		dot = 0;

	}// 도는 횟수


	fclose(out);
	fclose(inp);

}