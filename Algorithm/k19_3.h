#include <string>
#include <vector>

using namespace std;

void rotate_90(vector<vector<int>>& data) {
	int S = data.size();
	int half_S = S >> 1;

	for (int i = 0; i < half_S; i++) {
		for (int j = 0; j < half_S; j++) {
			int sj = S - j - 1;
			int si = S - i - 1;

			int tmp = data[i][j];
			data[i][j] = data[sj][i];
			data[sj][i] = data[si][sj];
			data[si][sj] = data[j][si];
			data[j][si] = tmp;
		}
	}
}

bool solution(vector<vector<int>> key,
			  vector<vector<int>> lock) {
	int N = lock.size();
	int M = key.size();

	// 록의 홈 좌표를 모은다.
	vector<pair<int, int>> lock_holes;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			if (key[i][j] == 0)
				lock_holes.emplace_back(i, j);


	for (int k = 0; k < 4; k++) {
		// 키의 돌기를 모은다.
		vector<pair<int, int>> key_bumps;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				if (key[i][j] == 1)
					key_bumps.emplace_back(i, j);

		// 키 돌기 하나를 홀 하나에 맞추어 본다.
		for (auto& kb : key_bumps) {
			for (auto& lh : lock_holes) {
				// 열쇠의 좌표를 기준으로
				bool fail = false;
				int k_cnt = 0;

				for (int i = 0; i < M && !fail; i++) { // 행
					for (int j = 0; j < M; j++) { // 열
						int x = lh.first - kb.first + j;
						int y = lh.second - kb.second + i;

						if (x < 0 || y < 0 || x >= N || y >= N)
							continue;

						// 돌기가 1이고
						if (key[i][j] == 1) {
							if (lock[y][x] == 0) {
								k_cnt++;
							} else {
								fail = false;
							}
						}
					}
				}

				// 실패가 아니고 다 채웠다면
				if (k_cnt == key_bumps.size()) {
					return true;
				}
			}
		}

		// 키를 돌린다.
		rotate_90(key);
	}

	return false;
}

int main() {
	auto key = vector<vector<int>>{
		{0, 0, 0}, {1, 0, 0}, {0, 1, 1}
	};

	auto lock = vector<vector<int>>{
		{1, 1, 1}, {1, 1, 0}, {1, 0, 1}
	};

	auto r = solution(key, lock);
	printf("%s\n", r ? "true" : "false");
}
