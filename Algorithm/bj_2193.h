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
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i - 1; j++)
			mem[i] += mem[j];
	}

	for (int i = 1; i <= N; i++)
		printf("%lld\n", mem[i]);
}