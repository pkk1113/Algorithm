#pragma once
/*
	https://www.acmicpc.net/problem/1182
	
	�κм����� ��
	-----------
	 N���� ������ �̷���� ������ ���� ��, ũ�Ⱑ ����� �κм��� �߿���
	�� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	-----------
	 ù° �ٿ� ������ ������ ��Ÿ���� N�� ���� S�� �־�����. (1 �� N �� 20, |S| �� 1,000,000) 
	��° �ٿ� N���� ������ �� ĭ�� ���̿� �ΰ� �־�����. �־����� ������ ������ 100,000�� ���� �ʴ´�.
	-----------
	5 0
	-7 -3 -2 5 8
	-----------
	1
*/
#pragma warning(disable:4996)
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	int n, s;
	if (2 != scanf("%d%d", &n, &s)) return 0;

	vector<int> arr(n);
	for (auto& el : arr) {
		if (1 != scanf("%d", &el)) return 0;
	}

	int cnt = 0;
	for (size_t bit = 1; bit < (1 << n); bit++) {
		int sum = 0;

		for (int i = 0; i < n; i++) {
			if (bit & (1 << i))
				sum += arr[i];
		}

		if (sum == s)
			cnt++;
	}

	printf("%d\n", cnt);
}