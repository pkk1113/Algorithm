#pragma once
#pragma warning(disable:4996)
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

// Edit Distance Problem ���� ����(Divide and Conquer)
size_t edp_dc(const char str_a[],
			  const char str_b[],
			  size_t len_a,
			  size_t len_b) {
	// �� ���� 0�̸� ���� �� ���� ���̸� ��ȯ�Ѵ�.
	if (len_a == 0)
		return len_b;
	else if (len_b == 0)
		return len_a;

	// �� ���� ���ٸ� �ɰ��� �ʴ´�.
	if (str_a[len_a - 1] == str_b[len_b - 1])
		return edp_dc(str_a, str_b, len_a - 1, len_b - 1);
	else
		// ���⼭ 1�� (���� �Ǵ� ��ȯ)
		// ����: ��� �� ���� ���̸� 1���� ���
		// ��ȯ: ���� ���̸� 1 ���� ���
		return 1 + std::min(edp_dc(str_a, str_b, len_a - 1, len_b - 1),
							std::min(edp_dc(str_a, str_b, len_a - 1, len_b),
									 edp_dc(str_a, str_b, len_a, len_b - 1)));
}

// Edit Distance Problem ���� ��ȹ��(Dynamic Programming)
size_t edp_dp(const char str_a[],
			  const char str_b[],
			  size_t len_a,
			  size_t len_b) {

	vector<vector<int>> data(len_a + 1, vector<int>(len_b + 1));

	for (size_t i = 0; i <= len_a; i++) {
		for (size_t j = 0; j <= len_b; j++) {
			if (i == 0)
				data[i][j] = j;
			else if (j == 0)
				data[i][j] = i;
			else if (str_a[i - 1] == str_b[j - 1])
				data[i][j] = data[i - 1][j - 1];
			else
				data[i][j] = 1 + std::min(data[i - 1][j - 1],
										  std::min(data[i - 1][j],
												   data[i][j - 1]));
		}
	}

	return data[len_a][len_b];
}

int main() {
	auto a = "abcaba";
	auto b = "adsdvd";
	size_t result = 0;

	result = edp_dc(a, b, strlen(a), strlen(b));
	printf("div-con�� ���: %d\n", result);

	result = edp_dp( a, b, strlen(a), strlen(b));
	printf("dyn-pro�� ���: %d\n", result);
}