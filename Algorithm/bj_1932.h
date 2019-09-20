// 정수 삼각형

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#pragma warning(disable:4018) // unsigned를 int로 변환
#endif

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int len = 1;
	auto a = vector<int>(len);
	scanf("%d", &a[0]);

	while (--n) {
		auto b = vector<int>(++len);
		for (int i = 0; i < len; i++) {
			scanf("%d", &b[i]);
			int left = (i == 0) ? 0 : a[i - 1]; // 왼쪽 위
			int right = (i == len - 1) ? 0 : a[i]; // 오른쪽 위
			b[i] += max(left, right);
		}
		a = move(b);
	}

	printf("%d", *max_element(a.cbegin(), a.cend()));
}
