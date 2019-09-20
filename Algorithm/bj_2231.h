// 분해합

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>

int get_m(int n) {
	int t = n;
	while (t != 0) {
		n += t % 10;
		t /= 10;
	}
	return n; // m
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		if (n == get_m(i)) {
			printf("%d\n", i);
			return 0;
		}
	}

	puts("0");
}