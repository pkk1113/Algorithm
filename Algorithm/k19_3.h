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

	// ���� Ȩ ��ǥ�� ������.
	vector<pair<int, int>> lock_holes;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			if (key[i][j] == 0)
				lock_holes.emplace_back(i, j);


	for (int k = 0; k < 4; k++) {
		// Ű�� ���⸦ ������.
		vector<pair<int, int>> key_bumps;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				if (key[i][j] == 1)
					key_bumps.emplace_back(i, j);

		// Ű ���� �ϳ��� Ȧ �ϳ��� ���߾� ����.
		for (auto& kb : key_bumps) {
			for (auto& lh : lock_holes) {
				// ������ ��ǥ�� ��������
				bool fail = false;
				int k_cnt = 0;

				for (int i = 0; i < M && !fail; i++) { // ��
					for (int j = 0; j < M; j++) { // ��
						int x = lh.first - kb.first + j;
						int y = lh.second - kb.second + i;

						if (x < 0 || y < 0 || x >= N || y >= N)
							continue;

						// ���Ⱑ 1�̰�
						if (key[i][j] == 1) {
							if (lock[y][x] == 0) {
								k_cnt++;
							} else {
								fail = false;
							}
						}
					}
				}

				// ���а� �ƴϰ� �� ä���ٸ�
				if (k_cnt == key_bumps.size()) {
					return true;
				}
			}
		}

		// Ű�� ������.
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
