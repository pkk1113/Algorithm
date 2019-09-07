#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	
	vector<string> answer;

	for (int i = 0; i < n; i++) {
		answer.push_back(string());

		auto tmp = arr1[i] | arr2[i];

		for (int j = n - 1; j >= 0; j--) {
			if (1 & (tmp >> j))
				answer[i].push_back('#');
			else
				answer[i].push_back(' ');
		}
	}

	return answer;
}

int main() {
	auto arr1 = vector<int>{ 9, 20, 28, 18, 11 };
	auto arr2 = vector<int>{ 30, 1, 27, 17, 28 };

	auto r = solution(5, arr1, arr2);
	for (auto& el : r) {
		puts(el.c_str());
	}
}