// �Ǻ���ġ �Լ�

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#endif

#include <cstdio>

int main() {
	int z[41] = { 1, 0 };
	int o[41] = { 0, 1 };
	for (int i = 2; i <= 40; i++) {
		z[i] = z[i - 1] + z[i - 2];
		o[i] = o[i - 1] + o[i - 2];
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		printf("%d %d\n", z[N], o[N]);
	}
}