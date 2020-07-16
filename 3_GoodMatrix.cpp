#include <stdio.h>

int main()
{
	FILE* out = fopen("matrix.out", "wt");
	FILE* inp = fopen("matrix.inp", "rt");

	int cnt, num;
	int arr[301][301];
	int i, j;
	int GD;
	int x, y;
	int n = 0;


	fscanf(inp, "%d", &cnt); //입력 횟수

	for (int k = 0; k < cnt; k++)
	{
		int sum = 0;
		GD = 0;

		fscanf(inp, "%d", &num); //행열 개수

		for (i = 0; i < num; i++) //행
		{
			for (j = 0; j < num; j++) //열			
			{
				fscanf(inp, "%d ", &arr[i][j]);
			}
		} //행렬완성


		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				if (arr[i][j] != 1)
				{ //arr[i][j] 는 1이 아닌 수 모두

					for (x = 0; x < num; x++) //x는 num 행(열) 수만큼 반복
					{
						for (y = 0; y < num; y++)	//y는 num 행(열) 수만큼 반복
						{
							if (arr[i][j] != arr[i][y] + arr[x][j]) //i 와 j는 고정되고 x랑 y가 num만큼 돔
							{
								continue;
							}
							else
							{
								sum = arr[i][j];
								break;
							} //arr[i][j] == arr[i][y] + arr[x][j] 면 sum에 넣음
						}
						if (sum == arr[i][j]) break;
					}
					if (sum != arr[i][j]) GD = 1;
					if (GD == 1) break;
				} //1이 아닌 수

			}
			if (GD == 1) break;
		}

		if (GD == 1)
		{
			fprintf(out, "0\n");
		}
		else
		{
			fprintf(out, "1\n");
		}

	}
	fclose(out);
	fclose(inp);

	return 0;
}