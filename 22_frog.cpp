#include <stdio.h>

int main()
{
	FILE* out = fopen("frog.out", "wt");
	FILE* inp = fopen("frog.inp", "rt");


	int test, result;
	int z;

	fscanf(inp, "%d", &test);
	for (z = 0; z < test; z++)
	{
		int frog[100] = { 0 }; // �ٴ� �� ����
		int sum[100] = { 0 }; //�Ÿ� ���ϱ�

		char stone[100];
		int stonenum = 0, stream = 0;
		int max = 0;

		fscanf(inp, "%d %d", &stonenum, &stream); //�� ����, �� �ʺ�
		for (int i = 1; i <= stonenum; i++) //�� ������ŭ �ݺ�
		{
			fgetc(inp);
			fscanf(inp, "%c", &stone[i]); //�� ����
			fgetc(inp);
			fscanf(inp, "%d", &frog[i]); //�������� �Ÿ�
		}

		frog[0] = 0; //������ 0
		frog[stonenum + 1] = stream; // �迭 �Է��� ���������� �׻� ���� �ʺ� ����


		for (int j = 0; j < stonenum + 1; j++)
		{
			if (stone[j] == 'B')
			{
				if (stonenum == 1)
				{
					sum[0] = frog[1] - frog[0];
				}
				sum[j] = frog[j + 1] - frog[j];

			}
			else //stone =='S'
			{
				if (stonenum == 1)
				{
					sum[j] = stream;

				}
				else
				{
					if (j == 0) sum[j] = frog[j + 1] - frog[j];
					else { sum[j] = frog[j + 1] - frog[j - 1]; }

				}
			}

		}



		//sum �� ���� ū �� ���
		max = sum[0];
		for (int k = 0; k < stonenum; k++)
		{
			if (sum[k + 1] > max)
			{
				max = sum[k + 1];
			}
		}



		fprintf(out, "Case %d: %d\n", z + 1, max);

	}//�׽�Ʈ���̽�

	fclose(out);
	fclose(inp);
	return 0;
}