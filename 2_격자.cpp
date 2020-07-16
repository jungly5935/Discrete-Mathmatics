#include <stdio.h>

int main()
{
	FILE* out = fopen("grid1.out", "wt");
	FILE* inp = fopen("grid1.inp", "rt");

	int type;
	int s;
	int grid;
	int direction;
	int N, M;
	int num;
	int i, j;

	fscanf(inp, "%d", &num);

	for (j = 0; j < num; j++)
	{
		fscanf(inp, "%d %d %d %d %d", &N, &M, &type, &direction, &s); //N���� M����

		if (type == 1)
		{
			switch (direction)
			{
			case 1:
			{
				grid = 0;
				int x = 1;

				for (i = 0; i < s; i++)
				{
					if (x % 2 == 1)
					{
						if (grid % M == 0 && grid != 0)
						{
							grid = grid + M;
							x++;
						}
						else
						{
							grid = grid + 1;
						}
					}
					else if (x % 2 == 0)
					{
						if (grid % M == 1)
						{
							grid = grid + M;
							x++;
						}
						else
						{
							grid = grid - 1;
						}
					}
				}
				fprintf(out, "%d\n", grid);
				break;
			} //case1�ϰ��

			case 2:
			{
				grid = M;
				int x = 1;

				for (i = 1; i < s; i++)
				{
					if (x % 2 == 1) //Ȧ����
					{
						if (grid % M == 1)
						{
							grid = grid + M;
							x++;
						}

						else
						{
							grid = grid - 1;

						}
					}
					else if (x % 2 == 0) //¦����
					{
						if (grid % M == 0)
						{
							grid = grid + M;
							x++;
						}
						else
						{
							grid = grid + 1;
						}
					}
				}
				fprintf(out, "%d\n", grid);
				break;
			} //case2�ϰ��

			case 3:
			{
				grid = M * N;
				int x = 1;

				for (i = 1; i < s; i++)
				{
					if (x % 2 == 1) //��������
					{
						if (grid % M == 1)
						{
							grid = grid - M;
							x++;
						}

						else
						{
							grid = grid - 1;

						}
					}
					else if (x % 2 == 0) //�״�����
					{
						if (grid % M == 0)
						{
							grid = grid - M;
							x++;
						}
						else
						{
							grid = grid + 1;
						}
					}
				}
				fprintf(out, "%d\n", grid);
				break;
			} //case3�ϰ��

			case 4:
			{
				grid = (M * N) - (M - 1);
				int x = 1;

				for (i = 1; i < s; i++)
				{
					if (x % 2 == 1) //��������
					{
						if (grid % M == 0)
						{
							grid = grid - M;
							x++;
						}

						else
						{
							grid = grid + 1;

						}
					}
					else if (x % 2 == 0) //�״�����
					{
						if (grid % M == 1)
						{
							grid = grid - M;
							x++;
						}
						else
						{
							grid = grid - 1;
						}
					}
				}
				fprintf(out, "%d\n", grid);
				break;
			} //case4�ϰ��
			}//switch
		} //if

		else //TYPE 2�϶�
		{
			switch (direction)
			{
			case 1:
			{
				grid = 1;
				int x = 1;
				int cnt = 0;

				for (i = 1; i < s; i++)
				{
					if (M % 2 == 1)//���ΰ� Ȧ���϶�
					{
						if (x % 2 == 1) //ù°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid + 1;
								x++;
							}
							else
							{
								grid = grid + M;
								cnt++;
							}
						}
						else //��°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid + 1;
								x++;
							}
							else
							{
								grid = grid - M;
								cnt++;
							}
						}
					}//M%2==1
					else //���ΰ� ¦���϶�
					{
						if (x % 2 == 1) //ù°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid + 1;
								x++;
							}
							else
							{
								grid = grid + M;
								cnt++;
							}
						}
						else //��°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid + 1;
								x++;
							}
							else
							{
								grid = grid - M;
								cnt++;
							}
						}

					}

				}//for

				fprintf(out, "%d\n", grid);
				break;
			} // case1
			case 2:
			{
				grid = M;
				int x = 1;
				int cnt = 0;

				for (i = 1; i < s; i++)
				{
					if (M % 2 == 0)//���ΰ� ¦���ϰ��
					{
						if (x % 2 == 1) //ù°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid - 1;
								x++;
							}
							else
							{
								grid = grid + M;
								cnt++;
							}
						}
						else //��°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid - 1;
								x++;
							}
							else
							{
								grid = grid - M;
								cnt++;
							}
						}
					}//M%2==0
					else //���ΰ� Ȧ���ϰ��
					{
						if (x % 2 == 1) //ù°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid - 1;
								x++;
							}
							else
							{
								grid = grid + M;
								cnt++;
							}
						}
						else //��°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid - 1;
								x++;
							}
							else
							{
								grid = grid - M;
								cnt++;
							}
						}
					}

				}//for

				fprintf(out, "%d\n", grid);
				break;
			} // case2
			case 3:
			{
				grid = M * N;
				int x = 1;
				int cnt = 0;

				for (i = 1; i < s; i++)
				{

					if (M % 2 == 1) //���ΰ� Ȧ���϶�
					{
						if (x % 2 == 1) //ù°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid - 1;
								x++;
							}
							else
							{
								grid = grid - M;
								cnt++;
							}
						}
						else //��°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid - 1;
								x++;
							}
							else
							{
								grid = grid + M;
								cnt++;
							}
						}
					}//M%2
					else //M%2==0�϶� (���ΰ� ¦���϶�)
					{
						if (x % 2 == 1) //ù°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid - 1;
								x++;
							}
							else
							{
								grid = grid - M;
								cnt++;
							}
						}
						else //��°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid - 1;
								x++;
							}
							else
							{
								grid = grid + M;
								cnt++;
							}
						}

					}

				}//for

				fprintf(out, "%d\n", grid);
				break;
			} // case3
			case 4:
			{
				grid = M * N - (M - 1);
				int x = 1;
				int cnt = 0;

				for (i = 1; i < s; i++)
				{
					if (M % 2 == 0)//���ΰ� ¦��
					{
						if (x % 2 == 1) //ù°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid + 1;
								x++;
							}
							else
							{
								grid = grid - M;
								cnt++;
							}
						}
						else //��°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid + 1;
								x++;
							}
							else
							{
								grid = grid + M;
								cnt++;
							}
						}
					}//M%2==0
					else //M%2==1
					{

						if (x % 2 == 1) //ù°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid + 1;
								x++;
							}
							else
							{
								grid = grid - M;
								cnt++;
							}
						}
						else //��°��
						{
							if (cnt == N - 1)
							{
								cnt = 0;
								grid = grid + 1;
								x++;
							}
							else
							{
								grid = grid + M;
								cnt++;
							}
						}

					}

				}//for

				fprintf(out, "%d\n", grid);
				break;
			} // case4

			}//switch
		}//else


	}//for
	fclose(out);
	fclose(inp);

}