// ��ȭ���� ��

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#endif

#include <cstdio>

bool ok(int n) {
	int cnt = 0;
	while (n) {
		if (n % 10 == 6)
			cnt++;
		else
			cnt = 0;
		if (cnt == 3)
			return true;
		n /= 10;
	}
	return false;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int s = 666; true; s++) {
		if (ok(s))
			n--;
		if (!n) {
			printf("%d\n", s);
			break;
		}
	}
}
