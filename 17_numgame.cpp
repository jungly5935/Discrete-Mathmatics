#include <stdio.h>
#include <string.h>

int t, n, s, ba, num, board[10000];

void check() {

    int a[4], b[4];
    int inum = num;
    a[0] = inum / 1000;
    inum %= 1000;
    a[1] = inum / 100;
    inum %= 100;
    a[2] = inum / 10;
    a[3] = inum % 10;
    for (int i = 1234; i <= 9876; i++) {
        if (board[i] == 0) {
            int ii = i;
            b[0] = ii / 1000;
            ii %= 1000;
            b[1] = ii / 100;
            ii %= 100;
            b[2] = ii / 10;
            b[3] = ii % 10;
            if (b[0] == b[1] || b[0] == b[2] || b[0] == b[3] || b[1] == b[2] || b[1] == b[3] || b[2] == b[3]) {
                board[i] = 1;
                continue;
            }
            if (b[1] == 0 || b[2] == 0 || b[3] == 0) {
                board[i] = 1;
                continue;
            }

            int sc = 0, bc = 0;
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (j == k && a[j] == b[k]) sc++;
                    else if (j != k && a[j] == b[k]) bc++;
                }
            }
            if (sc != s || bc != ba)board[i] = 1;
        }

    }
}

int main() {
    FILE* inp = fopen("numgame.inp", "rt");
    FILE* out = fopen("numgame.out", "wt");

    fscanf(inp, "%d", &t);
    while (t--) {
        fscanf(inp, "%d", &n);
        memset(board, 0, sizeof(board));
        while (n--) {
            fscanf(inp, "%d %d %d", &num, &s, &ba);
            check();
        }
        int ret = 0;
        for (int i = 1234; i <= 9876; i++)if (board[i] == 0)ret++;
        if (ret < 7) {
            fprintf(out, "%d\n", ret);
            for (int i = 1234; i <= 9876; i++)if (board[i] == 0)fprintf(out, "%d\n", i);
        }
        else {
            fprintf(out, "%d\n", ret);
            int co = 0;
            for (int i = 1234; i <= 9876; i++)if (board[i] == 0) {
                co++;
                if (co == 1 || co == 2 || co == 3 || co == ret || co == ret - 1 || co == ret - 2)fprintf(out, "%d\n", i);
            }

        }
    }
    fclose(out);
    fclose(inp);
}