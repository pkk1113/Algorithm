// 2��n Ÿ�ϸ� 2

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#endif

#include <vector>
using namespace std;
#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);
	int mem[1001] = { 0, 1, 3, };

	for (int i = 3; i <= N; i++) {
		mem[i] = (mem[i - 1] + 2 * mem[i - 2]) % 10007;
	}

	printf("%d\n", mem[N]);
}