#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <stdio.h>

int main() {
	int n;
	int t;
	int i = 0; // index
	int s = 0; // sum
	int b = -1; // big

	scanf("%d", &n);
	while (i++ < n) {
		scanf("%d", &t);
		s += t;
		b = t > b ? t : b;
	}

	printf("%.2f", ((float)s / n) * (100.f / b));
}