// ���̾�

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#pragma warning(disable:4018) // unsigned�� int�� ��ȯ
#endif

#include <cstdio>

int to_num(char c) {
	if (c < 'S')
		return (c - 'A') / 3 + 2;
	else if (c == 'S')
		return 7;
	else if (c < 'W')
		return 8;
	else
		return 9;
}

int main() {
	char c;
	int t = 0;

	while ((c = getchar()) != '\n') {
		t += to_num(c) + 1;
	}

	printf("%d\n", t);
}