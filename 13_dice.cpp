#include <stdio.h>

FILE* out = fopen("dice.out", "wt");
FILE* inp = fopen("dice.inp", "rt");

int DICE[10000][6]; //주사위 개수 10000개 제한
int BAN[6] = { 5,3,4,1,2,0 }; //주사위 반대쪽 면
int first[10000][6];
int max;

int main()
{
	int x;
	int sum;
	int test;
	int i, j;

	fscanf(inp, "%d", &test);

	for (i = 0; i < test; i++) //주사위 개수
	{
		for (j = 0; j < 6; j++) //주사위 면 수
		{
			fscanf(inp, "%d", &DICE[i][j]);
			first[i][DICE[i][j]] = j; //first은 DICE의 값 첫번째 j값 넣어줌, 이거 헷갈림 ㅠㅠ
		}
	} //주사위 [개수][면] 저장

	int A, B; //계산하지 않는 면 두개 A,B
	int P, Q;

	for (i = 0; i < 6; i++)
	{
		A = DICE[0][i]; //A는 첫 번째 주사위일때, 0 면 부터 시작
		sum = 0;

		for (j = 0; j < test; j++)
		{
			P = first[j][A]; //j번째 주사위일때의 면 A
			Q = BAN[P];
			B = DICE[j][Q]; //j번째 주사위의 마주보는 면은 B

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
			//6->5->4순서대로 대입

			sum += x;

			A = B; //A안에 B를 넣어줌으로써 , j번째 주사위일때 면 A에서 계산 가능
		}

		if (sum > max)
		{
			max = sum;
		} //sum과 max를 비교해 가장 큰 sum를 max 값에 넣어준다
	}

	fprintf(out, "%d", max);


	fclose(inp);
	fclose(out);

	return 0;
}