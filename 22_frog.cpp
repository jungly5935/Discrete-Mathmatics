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
		int frog[100] = { 0 }; // 뛰는 값 저장
		int sum[100] = { 0 }; //거리 구하기

		char stone[100];
		int stonenum = 0, stream = 0;
		int max = 0;

		fscanf(inp, "%d %d", &stonenum, &stream); //돌 개수, 강 너비
		for (int i = 1; i <= stonenum; i++) //돌 개수만큼 반복
		{
			fgetc(inp);
			fscanf(inp, "%c", &stone[i]); //돌 종류
			fgetc(inp);
			fscanf(inp, "%d", &frog[i]); //서편에서의 거리
		}

		frog[0] = 0; //시작점 0
		frog[stonenum + 1] = stream; // 배열 입력의 마지막에는 항상 강의 너비 저장


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



		//sum 중 가장 큰 수 출력
		max = sum[0];
		for (int k = 0; k < stonenum; k++)
		{
			if (sum[k + 1] > max)
			{
				max = sum[k + 1];
			}
		}



		fprintf(out, "Case %d: %d\n", z + 1, max);

	}//테스트케이스

	fclose(out);
	fclose(inp);
	return 0;
}