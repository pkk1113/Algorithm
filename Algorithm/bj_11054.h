// ���� �� ������� �κ� ����

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#pragma warning(disable:4018) // unsigned�� int�� ��ȯ
#endif

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// s: source, t: target, n: size, d: direction
void lis(int* s, int* t, int n, int d = 1) {
	t[0] = 1;
	for (int i = 1; i < n; i++) {
		int big = 0;
		int di = d * i;
		for (int j = 0; j < i; j++) {
			int dj = d * j;
			if (s[dj] < s[di] && big < t[dj]) {
				big = t[dj];
			}
		}
		t[di] = big + 1;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	auto arr = vector<int>(n);
	for (auto& el : arr) {
		scanf("%d", &el);
	}

	auto inc = vector<int>(n);
	auto dec = vector<int>(n);

	lis(&arr.front(), &inc.front(), n, 1);
	lis(&arr.back(), &dec.back(), n, -1);
	
	int big = 1;

	for (int i = 0; i < n; i++) {
		big = max(big, inc[i] + dec[i] - 1);
	}

	printf("%d\n", big);
}