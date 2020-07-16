#include <stdio.h>
int main()
{
	FILE* out = fopen("die.out", "wt");
	FILE* inp = fopen("die.inp", "rt");

	int test;
	int dice[6];
	char direction;


	fscanf(inp, "%d", &test);
	for (int t = 0; t < test; t++)
	{
		int x = 0, y = 0, n, a = 0, b = 0;

		for (int d = 0; d < 6; d++)//다이스개수
		{
			fscanf(inp, "%d", &dice[d]);
		}

		fscanf(inp, "%d %d", &a, &b); //위치정보

		fscanf(inp, "%d", &n);//이동 횟수
		fgetc(inp);
		int A, B;
		int E0[4] = { 1,3,4,5 };
		int E1[4] = { 0,5,2,3 };
		int E2[4] = { 4,3,1,5 };
		int E3[4] = { 1,2,4,0 };
		int E4[4] = { 0,3,2,5 };
		int E5[4] = { 0,4,2,1 };

		int A1[4] = { 1,2,4,0 };//B가 0이고 A가 1이면
		int A3[4] = { 3,2,5,0 };
		int A4[4] = { 4,2,1,0 };
		int A5[4] = { 5,2,3,0 };
		int B3[4] = { 3,4,5,1 };
		int B0[4] = { 0,4,2,1 };
		int B5[4] = { 5,4,3,1 };
		int B2[4] = { 2,4,0,1 };
		int C3[4] = { 3,0,5,2 };
		int C1[4] = { 1,0,4,2 };
		int C5[4] = { 5,0,3,2 };
		int C4[4] = { 4,0,1,2 };
		int D0[4] = { 0,5,2,3 };
		int D1[4] = { 1,5,4,3 };
		int D2[4] = { 2,5,0,3 };
		int D4[4] = { 4,5,1,3 };
		int G5[4] = { 5,1,3,4 };
		int G0[4] = { 0,1,2,4 };
		int G3[4] = { 3,1,5,4 };
		int G2[4] = { 2,1,0,4 };
		int F1[4] = { 1,3,4,5 };
		int F0[4] = { 0,3,2,5 };
		int F4[4] = { 4,3,1,5 };
		int F2[4] = { 2,3,0,5 };


		int i;
		for (int k = 0; k < n; k++)
		{

			fscanf(inp, "%c", &direction);//방향
			if (direction == '\n') break;
			for (int j = 0; j < 6; j++) //a와 b의주솟값 찾기
			{
				if (a == dice[j]) A = j;
				if (b == dice[j]) B = j;
			}

			if (direction == 'E') //E면 b는 가만히있고 a만 -> 움직임
			{
				y += 1;
				if (B == 0)
				{
					if (A == 1) { i = 0; a = dice[E0[(i + 1) % 4]]; }
					if (A == 3) { i = 1; a = dice[E0[(i + 1) % 4]]; }
					if (A == 4) { i = 2; a = dice[E0[(i + 1) % 4]]; }
					if (A == 5) { i = 3; a = dice[E0[(i + 1) % 4]]; }
				}

				if (B == 1)
				{
					if (A == 0) { i = 0; a = dice[E1[(i + 1) % 4]]; }
					if (A == 5) { i = 1; a = dice[E1[(i + 1) % 4]]; }
					if (A == 2) { i = 2; a = dice[E1[(i + 1) % 4]]; }
					if (A == 3) { i = 3; a = dice[E1[(i + 1) % 4]]; }
				}
				if (B == 2)
				{
					if (A == 4) { i = 0; a = dice[E2[(i + 1) % 4]]; }
					if (A == 3) { i = 1; a = dice[E2[(i + 1) % 4]]; }
					if (A == 1) { i = 2; a = dice[E2[(i + 1) % 4]]; }
					if (A == 5) { i = 3; a = dice[E2[(i + 1) % 4]]; }

				}
				if (B == 3)
				{
					if (A == 1) { i = 0; a = dice[E3[(i + 1) % 4]]; }
					if (A == 2) { i = 1; a = dice[E3[(i + 1) % 4]]; }
					if (A == 4) { i = 2; a = dice[E3[(i + 1) % 4]]; }
					if (A == 0) { i = 3; a = dice[E3[(i + 1) % 4]]; }
				}
				if (B == 4)
				{
					if (A == 0) { i = 0; a = dice[E4[(i + 1) % 4]]; }
					if (A == 3) { i = 1; a = dice[E4[(i + 1) % 4]]; }
					if (A == 2) { i = 2; a = dice[E4[(i + 1) % 4]]; }
					if (A == 5) { i = 3; a = dice[E4[(i + 1) % 4]]; }
				}
				if (B == 5)
				{
					if (A == 0) { i = 0; a = dice[E5[(i + 1) % 4]]; }
					if (A == 4) { i = 1; a = dice[E5[(i + 1) % 4]]; }
					if (A == 2) { i = 2; a = dice[E5[(i + 1) % 4]]; }
					if (A == 1) { i = 3; a = dice[E1[(i + 1) % 4]]; }
				}

			}
			else if (direction == 'W') //W면 b는 가만히있고 a만 <- 움직임
			{
				y -= 1;
				if (B == 0)
				{
					if (A == 1) { i = 0; a = dice[E0[(4 - 1) % 4]]; }
					if (A == 3) { i = 1; a = dice[E0[(i - 1) % 4]]; }
					if (A == 4) { i = 2; a = dice[E0[(i - 1) % 4]]; }
					if (A == 5) { i = 3; a = dice[E0[(i - 1) % 4]]; }
				}

				if (B == 1)
				{
					if (A == 0) { i = 0; a = dice[E1[(4 - 1) % 4]]; }
					if (A == 5) { i = 1; a = dice[E1[(i - 1) % 4]]; }
					if (A == 2) { i = 2; a = dice[E1[(i - 1) % 4]]; }
					if (A == 3) { i = 3; a = dice[E1[(i - 1) % 4]]; }
				}
				if (B == 2)
				{
					if (A == 4) { i = 0; a = dice[E2[(4 - 1) % 4]]; }
					if (A == 3) { i = 1; a = dice[E2[(i - 1) % 4]]; }
					if (A == 1) { i = 2; a = dice[E2[(i - 1) % 4]]; }
					if (A == 5) { i = 3; a = dice[E2[(i - 1) % 4]]; }

				}
				if (B == 3)
				{
					if (A == 1) { i = 0; a = dice[E3[(4 - 1) % 4]]; }
					if (A == 2) { i = 1; a = dice[E3[(i - 1) % 4]]; }
					if (A == 4) { i = 2; a = dice[E3[(i - 1) % 4]]; }
					if (A == 0) { i = 3; a = dice[E3[(i - 1) % 4]]; }
				}
				if (B == 4)
				{
					if (A == 0) { i = 0; a = dice[E4[(4 - 1) % 4]]; }
					if (A == 3) { i = 1; a = dice[E4[(i - 1) % 4]]; }
					if (A == 2) { i = 2; a = dice[E4[(i - 1) % 4]]; }
					if (A == 5) { i = 3; a = dice[E4[(i - 1) % 4]]; }
				}
				if (B == 5)
				{
					if (A == 0) { i = 0; a = dice[E5[(4 - 1) % 4]]; }
					if (A == 4) { i = 1; a = dice[E5[(i - 1) % 4]]; }
					if (A == 2) { i = 2; a = dice[E5[(i - 1) % 4]]; }
					if (A == 1) { i = 3; a = dice[E5[(i - 1) % 4]]; }
				}
			}
			else if (direction == 'S') //S면 a가 바뀌고 b는 a가 됨
			{
				i = 0;
				x -= 1;
				b = a;
				if (B == 0)
				{

					if (A == 3) { a = dice[A3[(i + 1) % 4]]; }
					if (A == 4) { a = dice[A4[(i + 1) % 4]]; }
					if (A == 5) { a = dice[A5[(i + 1) % 4]]; }
					if (A == 1) { a = dice[A1[(i + 1) % 4]]; }
				}

				if (B == 1)
				{

					if (A == 3) { a = dice[B3[(i + 1) % 4]]; }
					if (A == 0) { a = dice[B0[(i + 1) % 4]]; }
					if (A == 5) { a = dice[B5[(i + 1) % 4]]; }
					if (A == 2) { a = dice[B2[(i + 1) % 4]]; }
				}
				if (B == 2)
				{

					if (A == 3) { a = dice[C3[(i + 1) % 4]]; }
					if (A == 1) { a = dice[C1[(i + 1) % 4]]; }
					if (A == 5) { a = dice[C5[(i + 1) % 4]]; }
					if (A == 4) { a = dice[C4[(i + 1) % 4]]; }
				}
				if (B == 3)
				{

					if (A == 0) { a = dice[D0[(i + 1) % 4]]; }
					if (A == 1) { a = dice[D1[(i + 1) % 4]]; }
					if (A == 2) { a = dice[D2[(i + 1) % 4]]; }
					if (A == 4) { a = dice[D4[(i + 1) % 4]]; }
				}
				if (B == 4)
				{

					if (A == 5) { a = dice[G5[(i + 1) % 4]]; }
					if (A == 0) { a = dice[G0[(i + 1) % 4]]; }
					if (A == 3) { a = dice[G3[(i + 1) % 4]]; }
					if (A == 2) { a = dice[G2[(i + 1) % 4]]; }

				}
				if (B == 5)
				{

					if (A == 1) { a = dice[F1[(i + 1) % 4]]; }
					if (A == 0) { a = dice[F0[(i + 1) % 4]]; }
					if (A == 4) { a = dice[F4[(i + 1) % 4]]; }
					if (A == 2) { a = dice[F2[(i + 1) % 4]]; }

				}
			}
			else if (direction == 'N')//N면 a는 b가되고 b가 바뀜
			{
				i = 3;
				x += 1;
				a = b;
				if (B == 0)
				{

					if (A == 3) { b = dice[A3[(i - 1) % 4]]; }
					if (A == 4) { b = dice[A4[(i - 1) % 4]]; }
					if (A == 5) { b = dice[A5[(i - 1) % 4]]; }
					if (A == 1) { b = dice[A1[(i - 1) % 4]]; }
				}

				if (B == 1)
				{

					if (A == 3) { b = dice[B3[(i - 1) % 4]]; }
					if (A == 0) { b = dice[B0[(i - 1) % 4]]; }
					if (A == 5) { b = dice[B5[(i - 1) % 4]]; }
					if (A == 2) { b = dice[B2[(i - 1) % 4]]; }
				}
				if (B == 2)
				{
					if (A == 3) { b = dice[C3[(i - 1) % 4]]; }
					if (A == 1) { b = dice[C1[(i - 1) % 4]]; }
					if (A == 5) { b = dice[C5[(i - 1) % 4]]; }
					if (A == 4) { b = dice[C4[(i - 1) % 4]]; }
				}
				if (B == 3)
				{

					if (A == 0) { b = dice[D0[(i - 1) % 4]]; }
					if (A == 1) { b = dice[D1[(i - 1) % 4]]; }
					if (A == 2) { b = dice[D2[(i - 1) % 4]]; }
					if (A == 4) { b = dice[D4[(i - 1) % 4]]; }
				}
				if (B == 4)
				{

					if (A == 5) { b = dice[G5[(i - 1) % 4]]; }
					if (A == 0) { b = dice[G0[(i - 1) % 4]]; }
					if (A == 3) { b = dice[G3[(i - 1) % 4]]; }
					if (A == 2) { b = dice[G2[(i - 1) % 4]]; }

				}
				if (B == 5)
				{

					if (A == 1) { b = dice[F1[(i - 1) % 4]]; }
					if (A == 0) { b = dice[F0[(i - 1) % 4]]; }
					if (A == 4) { b = dice[F4[(i - 1) % 4]]; }
					if (A == 2) { b = dice[F2[(i - 1) % 4]]; }

				}
			}


		}//전체 for문


		fprintf(out, "%d %d %d %d\n", y, x, a, b);
	}//테스트케이스

	fclose(out);
	fclose(inp);
	return 0;
}