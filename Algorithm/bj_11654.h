// 아스키 코드

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#pragma warning(disable:4018) // unsigned를 int로 변환
#endif

#include <cstdio>

int main() {
	char c;
	scanf("%c", &c);
	printf("%d", c);
}