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

		for (i = 0; i < num; i++) {  // �Է¹��� ������ �� ��ŭ ����
			for (j = 0; j < 8; j++) {  // 8���� ���ڿ� ���� ��
				for (k = 0; k < 6; k++) { // ��Ʈ ���� Ȯ�� 
					if (m[j].code[k] != letter[(i * 6) + k])
						cnt++;
					if (cnt > 1)
						break;
				}

				if (k == 6)
				{ // k�� 6�̸� 1��Ʈ�� ���̳��ų� ��� ��Ʈ�� �������� ���Ǹ���
					result[p++] = m[j].text;
					cnt = 0;
					break; //ã�� ������ �� �̻� ���ڸ� ���� �ʿ䰡 �����Ƿ� break;
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
	}//for(z) //3�� ���

	return 0;
}