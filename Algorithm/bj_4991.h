// �κ� û�ұ�

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#pragma warning(disable:4018) // unsigned�� int�� ��ȯ
#endif

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

void dfs(int s, int len, int remain, vector<map<int, int>>& li, vector<bool>& visit, int& small) {
	if (len >= small)
		return;

	if (remain == 0) {
		small = len;
		return;
	}

	for (auto& el : li[s]) {
		if (visit[el.first])
			continue;
		if (len + el.second >= small)
			continue;

		visit[el.first] = true;
		dfs(el.first, len + el.second, remain - 1, li, visit, small);
		visit[el.first] = false;
	}
}

int main() {
	int m, n;
	int dc[] = { -1, 1, 0, 0 };
	int dr[] = { 0, 0, -1, 1 };

	while (true) {
		scanf("%d %d\n", &m, &n);
		if (m == 0 && n == 0)
			break;

		auto data = vector<vector<int>>(n, vector<int>(m + 1, 10)); // 10�� �ٴ�
		auto vert = vector<pair<int, int>>();

		// �����͸� �����鼭 o, * �� id �ο�
		int id = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= m; j++) {
				char t;
				scanf("%c", &t);
				if (t == 'o') {
					vert.emplace_back(i, j);
					data[i][j] = 0; // ������ 0
				} else if (t == '*') {
					vert.emplace_back(i, j);
					data[i][j] = ++id; // �������� 1���� ����(�ִ� 9����)
				} else if (t == 'x') {
					data[i][j] = -1;
				}
			}
		}

		// id�� �ٸ� id���� �Ÿ��� ���Ѵ�. (bfs)
		auto li = vector<map<int, int>>(vert.size());

		for (auto& v : vert) {
			auto step = vector<vector<int>>(n, vector<int>(m, 0));

			auto q = queue<pair<int, int>>();
			q.push(v);

			while (!q.empty()) {
				auto from = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int nr = from.first + dr[k];
					int nc = from.second + dc[k];

					if (nr < 0 || nc < 0 || nr >= n || nc >= m)
						continue; // ���� ������ ��ŵ
					if (step[nr][nc] != 0 || data[nr][nc] == -1)
						continue; // �̹� �԰ų�, �� �� ������ ��ŵ
					if (nr == v.first && nc == v.second)
						continue; // �ڱ��ڽ� ��ŵ

					step[nr][nc] = step[from.first][from.second] + 1;
					q.emplace(nr, nc);

					if (data[nr][nc] >= 0 && data[nr][nc] < 10) {
						li[data[v.first][v.second]].emplace(data[nr][nc], step[nr][nc]);
					}
				}
			}
		}

		// ���� ��� *�� �� �� ���ٸ� -1 ���
		if (li[0].size() + 1 != vert.size()) {
			printf("%d\n", -1);
			continue;
		}

		// id 0���� �����ϴ� �ִܰ�θ� ���Ѵ�. (dfs)
		int small = 1 << 30;
		auto visit = vector<bool>(li.size());
		visit[0] = true;
		dfs(0, 0, li.size() - 1, li, visit, small);
		printf("%d\n", small);
	}
}