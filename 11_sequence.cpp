#include <stdio.h>
int main()
{
	FILE* out = fopen("sequence.out", "wt");
	FILE* inp = fopen("sequence.inp", "rt");
	int i = 0;
	while (1)
	{
		long long A, L, num;
		int step;
		int cnt = 0;

		fscanf(inp, "%lld %lld", &A, &L);
		step = 2;
		num = A;
		if (A == -1 || A < 0)
		{
			break;
		}
		switch (step)
		{
		case 2: {
		gogo:	if (num == 1) {
			cnt++;
			break;
		}
		if (num % 2 == 0) step = 3;
		if (num % 2 == 1) step = 4;
		}

		case 3: {
		label:	if (num % 2 == 0) //Â¦¼ö
		{
			if (num > L) { break; }
			if (num == 1) goto gogo;
			num = num * 0.5;
			cnt++;
			if (num % 2 == 1) goto Love;
			if (num % 2 == 0) goto label;
		}
		}
		case 4: {
		Love: if (num % 2 == 1) //È¦¼ö
		{
			if (num > L) { break; }
			if (num == 1) goto gogo;
			num = num * 3 + 1;
			cnt++;
			if (num % 2 == 0) goto label;
			if (num % 2 == 1) goto Love;
		}
		}

		}//switch	

		fprintf(out, "Case %d: A = %lld, limit = %lld, number of terms = %d\n", i + 1, A, L, cnt);
		i++;
	}//while
	fclose(out);
	fclose(inp);
	return 0;
}