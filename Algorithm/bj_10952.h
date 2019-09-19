// A+B - 5

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <stdio.h>

int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) == 2 && (a != 0 || b != 0))
		printf("%d\n", a + b);
}