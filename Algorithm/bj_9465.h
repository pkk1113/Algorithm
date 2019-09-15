// 스티커

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N;
		scanf("%d", &N);

		auto arr = vector<vector<int>>(2, vector<int>(N + 1, 0));
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= N; j++)
				scanf("%d", &arr[i][j]);
		}

		auto mem = vector<vector<int>>(2, vector<int>(N + 1, 0));
		for (int i = 1; i <= N; i++) {
			int tmp = i >= 2 ? mem[0][i - 2] > mem[1][i - 2] ? mem[0][i - 2] : mem[1][i - 2] : 0;
			mem[0][i] = max(tmp, i >= 1 ? mem[1][i - 1] : 0) + arr[0][i];
			mem[1][i] = max(tmp, i >= 1 ? mem[0][i - 1] : 0) + arr[1][i];
		}

		printf("%d\n", max(mem[0][N], mem[1][N]));
	}
}