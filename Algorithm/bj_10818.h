// 최소, 최대

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <stdio.h>

int main() {
	int n;
	int b = -1000000; // big
	int s = 1000000; // small
	int t; // temp

	scanf("%d", &n);

	while (n--) {
		scanf("%d", &t);
		b = (t > b) ? t : b;
		s = (t < s) ? t : s;
	}

	printf("%d %d", s, b);
}