// �ƽ�Ű �ڵ�

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#pragma warning(disable:4018) // unsigned�� int�� ��ȯ
#endif

#include <cstdio>

int main() {
	char c;
	scanf("%c", &c);
	printf("%d", c);
}