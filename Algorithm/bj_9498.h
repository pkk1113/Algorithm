// 시험 성적

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	char ans = 'F';

	if (n >= 90)
		ans = 'A';
	else if (n >= 80)
		ans = 'B';
	else if (n >= 70)
		ans = 'C';
	else if (n >= 60)
		ans = 'D';

	printf("%c", ans);
}
