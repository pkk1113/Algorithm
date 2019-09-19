#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	auto arr = vector<int>(n);
	for (auto& el : arr)
		scanf("%d", &el);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int tmp = arr[i] + arr[j] + arr[k];
				if (tmp <= m) {
					ans = abs(tmp - m) < abs(ans - m) ? tmp : ans;
				}
			}
		}
	}

	printf("%d\n", ans);
}