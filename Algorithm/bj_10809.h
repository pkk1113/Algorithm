// ���ĺ� ã��

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#pragma warning(disable:4018) // unsigned�� int�� ��ȯ
#endif

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	auto alpha = vector<int>('z' - 'a' + 1, -1);
	char c;
	int i = 0;

	while ((c = getchar()) != '\n') {
		if (alpha[c - 'a'] == -1)
			alpha[c - 'a'] = i;
		i++;
	}

	for (auto& index : alpha) {
		printf("%d ", index);
	}
}
