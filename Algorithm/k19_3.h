#include <string>
#include <vector>

using namespace std;

int N;
int M;

void make_roated_90(vector<vector<int>>& old_data,
					vector<vector<int>>& new_data) {

	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			new_data[i][j] = old_data[M - 1 - j][i];
}

bool solution(vector<vector<int>> key,
			  vector<vector<int>> lock) {
	M = key.size();
	N = lock.size();

	auto key_90 = vector<vector<int>>(M, vector<int>(M));
	auto key_180 = vector<vector<int>>(M, vector<int>(M));
	auto key_270 = vector<vector<int>>(M, vector<int>(M));

	make_roated_90(key, key_90);
	make_roated_90(key_90, key_180);
	make_roated_90(key_180, key_270);

	vector<pair<int, int>> key_bumps[4];
	vector<pair<int, int>> lock_holes;

	// 0 Ű�� ���� ��ǥ�� ������.
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			if (key[i][j] == 1)
				key_bumps[0].emplace_back(i, j);

	// 90 Ű�� ���� ��ǥ�� ������.
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			if (key_90[i][j] == 1)
				key_bumps[1].emplace_back(i, j);

	// 180 Ű�� ���� ��ǥ�� ������.
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			if (key_180[i][j] == 1)
				key_bumps[2].emplace_back(i, j);

	// 270 Ű�� ���� ��ǥ�� ������.
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			if (key_270[i][j] == 1)
				key_bumps[3].emplace_back(i, j);


	// ���� Ȩ ��ǥ�� ������.
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			if (key[i][j] == 0)
				lock_holes.emplace_back(i, j);

	// Ű�� ���⸦ ���� �� Ȩ�� �ְ� 4�� ��������.
	for (int k = 0; k < 4; k++) {
		for (auto& kb : key_bumps[k]) {
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

						if ((lock[y][x] & key[i][j]) == 1) {
							fail = true;
							break;
						}
					}
				}

				// ���а� �ƴϰ� �� ä���ٸ�
				if (!fail) {
					return true;
				}
			}
		}
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

	solution(key, lock);
}
