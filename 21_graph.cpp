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
	Visit[start] = 1; //1�̸� �湮 0�̸� �湮x
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
	} //while��

}


int main()
{
	FILE* out = fopen("graph.out", "wt");
	FILE* inp = fopen("graph.inp", "rt");

	vector<bool> Visit;
	pair<int, int> A; //���� v�� ���� �迭
	pair<int, int> B; //���� u�� ���� �迭

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
		fscanf(inp, "%d %d,", &vertex, &edge); //���� ����, ���� ����
		Visit.resize(vertex);
		for (int k = 0; k < edge; k++)
		{
			fscanf(inp, "%d %d %d", &u, &v, &w);
			A.first = v;
			A.second = w;
			graph[u].push_back(A); //�迭 ���� ���� �� �߰� (u,w)
			B.first = u;
			B.second = w;
			graph[v].push_back(B); //�迭 ���� ���� �� �߰�(v,w)
								   // �������̶� �ݴ��� ����
		}
		for (int i = 0; i < vertex; i++)
		{
			sort(graph[i].begin(), graph[i].end()); //����
		}

		fscanf(inp, "%d", &k); //������ ���� 4
		for (int i = 0; i < k; i++)
		{
			dfs_result = 0;
			bfs_result = 0;
			fscanf(inp, "%d", &start); // 0 4 6 1
			DFS(start, Visit);
			Visit = vector<bool>(vertex, 0); //�湮 �ʱ�ȭ, ���� �缳��
			BFS(start, Visit);
			Visit = vector<bool>(vertex, 0);
			fprintf(out, "n=%d m=%d start=%d DFS:%d BFS:%d\n", vertex, edge, start, dfs_result, bfs_result);
			start = 0;
		}

		for (int i = 0; i < vertex; i++)
		{
			graph[i].clear();
		}
	}//�׽�Ʈ���̽�

	fclose(out);
	fclose(inp);
	return 0;
}