// RGB거리

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d\n", &N);
	// [위치][색] = 비용
	auto mem = vector<vector<int>>(N + 1, vector<int>(3, 0));
	for (int i = 1; i <= N; i++) {
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);
		mem[i][0] = min(mem[i - 1][1], mem[i - 1][2]) + r;
		mem[i][1] = min(mem[i - 1][0], mem[i - 1][2]) + g;
		mem[i][2] = min(mem[i - 1][0], mem[i - 1][1]) + b;
	}

	printf("%d\n", *min_element(mem[N].cbegin(), mem[N].cend()));
}