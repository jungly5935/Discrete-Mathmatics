#include <stdio.h>

long long arr[10001];

int main() {

    long long n, i, j, temp, min, costsum, cost;
    FILE* fp = fopen("add.inp", "r"), * op = fopen("add.out", "w");

    while (1) {

        fscanf(fp, "%lld", &n);
        if (n == 0) {
            break;
        }

        costsum = 0;

        for (i = 0; i < n; i++) {
            fscanf(fp, "%lld", &arr[i]);
        }

        for (i = 0; i < n; i++) {
            min = i;

            for (j = i + 1; j < n; j++) {
                if (arr[j] < arr[min]) min = j;
            }
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;

        }
        for (i = 0; i < n - 1; i++) {

            cost = arr[i] + arr[i + 1];
            costsum = costsum + cost;

            for (j = i + 1; arr[j + 1] < cost && j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }

            arr[j] = cost;
        }

        fprintf(op, "%lld\n", costsum);

    }

    fclose(fp);
    fclose(op);

    return 0;

}