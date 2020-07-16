#include <stdio.h>
int main()
{
	FILE* out = fopen("line.out", "wt");
	FILE* inp = fopen("line.inp", "rt");

	int test, num;
	int z;
	int Q, A; //질문,답
	int n;
	int i, j;
	int k1, k2;
	int N = 0;
	int K;

	fscanf(inp, "%d", &test);
	for (z = 0; z < test; z++)
	{
		int cnt = 0;
		int k_max = 0;
		int k_min = 0;
		int before_K_min = 0;
		int before_K_max = 0;
		int k = 0;
		int min = 0;
		int max = 0;

		fscanf(inp, "%d", &num);
		for (j = 0; j < num; j++)
		{
			fscanf(inp, "%d %d", &Q, &A);
			if (k_min == k_max && k_min != 0 && k_max != 0)
			{
				continue;
			}
			//최소값 최대값 찾아서 비교하기
			for (k = 1; k < 1000000; k++)
			{
				min = (k + (k + 1) * ((A - 1) - 1) + (((A - 1) - 1) * (A - 1)) / 2 - ((A - 1) - 1)) + 1;// 그 (항-1) + 1의 값
				max = k + (k + 1) * (A - 1) + ((A - 1) * A) / 2 - (A - 1); //k 원소합

				if (Q >= min && Q <= max)
				{
					if (before_K_min > k)
					{
						k_min = before_K_min;
						break;
					}
					else
					{
						k_min = k;
						break;
					}
				}
			}
			for (k = k_min; k < max; k++)
			{
				min = (k + (k + 1) * ((A - 1) - 1) + (((A - 1) - 1) * (A - 1)) / 2 - ((A - 1) - 1)) + 1;// 그 (항-1) + 1의 값
				max = k + (k + 1) * (A - 1) + ((A - 1) * A) / 2 - (A - 1); //k 원소합

				if (Q < min)
				{
					if (before_K_max < k && before_K_max != 0)
					{
						k_max = before_K_max;
						break;
					}
					else
					{
						k_max = k - 1;
						break;
					}

				}

			}
			before_K_min = k_min;
			before_K_max = k_max;


			cnt++; //질문 개수 세기
			k = k_min;

		}//for(j)


		if (k_min != k_max) { fprintf(out, "-1\n"); }
		else
			fprintf(out, "%d %d\n", cnt, k); //최소 질문 수, k값



	}//테스트케이스


	return 0;
}