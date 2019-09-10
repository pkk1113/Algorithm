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
		auto data = vector<int>(M + 1, 0);
		for (int i = 0; i < N; i++) {
			char tmp[11];
			scanf("%s", tmp);

			for (int j = 1; j <= M; j++) { // 1부터
				if (tmp[j - 1] == '.') // 0부터
					data[j]++;
			}
		}

		auto mem = vector<int>(M + 1, 0);
		mem[1] = data[1];
		for (int i = 2; i <= M; i++) {
			mem[i] = max(mem[i - 2] + data[i], mem[i - 1]);
		}

		if (M >= 2)
			mem[M] = max(mem[M], mem[M - 1]);

		printf("%d\n", mem[M]);
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