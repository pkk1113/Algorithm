// 다이얼

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#pragma warning(disable:4018) // unsigned를 int로 변환
#endif

#include <cstdio>

int to_num(char c) {
	if (c < 'S')
		return (c - 'A') / 3 + 2;
	else if (c == 'S')
		return 7;
	else if (c < 'W')
		return 8;
	else
		return 9;
}

int main() {
	char c;
	int t = 0;

	while ((c = getchar()) != '\n') {
		t += to_num(c) + 1;
	}

	printf("%d\n", t);
}