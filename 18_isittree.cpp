#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	FILE* out = fopen("tree.out", "wt");
	FILE* inp = fopen("tree.inp", "rt");

	vector<int> v; //��� ���� ���� �迭
	vector <int> A; //a�� ������ ���� �迭
	vector <int> B; //b�� ������ ���� �迭 

	for (int t = 0; t >= 0; t++) { //�׽�Ʈ���̽�
		int a, b, start;
		int cnt = 0, result = 0, size = 0, root = -1;

		for (int i = 0; i >= 0; i++) {
			fscanf(inp, "%d %d", &a, &b); //�θ� �ڽ�
			if (a == 0 && b == 0) break; if (a == -1 && b == -1) break;
			A.push_back(a), B.push_back(b); // b�� ������
			cnt++; //������ ����
			v.push_back(a), v.push_back(b);
		} //���Ϳ� �� �ֱ� �Ϸ�
		if (a == -1 && b == -1) break;
		sort(v.begin(), v.end()), sort(A.begin(), A.end()), sort(B.begin(), B.end());
		v.erase(unique(v.begin(), v.end()), v.end()); //���� �� ���� ���

		for (int r = 1; r < cnt; r++) //���� ������ŭ �ݺ�
		{
			if (B[r - 1] == B[r]) root = -1;
		}
		if (binary_search(B.begin(), B.end(), A.back()) == 0) {
			if (root == -1)
			{
				root = A.back();
			}
		}
		for (int i = 1;i < cnt; i++) {
			if (A[i] != A[i - 1]) //�� ���� ��
			{
				if (binary_search(B.begin(), B.end(), A[i - 1]) == 0) { //���� ���ٸ� ��Ʈ�� ����
					if (root == -1) root = A[i - 1];
				}
			}
		}
		if (cnt + 1 != v.size()) {
			root = -1;  //���� ������ ���� ���� ���̰� 1 �ƴϸ� -1���
		}
		for (int i = 0; i < B.size() - 1; i++)	//���� ��, ���͸� b�� �ٳְ� �� ���� ���� �� ���ʴ�� ÷�� 1�϶� 1������ �ٷ� -1 ���
		{
			if (B[i] == B[i + 1]) {
				root = -1;
				break;
			}//�״����� ���� ���� -1
		}

		fprintf(out, "Test Case %d: %d\n", t + 1, root);
		v.clear();
		A.clear();
		B.clear();
	}

	fclose(out);
	fclose(inp);
	return 0;
}