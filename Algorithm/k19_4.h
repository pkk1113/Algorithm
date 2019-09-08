#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool check_query(string& word, string& query) {
	if (word.size() != query.size())
		return false;

	// 앞에서
	if (query[0] != '?') {
		for (int i = 0; i < word.size(); i++) {
			if (query[i] == '?')
				break;
			else if (word[i] != query[i])
				return false;
		}
	}
	// 뒤에서
	else {
		for (int i = word.size() - 1; i >= 0; i--) {
			if (query[i] == '?')
				break;
			else if (word[i] != query[i])
				return false;
		}
	}

	return true;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	unordered_map<string, int> q_cnt; // query count
	unordered_map<string, bool> dup; // duplicated
	unordered_map<int, int> word_len_cnt; // word length count

	for (auto& word : words) {
		word_len_cnt[word.size()]++;
	}

	for (auto& query : queries) {
		if (dup[query])
			continue;
		dup[query] = true;

		// 모두 와일드라면
		if (all_of(query.begin(), query.end(), [](const char& c) {
			return c == '?';
		})) {
			q_cnt[query] = word_len_cnt[query.size()];
			continue;
		}

		for (auto& word : words) {
			// 모두 ? 라면 같은 글자 길이를 준다.
			if (check_query(word, query)) {
				q_cnt[query]++;
			}
		}
	}

	vector<int> answer;

	answer.reserve(queries.size());

	for (auto& query : queries) {
		answer.push_back(q_cnt[query]);
	}

	return answer;
}

int main() {
	auto words = vector<string>{ "frodo", "front", "frost", "frozen", "frame", "kakao" };
	auto queries = vector<string>{ "fro??", "????o", "fr???", "fro???", "pro?" };

	solution(words, queries);
}