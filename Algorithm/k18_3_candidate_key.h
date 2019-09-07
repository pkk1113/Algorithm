#pragma once

// https://www.welcomekakao.com/learn/courses/30/lessons/42890

#pragma warning(disable:4996)
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<vector<string>> relation) {
	int answer = 0;

	size_t row_num = relation.size();
	size_t col_num = relation[0].size();

	vector<size_t> keys;
	keys.reserve(1u << col_num);

	for (size_t bit = 1; bit < (1u << col_num); bit++) {
		// 이미 후보키를 포함하면 무시합니다.
		bool is_uniqu = true;
		for (auto& key : keys) {
			if ((bit & key) == key) {
				is_uniqu = false;
				break;
			}
		}
		if (!is_uniqu)
			continue;

		// 모든 비트를 돌면서 word를 완성한다.
		vector<string> words(row_num);
		for (size_t i = 0; i < col_num; i++) {
			if (bit & (1 << i)) {
				for (size_t j = 0; j < row_num; j++) {
					words[j] += relation[j][i];
				}
			}
		}

		// word가 모두 uniqu 하면 후보키로 등록한다.
		unordered_set<string> set;
		is_uniqu = true;
		for (auto& el : words) {
			if (set.find(el) != set.cend()) {
				is_uniqu = false;
				break;
			}
			set.insert(el);
		}
		if (is_uniqu)
			keys.push_back(bit);
	}

	answer = (int)keys.size();

	return answer;
}

int main() {
	// case 1
	{
		vector<vector<string>> relation = {
			{"100", "ryan", "music", "2"},
			{"200", "apeach", "math", "2"},
			{"300", "tube", "computer", "3"},
			{"400", "con", "computer", "4"},
			{"500", "muzi", "music", "3"},
			{"600", "apeach", "music", "2"}
		};

		int result = solution(relation);
		printf("%d\n", result); // 2
	}
}