#include <stdio.h>

int main() {
    int a, b, arr[1010][2] = { 0 }, i, T, n, result[1010], j, count;
    FILE* fp = fopen("line2.inp", "r"), * op = fopen("line2.out", "w");

    fscanf(fp, "%d", &T);

    while (T--) {

        fscanf(fp, "%d", &n);

        for (i = 0; i < n; i++) {
            fscanf(fp, "%d", &arr[i][0]);
        }

        for (i = 0; i < n; i++) {
            fscanf(fp, "%d", &a);
            for (j = 0; j < n; j++) {
                if (arr[j][0] == a) {
                    break;
                }
            }
            arr[j][1] = i;
        }

        for (i = 0; i < n; i++) {
            count = 0;

            for (j = i - 1; j >= 0; j--) {
                if (arr[j][1] > arr[i][1]) count++;
            }

            result[arr[i][0]] = count;

        }

        for (i = 1; i <= n; i++) {
            fprintf(op, "%d ", result[i]);
        }

        fprintf(op, "\n");

    }

    fclose(fp);
    fclose(op);

    return 0;
}