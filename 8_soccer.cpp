#include <stdio.h>
int main()
{
	FILE* out = fopen("soccer.out", "wt");
	FILE* inp = fopen("soccer.inp", "rt");

	int i, j, k, z, T, a, b, sum = 0;
	int team, round, p, q, p_score, q_score;
	int away_score[100];
	int score[100];
	int result[100];
	int goal[100];
	int away[100];
	fscanf(inp, "%d", &T);
	for (z = 0; z < T; z++) { //�׽�Ʈ���̽�

		int away_score[100] = { 0 };
		int score[100] = { 0 };
		int result[100] = { 0 };
		int goal[100] = { 0 };
		int away[100] = { 0 };

		fscanf(inp, "%d %d", &team, &round); //�� ��, ���� ��
		for (i = 0; i < round; i++) {
			for (j = 0; j < 2 * (team - 1); j++) { //2*(n-1)��
				for (a = 0; a < team / 2; a++) //�Ϸ絿�� ��� Ƚ��
				{
					fscanf(inp, "%d-%d %d %d", &p, &q, &p_score, &q_score);
					if (p_score > q_score) // 1. ���� ������ ����+3 
					{
						score[p] = score[p] + 3;
					}
					else if (p_score < q_score)
					{
						score[q] = score[q] + 3;
					}
					else
					{
						score[p] = score[p] + 1;
						score[q] = score[q] + 1;
					}

					goal[p] += (p_score - q_score);//�� �� ���
					goal[q] += (q_score - p_score);
					away_score[p] += p_score;
					for (p = 1; p <= team; p++) {
						away[p] = away_score[p];

					} //away ���� ��� 
				}//n/2��� (�Ϸ�)
			}//for(game)
		}//for(round)

		for (i = 0; i < 41; i++)
		{
			result[i] = 1;
		}
		for (i = 1; i <= 41; i++)
		{
			for (j = 1; j <= 41; j++)
			{
				if (score[i] < score[j]) //1.���� �� : 1�� �ϳ��� ��ü(1,2,3,4..team) �� �ϳ��� �� �� 
				{
					result[i]++;
					continue;
				}

				if (score[i] == score[j]) //������ ���� ���
				{
					if (goal[i] < goal[j]) //2. �� ��� �� : �� ����� j�� �� Ŭ���
					{
						result[i]++; //i�� ��� ����
						continue;
					}
					if (goal[i] == goal[j]) // ����, �� ��� �� ���� ���
					{
						if (away[i] < away[j])//3. away �� ���� Ŭ ���� ���� ����
						{
							result[i]++;
							continue;
						}
						else continue;
					}
				}
			}
		}
		fprintf(out, "Test Case #%d: ", z + 1);//A->D ����������
		for (a = 1; a <= team; a++)
		{
			fprintf(out, "%d ", result[a]);
		}
		fprintf(out, "\n");

	}//�׽�Ʈ���̽�

	return 0;
}