#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dfs_result = 0;
int bfs_result = 0;

vector<pair<int, int> > graph[10000];

void DFS(int start, vector<bool>& Visit)
{
	Visit[start] = 1; //1이면 방문 0이면 방문x
	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i].first;
		if (Visit[next] == 0)
		{
			DFS(next, Visit);
			dfs_result += graph[start][i].second;
		}
	}
}
void BFS(int start, vector<bool>& Visit)
{
	queue<int> qsearch;

	Visit[start] = 1;
	qsearch.push(start);

	while (!qsearch.empty())
	{
		int here = qsearch.front();
		qsearch.pop();

		for (int i = 0; i < graph[here].size(); i++)
		{
			int next = graph[here][i].first;

			if (!Visit[next])
			{
				Visit[next] = 1;
				qsearch.push(next);
				bfs_result += graph[here][i].second;
			}

		}
	} //while문

}


int main()
{
	FILE* out = fopen("graph.out", "wt");
	FILE* inp = fopen("graph.inp", "rt");

	vector<bool> Visit;
	pair<int, int> A; //정점 v를 담을 배열
	pair<int, int> B; //정점 u를 담을 배열

	int test;
	int vertex, edge;
	int startnum;
	int u, v, w;
	int a, b;
	int k;
	int start;

	fscanf(inp, "%d", &test);
	for (int t = 0; t < test; t++)
	{
		fscanf(inp, "%d %d,", &vertex, &edge); //정점 개수, 에지 개수
		Visit.resize(vertex);
		for (int k = 0; k < edge; k++)
		{
			fscanf(inp, "%d %d %d", &u, &v, &w);
			A.first = v;
			A.second = w;
			graph[u].push_back(A); //배열 끝에 원소 값 추가 (u,w)
			B.first = u;
			B.second = w;
			graph[v].push_back(B); //배열 끝에 원소 값 추가(v,w)
								   // 무방향이라서 반대편도 넣음
		}
		for (int i = 0; i < vertex; i++)
		{
			sort(graph[i].begin(), graph[i].end()); //연결
		}

		fscanf(inp, "%d", &k); //시작점 개수 4
		for (int i = 0; i < k; i++)
		{
			dfs_result = 0;
			bfs_result = 0;
			fscanf(inp, "%d", &start); // 0 4 6 1
			DFS(start, Visit);
			Visit = vector<bool>(vertex, 0); //방문 초기화, 길이 재설정
			BFS(start, Visit);
			Visit = vector<bool>(vertex, 0);
			fprintf(out, "n=%d m=%d start=%d DFS:%d BFS:%d\n", vertex, edge, start, dfs_result, bfs_result);
			start = 0;
		}

		for (int i = 0; i < vertex; i++)
		{
			graph[i].clear();
		}
	}//테스트케이스

	fclose(out);
	fclose(inp);
	return 0;
}