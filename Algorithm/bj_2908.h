// 상수

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#pragma warning(disable:4018) // unsigned를 int로 변환
#endif

#include <cstdio>

int to_sangsu(char* c) {
	return 100 * (c[2] - '0') + 10 * (c[1] - '0') + c[0] - '0';
}

int main() {
	char a[4];
	char b[4];

	scanf("%s %s", a, b);

	int an = to_sangsu(a);
	int bn = to_sangsu(b);

	printf("%d", an > bn ? an : bn);
}