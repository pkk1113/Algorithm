// 퇴사

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; // number
	scanf("%d", &N);

	auto t = vector<int>(N + 1, 0); // time
	auto p = vector<int>(N + 1, 0); // pay
	auto mem = vector<int>(N + 1, 0); // memory

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &t[i], &p[i]);
		mem[i] = p[i];
	}

	// [날짜] = 최대로 얻은 돈
	for (int i = 1; i <= N; i++) {
		if (N - i + 1 >= t[i]) {
			for (int j = 1; j <= i; j++) {
				// (겹치지 않는 날까지의 합 + 지금, 지금까지 합)을 비교
				if (i - j >= t[j]) {
					mem[i] = max(p[i] + mem[j], mem[i]);
				}
			}
		} else {
			mem[i] = 0;
		}
	}
	printf("%d\n", *max_element(mem.begin() + 1, mem.end()));
}

