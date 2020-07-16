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


	fscanf(inp, "%d", &cnt); //�Է� Ƚ��

	for (int k = 0; k < cnt; k++)
	{
		int sum = 0;
		GD = 0;

		fscanf(inp, "%d", &num); //�࿭ ����

		for (i = 0; i < num; i++) //��
		{
			for (j = 0; j < num; j++) //��			
			{
				fscanf(inp, "%d ", &arr[i][j]);
			}
		} //��Ŀϼ�


		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				if (arr[i][j] != 1)
				{ //arr[i][j] �� 1�� �ƴ� �� ���

					for (x = 0; x < num; x++) //x�� num ��(��) ����ŭ �ݺ�
					{
						for (y = 0; y < num; y++)	//y�� num ��(��) ����ŭ �ݺ�
						{
							if (arr[i][j] != arr[i][y] + arr[x][j]) //i �� j�� �����ǰ� x�� y�� num��ŭ ��
							{
								continue;
							}
							else
							{
								sum = arr[i][j];
								break;
							} //arr[i][j] == arr[i][y] + arr[x][j] �� sum�� ����
						}
						if (sum == arr[i][j]) break;
					}
					if (sum != arr[i][j]) GD = 1;
					if (GD == 1) break;
				} //1�� �ƴ� ��

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