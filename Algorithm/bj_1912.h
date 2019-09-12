// 연속합

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	auto arr = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	
	int big = -1000; // minimum value
	auto mem = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		mem[i] = max(mem[i - 1] + arr[i], arr[i]);
		big = max(big, mem[i]);
	}

	printf("%d\n", big);
}