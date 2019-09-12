// 컨닝

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int C;
	scanf("%d", &C);

	while (C--) {
		int N, M; // 세로 N, 가로 M
		scanf("%d %d", &N, &M); // >= 1, <= 10
		auto data = vector<vector<char>>(N, vector<char>(M + 1));
		for (int i = 0; i < N; i++) {
			scanf("%s", data[i].data());
		}

		auto mem = vector<int>(M + 1);

		printf("%d\n", 10);
	}
}

// 인접한 열끼리 무조건 막아버린다. :(
/*
3 5
.x.x.
xxxxx
x.x.x
5 가 나와야 하는데 3이 나온다.
*/