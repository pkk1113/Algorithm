// 1, 2, 3 ¥ı«œ±‚

#ifdef _WIN32
#pragma warning(disable:4996)
#endif

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<int> steps(N);
	for (int i = 0; i < N; i++)
		scanf("%d", steps.data() + i);

	vector<int> mem(N + 1);
	mem[0] = 0;
	mem[1] = steps[0];

	for (int i = 2; i <= N; i++) {
	}
}