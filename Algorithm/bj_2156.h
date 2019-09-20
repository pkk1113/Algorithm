// 포도주 시식

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
	auto arr = vector<int>(4);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	auto mem = vector<int>(n + 1, 0);
	int c[3]; // cases
	for (int i = 1; i <= n; i++) {
		int mem_2 = i >= 2 ? mem[i - 2] : 0;
		int mem_3 = i >= 3 ? mem[i - 3] : 0;

		// cases
		c[0] = mem[i - 1];
		c[1] = arr[i] + mem_2;
		c[2] = arr[i] + arr[i - 1] + mem_3;

		mem[i] = *max_element(c, c + 3);
	}

	printf("%d\n", mem[n]);
}