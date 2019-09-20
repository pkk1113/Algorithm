// 덩치

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	auto x = vector<int>(n);
	auto y = vector<int>(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}

	for (int i = 0; i < n; i++) {
		int cnt = 1;

		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			
			if (x[j] > x[i] && y[j] > y[i]) {
				cnt++;
			}
		}

		printf("%d ", cnt);
	}
}