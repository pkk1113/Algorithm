// 1로 만들기

#ifdef _WIN32
#pragma warning(disable:4996)
#endif

#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int X;
	scanf("%d", &X);
	
	auto mem = vector<int>(X + 1);
	mem[1] = 0;

	for (int i = 2; i <= X; i++) {
		vector<int> tmp(3, numeric_limits<int>::max());

		if (i % 3 == 0)
			tmp[0] = mem[i / 3];
		if (i % 2 == 0)
			tmp[1] = mem[i / 2];
		tmp[2] = mem[i - 1];

		mem[i] = *min_element(tmp.begin(), tmp.end()) + 1;
	}

	printf("%d\n", mem[X]);
}