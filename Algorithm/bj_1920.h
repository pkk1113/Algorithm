#pragma once

#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool is_prime(size_t n) {
	static map<int, bool> primes{ {1, false} };

	if (primes.find(n) != primes.cend()) {
		return primes[n];
	}

	for (int i = 2; i <= (int)std::sqrt(n); i++) {
		if (n % i == 0) {
			primes.emplace(n, false);
			return false;
		}
	}

	primes.emplace(n, true);
	return true;
}

unordered_set<int> create_combs(int len, string num) {
	unordered_set<int> res;

	if (len == 1) {
		for (auto c : num) {
			if (c != '0')
				res.emplace(c - '0');
		}
		return res;
	}

	for (size_t i = 0; i < num.size(); i++) {
		string rest;
		for (size_t j = 0; j < num.size(); j++) {
			if (i != j)
				rest.push_back(num[j]);
		}

		for (auto& sub_comb : create_combs(len - 1, rest)) {
			auto full_comb = (int)std::pow(10, len - 1) * (int)(num[i] - '0') + sub_comb;
			res.emplace(full_comb);
		}
	}

	return res;
}

int solution(string numbers) {

	unordered_set<int> results;

	for (size_t len = 1; len <= numbers.size(); len++) {
		auto c = create_combs(len, numbers);
		results.insert(c.begin(), c.end());
	}

	int answer = 0;

	for (auto value : results) {
		printf("%d\n", value);
		if (is_prime(value))
			answer++;
	}

	return answer;
}

int main() {
	printf("%d", solution("101"));
}