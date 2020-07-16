#include <stdio.h>
#include <string.h>
FILE* out = fopen("mail.out", "wt");
FILE* inp = fopen("mail.inp", "rt");
typedef struct
{
	char text;
	char code[7];
}mail;
int main()
{
	mail m[8] = { { 'A', "000000" },{ 'B', "001111" },{ 'C', "010011" },{ 'D', "011100" },{ 'E', "100110" },{ 'F', "101001" },{ 'G', "110101" },{ 'H', "111010" } };
	int num, cnt = 0;
	int i, j, k, p = 0;
	int z, n;
	char letter[5000];
	char result[5000];

	fscanf(inp, "%d", &n);
	for (z = 0; z < n; z++)
	{
		fscanf(inp, "%d", &num);
		fscanf(inp, "%s", letter);

		for (i = 0; i < num; i++) {  // 입력받은 문자의 수 만큼 루프
			for (j = 0; j < 8; j++) {  // 8개의 문자에 대해 비교
				for (k = 0; k < 6; k++) { // 비트 단위 확인 
					if (m[j].code[k] != letter[(i * 6) + k])
						cnt++;
					if (cnt > 1)
						break;
				}

				if (k == 6)
				{ // k가 6이면 1비트만 차이나거나 모든 비트가 같은경우로 조건만족
					result[p++] = m[j].text;
					cnt = 0;
					break; //찾고 나서는 더 이상 문자를 비교할 필요가 없으므로 break;
				}

				if (j == 7 && k != 6)
				{
					result[p++] = 'X';
				}

				cnt = 0;
			} //for(j)

		} //for(i)

		for (i = 0; i < p; i++)
		{
			fprintf(out, "%c", result[i]);
		}
		fprintf(out, "\n");
		p = 0;
	}//for(z) //3번 출력

	return 0;
}