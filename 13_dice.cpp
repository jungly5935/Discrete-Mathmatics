#include <stdio.h>

FILE* out = fopen("dice.out", "wt");
FILE* inp = fopen("dice.inp", "rt");

int DICE[10000][6]; //�ֻ��� ���� 10000�� ����
int BAN[6] = { 5,3,4,1,2,0 }; //�ֻ��� �ݴ��� ��
int first[10000][6];
int max;

int main()
{
	int x;
	int sum;
	int test;
	int i, j;

	fscanf(inp, "%d", &test);

	for (i = 0; i < test; i++) //�ֻ��� ����
	{
		for (j = 0; j < 6; j++) //�ֻ��� �� ��
		{
			fscanf(inp, "%d", &DICE[i][j]);
			first[i][DICE[i][j]] = j; //first�� DICE�� �� ù��° j�� �־���, �̰� �򰥸� �Ф�
		}
	} //�ֻ��� [����][��] ����

	int A, B; //������� �ʴ� �� �ΰ� A,B
	int P, Q;

	for (i = 0; i < 6; i++)
	{
		A = DICE[0][i]; //A�� ù ��° �ֻ����϶�, 0 �� ���� ����
		sum = 0;

		for (j = 0; j < test; j++)
		{
			P = first[j][A]; //j��° �ֻ����϶��� �� A
			Q = BAN[P];
			B = DICE[j][Q]; //j��° �ֻ����� ���ֺ��� ���� B

			if (A != 6 && B != 6)
			{
				x = 6;
			}
			else if (B != 5 && A != 5)
			{
				x = 5;
			}
			else
			{
				x = 4;
			}
			//6->5->4������� ����

			sum += x;

			A = B; //A�ȿ� B�� �־������ν� , j��° �ֻ����϶� �� A���� ��� ����
		}

		if (sum > max)
		{
			max = sum;
		} //sum�� max�� ���� ���� ū sum�� max ���� �־��ش�
	}

	fprintf(out, "%d", max);


	fclose(inp);
	fclose(out);

	return 0;
}