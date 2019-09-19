// 오르막수

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
using namespace std;

inline void op(int& target, int& value) {
	target = (target + value) % 10007;
}

int main() {
	int n;
	scanf("%d", &n);

	// start - digit
	auto mem = vector<vector<int>>(10, vector<int>(n + 1, 0));

	for (int s = 0; s <= 9; s++)
		mem[s][1] = 1;

	for (int d = 2; d <= n; d++)
		for (int s = 0; s <= 9; s++)
			for (int k = s; k <= 9; k++)
				op(mem[s][d], mem[k][d - 1]);

	int ans = 0;
	for (int s = 0; s <= 9; s++)
		op(ans, mem[s][n]);

	printf("%d\n", ans);
}