// ��ģ��

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

	auto mem = vector<long long>(N + 1, 1);
	for (int i = 3; i <= N; i++) {
		mem[i] = mem[i - 1] + mem[i - 2];
		// f(i) = 1 + f(i-2)...f(1)		1. ó�� ������ ��ȭ��
		// f(i-1) = 1 + f(i-3)...f(1)	2. ���� ���� �Ϻθ� ġȯ����
		// f(i) = f(i-1) + f(i-2)		3. ��..
	}

	printf("%lld\n", mem[N]);
}