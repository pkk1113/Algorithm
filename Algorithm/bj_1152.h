// �ܾ��� ����

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#pragma warning(disable:4018) // unsigned�� int�� ��ȯ
#endif

#include <cstdio>

int main() {
	char word[1000000];
	char* c = word;
	bool hit = false;
	int cnt = 0;

	scanf("%[^\n]s", word);

	while (*c != '\0') {
		if (*c != ' ') {
			if (!hit) {
				cnt++;
				hit = true;
			}
		} else {
			hit = false;
		}
		c++;
	}

	printf("%d", cnt);
}