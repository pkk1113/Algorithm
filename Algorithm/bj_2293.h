// 동전

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	auto coin = vector<int>(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &coin[i]);

	// [k원] = 경우의 수
	auto mem = vector<int>(k + 1);
	mem[0] = 1; // 0원은 안내면 되기때문에 1번

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coin[i]) {
				mem[j] += mem[j - coin[i]];
			}
		}
	}

	printf("%d\n", mem[k]);
}