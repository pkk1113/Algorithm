#pragma once
/*
	https://www.acmicpc.net/problem/1182
	
	부분수열의 합
	-----------
	 N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서
	그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.
	-----------
	 첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 
	둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.
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