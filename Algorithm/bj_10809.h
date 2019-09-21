// 알파벳 찾기

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#pragma warning(disable:4018) // unsigned를 int로 변환
#endif

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	auto alpha = vector<int>('z' - 'a' + 1, -1);
	char c;
	int i = 0;

	while ((c = getchar()) != '\n') {
		if (alpha[c - 'a'] == -1)
			alpha[c - 'a'] = i;
		i++;
	}

	for (auto& index : alpha) {
		printf("%d ", index);
	}
}
