// 이친수

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

	auto mem = vector<long long>(N + 1, 1);
	for (int i = 3; i <= N; i++) {
		mem[i] = mem[i - 1] + mem[i - 2];
		// f(i) = 1 + f(i-2)...f(1)		1. 처음 생각한 점화식
		// f(i-1) = 1 + f(i-3)...f(1)	2. 지금 보니 일부를 치환가능
		// f(i) = f(i-1) + f(i-2)		3. 아..
	}

	printf("%lld\n", mem[N]);
}