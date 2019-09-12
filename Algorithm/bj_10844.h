#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);

	int mem[100][10] = { 0, };
	for (int s = 0; s <= 9; s++)
		mem[0][s] = 1;

	for (int len = 1; len < N; len++)
		for (int s = 0; s <= 9; s++)
			mem[len][s] = (((s > 0) ? mem[len - 1][s - 1] : 0)
						   + ((s < 9) ? mem[len - 1][s + 1] : 0)) % 1000000000;

	int ans = 0;
	for (int s = 1; s <= 9; s++) {
		ans += mem[N - 1][s];
		ans %= 1000000000;
	}

	printf("%d\n", ans);
}