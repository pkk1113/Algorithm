// ���ϱ� ����Ŭ

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#endif

#include <stdio.h>

int main() {
	int n;
	int p = -1; // prev
	int t = 0; // temp
	int cnt = 0; // count

	scanf("%d", &n);

	p = n;

	do {
		t = (p / 10) + (p % 10);
		p = (p % 10) * 10 + (t % 10);
		cnt++;
	} while (n != p);

	printf("%d\n", cnt);
}