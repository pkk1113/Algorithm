// ���ڿ� �ݺ�

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#pragma warning(disable:4018) // unsigned�� int�� ��ȯ
#endif

#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		char s[20];
		scanf("%s", s);

		char ans[160];
		int k = 0;
		for (int i = 0; i < strlen(s); i++) {
			for (int j = 0; j < n; j++) {
				ans[k++] = s[i];
			}
		}
		ans[k] = '\0';
		puts(ans);
	}
}