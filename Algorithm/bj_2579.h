// 1, 2, 3 더하기

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	auto steps = vector<int>(N + 1);
	for (int i = 1; i <= N; i++)
		scanf("%d", steps.data() + i);

	auto mem = vector<int>(N + 1); // [도착] = 최대 점수
	for (int i = 1; i <= N; i++) {
		mem[i] = steps[i] + max(i >= 3 ? mem[i - 3] + steps[i - 1] : 0,
								i >= 2 ? mem[i - 2] : 0);
	}

	printf("%d\n", mem[N]);
}