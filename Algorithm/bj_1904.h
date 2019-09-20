// 01타일

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int a = 1;
	int b = 2;

	while (--n) {
		int t = (a + b) % 15746;
		a = b;
		b = t;
	}

	printf("%d\n", a);
}