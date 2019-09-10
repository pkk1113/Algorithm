// 1, 2, 3 더하기

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>

using namespace std;

int main() {
	int mem[11] = { 0, 1, 2, 4, };

	for (int i = 4; i <= 10; i++)
		mem[i] = mem[i - 1] + mem[i - 2] + mem[i - 3];

	int T;
	scanf("%d", &T);

	while (T--) {
		int N;
		scanf("%d", &N);
		printf("%d\n", mem[N]);
	}
}