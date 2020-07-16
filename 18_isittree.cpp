#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	FILE* out = fopen("tree.out", "wt");
	FILE* inp = fopen("tree.inp", "rt");

	vector<int> v; //모든 정점 담을 배열
	vector <int> A; //a의 정점만 담을 배열
	vector <int> B; //b의 정점만 담을 배열 

	for (int t = 0; t >= 0; t++) { //테스트케이스
		int a, b, start;
		int cnt = 0, result = 0, size = 0, root = -1;

		for (int i = 0; i >= 0; i++) {
			fscanf(inp, "%d %d", &a, &b); //부모 자식
			if (a == 0 && b == 0) break; if (a == -1 && b == -1) break;
			A.push_back(a), B.push_back(b); // b의 정점만
			cnt++; //간선의 개수
			v.push_back(a), v.push_back(b);
		} //벡터에 값 넣기 완료
		if (a == -1 && b == -1) break;
		sort(v.begin(), v.end()), sort(A.begin(), A.end()), sort(B.begin(), B.end());
		v.erase(unique(v.begin(), v.end()), v.end()); //정렬 후 정점 비움

		for (int r = 1; r < cnt; r++) //간선 개수만큼 반복
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
			if (A[i] != A[i - 1]) //양 옆과 비교
			{
				if (binary_search(B.begin(), B.end(), A[i - 1]) == 0) { //값이 없다면 루트를 갱신
					if (root == -1) root = A[i - 1];
				}
			}
		}
		if (cnt + 1 != v.size()) {
			root = -1;  //간선 개수랑 정점 개수 차이가 1 아니면 -1출력
		}
		for (int i = 0; i < B.size() - 1; i++)	//정렬 후, 벡터를 b만 다넣고 그 벡터 정렬 후 차례대로 첨에 1일때 1나오면 바로 -1 출력
		{
			if (B[i] == B[i + 1]) {
				root = -1;
				break;
			}//그다음이 같은 수면 -1
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