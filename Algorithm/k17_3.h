#include <string>
#include <vector>
#include <deque>

using namespace std;

string& to_lower(string& s) {
	for (auto& el : s)
		if (el >= 'A' && el <= 'Z')
			el += ('a' - 'A');
	return s;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	deque<string> cache;

	for (auto& city : cities) {
		to_lower(city);

		bool hit = false;
		auto it = cache.begin();

		for (; it != cache.end(); it++) {
			if (*it == city) {
				hit = true;
				break;
			}
		}

		if (hit) {
			auto value = *it;
			cache.erase(it);
			cache.push_front(value);
		} else {
			cache.push_front(city);
			if (cache.size() > cacheSize)
				cache.pop_back();
		}

		answer += (hit ? 1 : 5);
	}

	return answer;
}

int main() {
	int cs = 2;
	auto cities = vector<string>{ "Jeju", "Pangyo", "NewYork", "newyork" };

	solution(cs, cities);
}