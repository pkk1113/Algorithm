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

auto lis(int* b, int n) {
	auto mem = vector<int>();
	while (n--) {
		auto it = lower_bound(mem.begin(), mem.end(), *b);
		if (it == mem.end())
			mem.push_back(*b);
		else
			*it = *b;
		b++;
	}
	return mem;
}

auto lis_back(int* e, int n) {
	auto mem = vector<int>();
	while (n--) {
		auto it = lower_bound(mem.begin(), mem.end(), *e);
		if (it == mem.end())
			mem.push_back(*e);
		else
			*it = *e;
		e--;
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

	int big = 0;

	for (int i = 0; i < n; i++) {
		auto left = lis(&arr.front(), i);
		auto right = lis_back(&arr.back(), n - i);
		int len = left.size() + right.size();

		if (!left.empty() && !right.empty() && left.back() == right.back())
			len -= 1;

		big = max(big, len);
	}

	printf("%d\n", big);
}