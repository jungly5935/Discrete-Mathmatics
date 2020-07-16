#include <stdio.h>

int main()
{
	FILE* out = fopen("entrance.out", "wt");
	FILE* inp = fopen("entrance.inp", "rt");
	int TesT, n;
	int a;
	int result[1000] = { 0 };
	fscanf(inp, "%d", &TesT);
	for (int t = 0; t < TesT; t++)
	{

		int arr[1000] = { 0 };
		int cnt = 0;
		fscanf(inp, "%d", &n);

		for (int k = 0; k < n; k++)
		{
			fscanf(inp, "%d", &a);

			for (int j = 0; j < n; j++)
			{
				if (arr[j] < a)
				{
					arr[j] = a;
					break;
				}
			}

		}

		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 0) break;
			cnt++;
		}
		fprintf(out, "%d\n", cnt);

	}//테스트케이스

	fclose(out);
	fclose(inp);
	return 0;
}