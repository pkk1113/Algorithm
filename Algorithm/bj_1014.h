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
		auto data = vector<vector<char>>(N, vector<char>(M + 1));
		for (int i = 0; i < N; i++) {
			scanf("%s", data[i].data());
		}

		auto mem = vector<int>(M + 1);

		printf("%d\n", 10);
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