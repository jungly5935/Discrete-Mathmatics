#include <stdio.h>

int main()
{

	FILE* fp = fopen("dish.inp", "rt");
	FILE* pf = fopen("dish.out", "wt");

	int cnt;
	char dish[1000];
	int sum = 10;
	int d_cnt;
	int j = 1;
	char c;

	fscanf(fp, "%d", &cnt); //inp 첫째줄

	while (1)
	{

		fscanf(fp, "%d", &d_cnt); //inp 둘째줄
		fscanf(fp, "%c", &c);
		for (int i = 0;i < d_cnt;i++)
		{
			fscanf(fp, "%c", &dish[i]); //접시
		}


		for (int i = 1;i < d_cnt;i++)
		{
			if (dish[i] == dish[i - 1])
				sum += 5;
			else
				sum += 10;
		}


		fprintf(pf, "%d", sum);
		fprintf(pf, "\n");


		if (j == cnt)
			break;
		j++;
		sum = 10;
	} //while 



	fclose(fp);
	fclose(pf);


	return 0;

}
