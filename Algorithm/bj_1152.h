// 단어의 개수

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#pragma warning(disable:4018) // unsigned를 int로 변환
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