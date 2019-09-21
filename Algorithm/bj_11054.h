// 가장 긴 바이토닉 부분 수열

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#pragma warning(disable:4018) // unsigned를 int로 변환
#endif

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

auto lis(int* s, int n, bool inc = true) {
	auto mem = vector<int>();
	while (n--) {
		auto it = lower_bound(mem.begin(), mem.end(), *s);
		if (it == mem.end())
			mem.push_back(*s);
		else
			*it = *s;
		inc ? s++ : s--;
	}
	return mem;
}

int main() {
	int n;
	scanf("%d", &n);
	auto arr = vector<int>(n);
	for (auto& el : arr) {
		scanf("%d", &el);
	}

	int big = 1; // n은 최소 1이다.

	for (int i = 1; i < n; i++) {
		auto left = lis(&arr.front(), i, true);
		auto right = lis(&arr.back(), n - i, false);
		int len = left.size() + right.size();

		if (left.back() == right.back())
			len -= 1;

		big = max(big, len);
	}

	printf("%d\n", big);
}