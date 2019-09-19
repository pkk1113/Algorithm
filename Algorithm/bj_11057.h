// 오르막수

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	auto mem = vector<vector<int>>(10, vector<int>(n + 1, 0));
	for (int i = 0; i <= 9; i++)
		mem[i][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				mem[j][i] += mem[k][i - 1];
				mem[j][i] %= 10007;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += mem[i][n];
		ans %= 10007;
	}

	printf("%d\n", ans);
}