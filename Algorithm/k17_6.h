#include <string>
#include <vector>

using namespace std;

bool all_same(int r, int c, vector<string>& b) {
	return
		(b[r][c] == b[r][c + 1]) &&
		(b[r][c] == b[r + 1][c]) &&
		(b[r][c] == b[r + 1][c + 1]);
}

int solution(int m, int n, vector<string> board) {
	auto& b = board;
	int answer = 0;
	auto flag = vector<vector<bool>>(m, vector<bool>(n, false));

	do {
		bool any_checked = false;

		// 돌아다니며 체크한다.
		for (int i = 0; i < m - 1; i++) { // 행
			for (int j = 0; j < n - 1; j++) { // 열
				if (b[i][j] != 0 && all_same(i, j, b)) {
					flag[i][j] = true;
					flag[i + 1][j] = true;
					flag[i][j + 1] = true;
					flag[i + 1][j + 1] = true;

					any_checked = true;
				}
			}
		}

		if (!any_checked)
			break;

		// 제거하면서 내린다.
		for (int j = 0; j < n; j++) { // 열
			int ei = -1; // 빈 곳 중 가장 낮은 행의 좌표

			// 제거
			for (int i = 0; i < m; i++) { // 행
				if (flag[i][j]) {
					answer++;
					flag[i][j] = false;
					b[i][j] = 0;
					ei = i;
				}
			}

			// 내리기
			for (int i = ei; i >= 0; i--) {
				if (b[i][j] != 0) {
					b[ei--][j] = b[i][j];
					b[i][j] = 0;
				}
			}
		}
	} while (true);

	return answer;
}