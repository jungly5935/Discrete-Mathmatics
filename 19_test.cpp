#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

int t, cache[1001][1001], c = 1;
string gw, p, test;

int match(string g, string t, int gp, int tp) {



    int& ret = cache[gp][tp];
    if (ret != -1)return ret;
    int a = 0;

    if (gp < g.size() && tp < t.size() && ((g[gp] == '?' || g[gp] == t[tp]))) {

        if (g[gp] == '?') {
            for (int i = 0; i < gw.size(); i++) {
                if (t[tp] == gw[i]) {
                    a = 1;
                    break;
                }
            }
            if (a == 1)return ret = match(g, t, gp + 1, tp + 1);
            else return ret = 0;
        }
        else return ret = match(g, t, gp + 1, tp + 1);
    }
    if (gp == g.size()) {
        if (tp == t.size())return ret = 1;
        else return ret = 0;
    }
    if (g[gp] == '*') {
        for (int i = 0; i + tp <= t.size(); i++) {
            if (tp + i == t.size() && a == 0)break;
            if (a == 0) {
                for (int j = 0; j < gw.size(); j++) {
                    if (t[tp + i] == gw[j])break;
                    if (j == gw.size() - 1)a = 1;
                }
            }
            if (a == 1 && match(g, t, gp + 1, tp + +i + 1))return ret = 1;
        }
        if (match(g, t, gp + 1, tp))return ret = 1;
    }
    return ret = 0;
}

int main() {

    ifstream fin;
    ofstream fout;
    fin.open("exam.inp");
    fout.open("exam.out");

    fin >> t;
    while (t--) {

        fin >> gw;
        fin >> p;
        int num, ret;
        fin >> num;
        fout << "Test case: #" << c++ << endl;
        for (int i = 0; i < num; i++) {
            memset(cache, -1, sizeof(cache));
            fin >> test;
            ret = match(p, test, 0, 0);
            if (ret == 0)fout << "NO" << endl;
            else fout << "YES" << endl;
        }
    }

    fin.close();
    fout.close();

}