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

		// ���ƴٴϸ� üũ�Ѵ�.
		for (int i = 0; i < m - 1; i++) { // ��
			for (int j = 0; j < n - 1; j++) { // ��
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

		// �����ϸ鼭 ������.
		for (int j = 0; j < n; j++) { // ��
			int ei = -1; // �� �� �� ���� ���� ���� ��ǥ

			// ����
			for (int i = 0; i < m; i++) { // ��
				if (flag[i][j]) {
					answer++;
					flag[i][j] = false;
					b[i][j] = 0;
					ei = i;
				}
			}

			// ������
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