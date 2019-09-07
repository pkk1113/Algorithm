#pragma once

// https://www.welcomekakao.com/learn/courses/30/lessons/42891

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ���� ����ü
struct dish {
	int id;
	int time;

	dish() : id(0), time(0) {}
	dish(int id_, int time_) : id(id_), time(time_) {}
};

int solution(vector<int> food_times, long long k) {
	// ��� ���ø� �޽��ϴ�.
	vector<dish> dishes;
	long long total_food_time = 0;

	dishes.reserve(food_times.size());
	for (size_t i = 0; i < food_times.size(); i++) {
		if (food_times[i] == 0)
			continue;
		dishes.emplace_back(i + 1, food_times[i]);
		total_food_time += food_times[i];
	}

	// �ð��� ����ϸ� -1
	if (k >= total_food_time)
		return -1;

	// ������������ �����մϴ�.
	sort(dishes.begin(), dishes.end(), [](const dish& lhs, const dish& rhs) {
		return lhs.time > rhs.time;
	});

	// ���� ���̸�ŭ �ڿ������� �����ϴ�.
	const int n = (int)dishes.size();
	for (int i = n; i >= 1; i--) {
		// ������ �� * �������� ���� ��(�� ���̸� �ٷ� ���)
		int gap = (i == n) ? (dishes[i - 1].time) : (dishes[i - 1].time - dishes[i].time);
		long long t = (long long)i * gap;

		if (t <= k) {
			// �ð��� ����ϸ� ���� ���� �ܰ��
			k -= t;
		} else {
			// ���� ���� ���� ���� �ð��� ������ ���� ��
			int r = (int)(k % i);

			// ���� ���ÿ��� r������ �����ϵ��� �κ�����
			partial_sort(dishes.begin(), dishes.begin() + r + 1,
						 dishes.begin() + i, 
						 [](const dish& lhs, const dish& rhs) {
				return lhs.id < rhs.id;
			});

			// ���� �� ��ġ�� ���ð� k�ʶ� ���� �����Դϴ�.
			return dishes[r].id;
		}
	}

	// ���� ������� �ʽ��ϴ�. 
	return -1;
}

#pragma warning(disable:4996)
#include <cstdio>
#include <random>

int main() {
	// case 1
	{
		vector<int> food_times = { 3, 1, 2 };
		long long k = 5;

		int result = solution(food_times, k);
		printf("%d\n\n", result);
	}

	// case 2
	{
		vector<int> food_times = { 3, 8, 2, 8, 8, 7, 3, 8, 2 };
		long long k = 0;

		int result = solution(food_times, k);
		printf("%d\n\n", result);
	}

	// case 3
	{
		vector<int> food_times((int)(2e+5), (int)(1e+8));
		long long k = (long long)2e+13 - 1;

		int result = solution(food_times, k);
		printf("%d\n\n", result);
	}
}