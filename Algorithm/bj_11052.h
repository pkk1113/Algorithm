// 카드 구매하기

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	auto arr = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	auto mem = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

	for (int c = 1; c <= N; c++) {
		for (int i = 1; i <= N; i++) {
			mem[i][c];
		}
	}
}