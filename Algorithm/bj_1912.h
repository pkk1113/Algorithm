// ������

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#endif

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	auto arr = vector<int>(N);
	for (auto& el : arr)
		scanf("%d", &el);

	// [���][����] = ���� 
	int big = 0;
	for (int i = 1; i < N; i++) { // ���
		auto mem = vector<int>(N + 1);
		for (int j = i + 1; j <= N; j++) { // ����
			mem[j] = mem[j - 1] + arr[j - 1];
			if (mem[j] > big)
				big = mem[j];
		}
	}

	printf("%d\n", big);
}