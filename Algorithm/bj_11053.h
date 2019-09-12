// 가장 긴 증가하는 부분 수열

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
	
	vector<int> mem;

	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		
		auto it = lower_bound(mem.begin(), mem.end(), tmp);
		if (it == mem.end())
			mem.push_back(tmp);
		else
			*it = tmp;
	}

	printf("%d\n", mem.size());
}