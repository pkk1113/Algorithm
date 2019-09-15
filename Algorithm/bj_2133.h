// 타일 채우기 (3 * N)

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	auto mem = vector<int>(N + 1, 0);
	mem[2] = 3;

	for (int i = 4; i <= N; i += 2) {
		// 자신의 특이 케이스
		mem[i] = 2;
		// 일반적인 점화식 f(2) + f(i-2)
		mem[i] += 3 * mem[i - 2];
		// 특수가 앞에 오는 각 경우
		for (int j = 4; j <= i; j += 2) {
			mem[i] += 2 * mem[i - j];
		}
	}

	printf("%d\n", mem[N]);
}