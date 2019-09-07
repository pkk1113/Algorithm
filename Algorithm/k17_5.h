#include <string>
#include <map>
#include <algorithm>

using namespace std;

string& to_lower(string& s) {
	for (auto& el : s)
		if (el >= 'A' && el <= 'Z')
			el += ('a' - 'A');
	return s;
}

map<string, int> make_set(string& s) {
	map<string, int> m;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] < 'a' || s[i] > 'z')
			continue;
		if (s[i + 1] < 'a' || s[i + 1] > 'z') {
			i++;
			continue;
		}
		m[s.substr(i, 2)]++;
	}
	return m;
}

int solution(string str1, string str2) {
	auto ms1 = make_set(to_lower(str1));
	auto ms2 = make_set(to_lower(str2));

	if (ms1.empty() && ms2.empty())
		return 65536;

	int inter_cnt = 0;
	int union_cnt = 0;

	auto i1 = ms1.begin();
	auto i2 = ms2.begin();

	while (i1 != ms1.end() || i2 != ms2.end()) {
		if (i1 == ms1.end()) {
			union_cnt += i2->second;
			i2++;
		} else if (i2 == ms2.end()) {
			union_cnt += i1->second;
			i1++;
		} else if (i1->first > i2->first) {
			union_cnt += i2->second;
			i2++;
		} else if (i1->first < i2->first) {
			union_cnt += i1->second;
			i1++;
		} else {
			inter_cnt += min(i1->second, i2->second);
			union_cnt += max(i1->second, i2->second);
			i1++;
			i2++;
		}
	}

	return (int)(65536.0 * ((double)inter_cnt / (double)union_cnt));
}

int main() {
	string str1 = "++AC+++";
	string str2 = "----AB";

	int r = solution(str1, str2);
	printf("%d\n", r);
}