// Ÿ�� ä��� (3 * N)

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#endif

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	auto mem = vector<int>(N + 1, 0);
	mem[2] = 3;

	for (int i = 4; i <= N; i += 2) {
		// �ڽ��� Ư�� ���̽�
		mem[i] = 2;
		// �Ϲ����� ��ȭ�� f(2) + f(i-2)
		mem[i] += 3 * mem[i - 2];
		// Ư���� �տ� ���� �� ���
		for (int j = 4; j <= i; j += 2) {
			mem[i] += 2 * mem[i - j];
		}
	}

	printf("%d\n", mem[N]);
}