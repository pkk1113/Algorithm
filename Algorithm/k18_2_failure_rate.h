#pragma once

// https://www.welcomekakao.com/learn/courses/30/lessons/42889

#pragma warning(disable:4996)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct stage {
	int id;
	int total;
	double failure_rate;

	stage() : id(0), total(0), failure_rate(0.0) {}
};

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	vector<stage> data(N + 1);
	for (int el : stages)
		data[el - 1].total++;

	int total_user = stages.size();
	for (int i = 0; i < N; i++) {
		data[i].id = i + 1;

		if (total_user > 0) {
			data[i].failure_rate = (double)data[i].total / (double)total_user;
			total_user -= data[i].total;
		}
	}

	std::sort(data.begin(), data.end() - 1, [](const stage& a, const stage& b) {
		if (a.failure_rate == b.failure_rate)
			return a.id < b.id;
		return a.failure_rate > b.failure_rate;
	});

	answer.reserve(N);
	for (int i = 0; i < N; i++)
		answer.push_back(data[i].id);

	return answer;
}

int main() {
	// case 1
	{
		int N = 5;
		vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
		vector<int> result = solution(N, stages);
		for (int el : result)
			printf("%d\n", el);
	}

	// case 2
	{
		int N = 4;
		vector<int> stages = { 4, 4, 4, 4 };
		vector<int> result = solution(N, stages);
		for (int el : result)
			printf("%d\n", el);
	}

	// case new
	{
		int N = 10;
		vector<int> stages = { 1, 1, 1, 1 };
		vector<int> result = solution(N, stages);
		for (int el : result)
			printf("%d\n", el);
	}
}