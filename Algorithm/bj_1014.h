// ����

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#endif

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int C;
	scanf("%d", &C);

	while (C--) {
		int N, M; // ���� N, ���� M
		scanf("%d %d", &N, &M); // >= 1, <= 10
		auto data = vector<int>(M + 1, 0);
		for (int i = 0; i < N; i++) {
			char tmp[11];
			scanf("%s", tmp);

			for (int j = 1; j <= M; j++) { // 1����
				if (tmp[j - 1] == '.') // 0����
					data[j]++;
			}
		}

		auto mem = vector<int>(M + 1, 0);
		mem[1] = data[1];
		for (int i = 2; i <= M; i++) {
			mem[i] = max(mem[i - 2] + data[i], mem[i - 1]);
		}

		if (M >= 2)
			mem[M] = max(mem[M], mem[M - 1]);

		printf("%d\n", mem[M]);
	}
}

// ������ ������ ������ ���ƹ�����. :(
/*
3 5
.x.x.
xxxxx
x.x.x
5 �� ���;� �ϴµ� 3�� ���´�.
*/