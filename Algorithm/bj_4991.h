// 로봇 청소기

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#pragma warning(disable:4018) // unsigned를 int로 변환
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

		auto data = vector<vector<int>>(n, vector<int>(m + 1, 10)); // 10은 바닥
		auto vert = vector<pair<int, int>>();

		// 데이터를 읽으면서 o, * 에 id 부여
		int id = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= m; j++) {
				char t;
				scanf("%c", &t);
				if (t == 'o') {
					vert.emplace_back(i, j);
					data[i][j] = 0; // 시작은 0
				} else if (t == '*') {
					vert.emplace_back(i, j);
					data[i][j] = ++id; // 나머지는 1부터 증가(최대 9까지)
				} else if (t == 'x') {
					data[i][j] = -1;
				}
			}
		}

		// id별 다른 id로의 거리를 구한다. (bfs)
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
						continue; // 범위 나가면 스킵
					if (step[nr][nc] != 0 || data[nr][nc] == -1)
						continue; // 이미 왔거나, 갈 수 없으면 스킵
					if (nr == v.first && nc == v.second)
						continue; // 자기자신 스킵

					step[nr][nc] = step[from.first][from.second] + 1;
					q.emplace(nr, nc);

					if (data[nr][nc] >= 0 && data[nr][nc] < 10) {
						li[data[v.first][v.second]].emplace(data[nr][nc], step[nr][nc]);
					}
				}
			}
		}

		// 만약 모든 *에 갈 수 없다면 -1 출력
		if (li[0].size() + 1 != vert.size()) {
			printf("%d\n", -1);
			continue;
		}

		// id 0에서 시작하는 최단경로를 구한다. (dfs)
		int small = 1 << 30;
		auto visit = vector<bool>(li.size());
		visit[0] = true;
		dfs(0, 0, li.size() - 1, li, visit, small);
		printf("%d\n", small);
	}
}