// 체스판 다시 칠하기

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	auto arr = vector<vector<char>>(n, vector<char>(m + 1));
	for (auto& row : arr) {
		scanf("%s", row.data());
	}

	int small_cnt = 64;

	// offset i, j
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			// 판을 검사
			int cnt = 0;

			for (int r = 0; r < 8; r++) {
				for (int c = 0; c < 8; c++) {
					if ((r + c) % 2 == 0 && arr[r + i][c + j] == arr[i][j])
						cnt++;
					else if ((r + c) % 2 == 1 && arr[r + i][c + j] != arr[i][j])
						cnt++;
				}
			}

			cnt = cnt < 64 - cnt ? cnt : 64 - cnt;
			small_cnt = cnt < small_cnt ? cnt : small_cnt;
		}
	}

	printf("%d\n", small_cnt);
}