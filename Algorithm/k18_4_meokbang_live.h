#pragma once

// https://www.welcomekakao.com/learn/courses/30/lessons/42891

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 접시 구조체
struct dish {
	int id;
	int time;

	dish() : id(0), time(0) {}
	dish(int id_, int time_) : id(id_), time(time_) {}
};

int solution(vector<int> food_times, long long k) {
	// 모든 접시를 받습니다.
	vector<dish> dishes;
	long long total_food_time = 0;

	dishes.reserve(food_times.size());
	for (size_t i = 0; i < food_times.size(); i++) {
		if (food_times[i] == 0)
			continue;
		dishes.emplace_back(i + 1, food_times[i]);
		total_food_time += food_times[i];
	}

	// 시간이 충분하면 -1
	if (k >= total_food_time)
		return -1;

	// 내림차순으로 정렬합니다.
	sort(dishes.begin(), dishes.end(), [](const dish& lhs, const dish& rhs) {
		return lhs.time > rhs.time;
	});

	// 이제 차이만큼 뒤에서부터 빼갑니다.
	const int n = (int)dishes.size();
	for (int i = n; i >= 1; i--) {
		// 접시의 수 * 이전과의 높이 차(맨 끝이면 바로 사용)
		int gap = (i == n) ? (dishes[i - 1].time) : (dishes[i - 1].time - dishes[i].time);
		long long t = (long long)i * gap;

		if (t <= k) {
			// 시간이 충분하면 빼고 다음 단계로
			k -= t;
		} else {
			// 현재 남은 접시 수로 시간을 나누어 남은 수
			int r = (int)(k % i);

			// 남은 접시에서 r까지만 포함하도록 부분정렬
			partial_sort(dishes.begin(), dishes.begin() + r + 1,
						 dishes.begin() + i, 
						 [](const dish& lhs, const dish& rhs) {
				return lhs.id < rhs.id;
			});

			// 남은 수 위치의 접시가 k초때 먹을 접시입니다.
			return dishes[r].id;
		}
	}

	// 여긴 실행되지 않습니다. 
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