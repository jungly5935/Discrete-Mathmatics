#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE* input = fopen("spreadsheet.inp", "r");
    FILE* output = fopen("spreadsheet.out", "w");

    int T;
    char ex[20];

    fscanf(input, "%d", &T);

    while (T--) {
        fscanf(input, "%s", &ex);
        int a = strlen(ex);  //a�� ex�� string����
        int b = 1;
        while (b < a && isdigit(ex[b])) //isdigit()��  ex[b]�� ������ �ƽ�Ű�ڵ尪���� �Ǻ�
            ++b;
        if (b > 1 && b < a) {
            int c = 0;
            for (int i = b + 1; i < a; ++i) {
                c = c * 10 + (ex[i] - '0'); //'0'=48
            }

            int p = 26;
            while (c > p) {
                c -= p;
                p *= 26;
            }

            c = c - 1;
            while (p != 1) {
                p /= 26;
                fprintf(output, "%c", c / p + 'A'); //'A'=65
                c %= p;
            }

            ex[b] = 0;
            fprintf(output, "%s\n", ex + 1);
        }
        else {
            int c = 0; int val = 0; int p = 1;
            int i = 0;
            while (isalpha(ex[i])) {  //�������� �ƴ��� �Ǻ�
                c += p;
                p *= 26;
                val = val * 26 + ex[i] - 'A';
                i += 1;
            }
            c += val;
            fprintf(output, "R%sC%d\n", ex + i, c);
        }
    }
    fclose(input);
    fclose(output);

    return 0;
}