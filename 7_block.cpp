#include<stdio.h>
#pragma warning(disable:4996)
int block[1001][1001];
FILE* inp = fopen("block.inp", "r");
FILE* out = fopen("block.out", "w");
int main()
{
	int Testcase, H;
	fscanf(inp, "%d ", &Testcase);
	int y = 0;
	int x = 0;
	int p;
	int count = 0;
	for (p = 0; p < Testcase; p += 1)

	{
		fscanf(inp, "%d", &H);
		for (x = 0; x < H; x += 1)
		{
			for (y = 0; y <= x; y += 1)
			{
				fscanf(inp, "%d", &block[x][y]);
			}
		}

		while (1)
		{
			count = 0;
			for (x = 0; x < H; x += 1)
			{
				for (y = 0; y <= x; y += 1)
				{
					if (block[x][y] != -1)
						continue;

					if (x == 0)//맨위쪽 일때
					{
						if ((block[x + 1][y] != -1) && (block[x + 1][y + 1] != -1))
						{
							block[x][y] = (block[x + 1][y] + block[x + 1][y + 1]) % 100;
							if (block[x][y] < 0)
							{
								block[x][y] += 100;
							}
							count += 1;
						}
						continue;
					}

					if (x == (H - 1))
					{

						if (y == 0)
						{
							if ((block[x - 1][y] != -1) && (block[x][y + 1] != -1))
							{
								block[x][y] = (block[x - 1][y] - block[x][y + 1]) % 100;
								if (block[x][y] < 0)
								{
									block[x][y] += 100;
								}
								count += 1;

							}
							continue;
						}
						if (y == x)
						{
							if ((block[x - 1][y - 1] != -1) && (block[x][y - 1] != -1))
							{
								block[x][y] = (block[x - 1][y - 1] - block[x][y - 1]) % 100;
								if (block[x][y] < 0)
								{
									block[x][y] += 100;
								}
								count += 1;

							}
							continue;
						}

						if ((block[x - 1][y - 1] != -1) && (block[x][y - 1] != -1))
						{
							block[x][y] = (block[x - 1][y - 1] - block[x][y - 1]) % 100;
							if (block[x][y] < 0)
							{
								block[x][y] += 100;
							}
							count += 1;
							continue;
						}

						if ((block[x][y + 1] != -1) && (block[x - 1][y] != -1))
						{
							block[x][y] = (block[x - 1][y] - block[x][y + 1]) % 100;
							if (block[x][y] < 0)
							{
								block[x][y] += 100;
							}
							count += 1;

						}
						continue;
					}

					if (y == 0)
					{
						if ((block[x - 1][y] != -1) && (block[x][y + 1] != -1))
						{
							block[x][y] = (block[x - 1][y] - block[x][y + 1]) % 100;
							if (block[x][y] < 0)
							{
								block[x][y] += 100;
							}
							count += 1;
							continue;
						}


						if ((block[x + 1][y] != -1) && (block[x + 1][y + 1] != -1))//자신의 아래쪽과 아래오른쪽을 확인해서 둘다있으면 연산
						{
							block[x][y] = (block[x + 1][y] + block[x + 1][y + 1]) % 100;
							if (block[x][y] < 0)
							{
								block[x][y] += 100;
							}

							count += 1;
						}
						continue;
					}

					if (y == x)//중간지점에서 맨오른쪽일때
					{
						if ((block[x + 1][y] != -1) && (block[x + 1][y + 1] != -1))
						{
							block[x][y] = (block[x + 1][y] + block[x + 1][y + 1]) % 100;
							if (block[x][y] < 0)
							{
								block[x][y] += 100;
							}
							count += 1;
							continue;
						}


						if ((block[x][y - 1] != -1) && (block[x - 1][y - 1] != -1))
						{
							block[x][y] = (block[x - 1][y - 1] - block[x][y - 1]) % 100;
							if (block[x][y] < 0)
							{
								block[x][y] += 100;
							}
							count += 1;

						}
						continue;
					}

					if ((block[x - 1][y - 1] != -1) && (block[x][y - 1] != -1))
					{
						block[x][y] = (block[x - 1][y - 1] - block[x][y - 1]) % 100;
						if (block[x][y] < 0)
						{
							block[x][y] += 100;
						}
						count += 1;
						continue;
					}


					if ((block[x][y + 1] != -1) && (block[x - 1][y] != -1))
					{
						block[x][y] = (block[x - 1][y] - block[x][y + 1]) % 100;
						if (block[x][y] < 0)
						{
							block[x][y] += 100;
						}
						count += 1;
						continue;
					}



					if ((block[x + 1][y] != -1) && (block[x + 1][y + 1] != -1))
					{

						block[x][y] = (block[x + 1][y] + block[x + 1][y + 1]) % 100;
						if (block[x][y] < 0)
						{
							block[x][y] += 100;
						}
						count += 1;
						continue;

					}
				}

			}
			if (count == 0)
				break;
		}

		for (x = 0; x < H; x++)
		{
			for (y = 0; y <= x; y++)
			{
				fprintf(out, "%d ", block[x][y]);
			}
			fprintf(out, "\n");
		}
	}
	fclose(inp);
	fclose(out);
	return 0;
}
