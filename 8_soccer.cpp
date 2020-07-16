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
	for (z = 0; z < T; z++) { //테스트케이스

		int away_score[100] = { 0 };
		int score[100] = { 0 };
		int result[100] = { 0 };
		int goal[100] = { 0 };
		int away[100] = { 0 };

		fscanf(inp, "%d %d", &team, &round); //팀 수, 라운드 수
		for (i = 0; i < round; i++) {
			for (j = 0; j < 2 * (team - 1); j++) { //2*(n-1)날
				for (a = 0; a < team / 2; a++) //하루동안 경기 횟수
				{
					fscanf(inp, "%d-%d %d %d", &p, &q, &p_score, &q_score);
					if (p_score > q_score) // 1. 점수 많으면 승점+3 
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

					goal[p] += (p_score - q_score);//골 수 계산
					goal[q] += (q_score - p_score);
					away_score[p] += p_score;
					for (p = 1; p <= team; p++) {
						away[p] = away_score[p];

					} //away 점수 계산 
				}//n/2경기 (하루)
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
				if (score[i] < score[j]) //1.승점 비교 : 1팀 하나와 전체(1,2,3,4..team) 를 하나씩 다 비교 
				{
					result[i]++;
					continue;
				}

				if (score[i] == score[j]) //점수가 같을 경우
				{
					if (goal[i] < goal[j]) //2. 골 득실 비교 : 골 득실이 j가 더 클경우
					{
						result[i]++; //i의 등수 증가
						continue;
					}
					if (goal[i] == goal[j]) // 승점, 골 득실 다 같을 경우
					{
						if (away[i] < away[j])//3. away 골 수가 클 수록 점수 증가
						{
							result[i]++;
							continue;
						}
						else continue;
					}
				}
			}
		}
		fprintf(out, "Test Case #%d: ", z + 1);//A->D 점수높은순
		for (a = 1; a <= team; a++)
		{
			fprintf(out, "%d ", result[a]);
		}
		fprintf(out, "\n");

	}//테스트케이스

	return 0;
}