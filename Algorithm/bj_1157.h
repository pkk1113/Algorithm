// �ܾ� ����

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#pragma warning(disable:4018) // unsigned�� int�� ��ȯ
#endif

#include <cstdio>

int main() {
	int cnt[26]{ 0, };
	char c;

	while ((c = getchar()) != '\n') {
		if (c >= 'A' && c <= 'Z')
			c = (c - 'A') + 'a';
		cnt[c - 'a']++;
	}

	int bi = 0; // biggest index
	bool hit = false;

	for (int i = 1; i < 26; i++) {
		if (cnt[i] > cnt[bi]) {
			bi = i;
			hit = false;
		} else if (cnt[i] == cnt[bi]) {
			hit = true;
		}
	}

	printf("%c", hit ? '?' : bi + 'A');
}